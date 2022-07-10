/*******************************************************************************
 * Librer�a: UART1  
 * Autor:    Carlos QL
 * Fecha:    01/02/2022
 * Autor:    Carlos QL
 * Version   2.1	
 * Descripcion:
 *      Compatible con familia PIC16F188XX
 *      Solo Puerto B y C para 28 Y 40 pines
 *      Por defecto RX-RC7 y TX-RC6
 *      Para Placa RX-RB7 y TX-RB6
 ******************************************************************************/

#include "UART.h"

/*******************************************************************************
 * Funcion para inicializar UART
 ******************************************************************************/

void UART_init(void)
{
    PIE3bits.RCIE = 0;          // INT RX OFF

    RXPPS = RX_PIN;             // Pin RX
    TX_PIN = PPSOUT_TX;         // Pin TX 

    BAUD1CONbits.SCKP = 0;      // Estado idle TX: 1=LOW, 0=HIGH
    BAUD1CONbits.BRG16 = 1;     // Generador Baud: 1=16 bits, 0=8 bits
    BAUD1CONbits.WUE = 0;       // 0 = Pin RX no monitoriado 
    BAUD1CONbits.ABDEN = 0;     // Auto bauding: 1=ON, 0=OFF

    RC1STAbits.SPEN = 1;        // Hanilitaci�n UART: 1=On, 0=Off
    RC1STAbits.RX9 = 0;         // RX a 9 bits: 1=9 bits, 0=8 bits
    RC1STAbits.CREN = 1;        // Recepci�n continua: 1= ON, 0=OFF
    RC1STAbits.ADDEN = 0;       // Solo para 9 RX a 9 bits
    
    TX1STAbits.TX9 = 0;         // TX a 9 bits: 1=9 bits, 0=8 bits
    TX1STAbits.TXEN = 1;        // Habilitacion de TX: 1=ON, 0=OFF
    TX1STAbits.SYNC = 0;        // UART: 1= sincrono, 0=asincrono
    TX1STAbits.SENDB = 0;       // Envio break off: 1=ON 0=OFF
    TX1STAbits.BRGH = 1;        // Velocidad: 1=Alta, 0=Baja

    SPBRGH = SPBRG_H;
    SPBRG = SPBRG_L;	
    
    PIE3bits.RCIE = 1;          // Habilia interrupcion por RX
}

/*******************************************************************************
 * Para enviar un dato por TX
 ******************************************************************************/

void UART_write(uint8_t txData)
{
    while(PIR3bits.TXIF==0);
    TX1REG = txData;            // Write the data byte to the USART.
}

/*******************************************************************************
 * Para enviar una cadena de caracteres por TX
 ******************************************************************************/

void UART_write_text(char *uartText)
{
    while (*uartText) UART_write(*uartText++);
}

/*******************************************************************************
 * Para leer un dato por RX
 ******************************************************************************/

uint8_t UART_read(void)
{
    while(!PIR3bits.RCIF);
    if(RC1STAbits.OERR==1)     	// EUSART error - restart
    {
        RC1STAbits.CREN = 0; 
        RC1STAbits.CREN = 1; 
    }
    return RC1REG;
}

/*******************************************************************************
 * Para recibir una cadena de caracteres por RX
 ******************************************************************************/

void UART_read_text(char *uartText, uint8_t length)
{
    uint8_t llave = 0;
    unsigned long int count=0;       // contador
    for(uint8_t i=0; i<length; i++)    
    {   
        while(!PIR3bits.RCIF)
        {
            count++;
            if(count>=200000)
            {
                llave=1;
                break;
            }
        }
        if(RC1STAbits.OERR==1)     	// EUSART error - restart
        {
            RC1STAbits.CREN = 0; 
            RC1STAbits.CREN = 1; 
        }
        if(llave) break;
        *uartText++ = RC1REG;       // cargar Buffer RX     
    }    
    *uartText='\0';
}

/*******************************************************************************
 * Para utilizar printf, dependencia stdio.h
 ******************************************************************************/

char getch(void)
{
    return UART_read();
}

void putch(char txData)
{
    UART_write(txData);
}

/*******************************************************************************
 * ISR para recepcion de UART por interrupcion
 ******************************************************************************/

void UART_receive_ISR(void)
{
    if(RC1STAbits.OERR == 1)
    {
        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }
   
	uint8_t rxData = RC1REG;	
	uartRxBuffer[uartRxCount++] = RC1REG;
    if(uartRxCount >= UART_RX_BUFFER_SIZE) uartRxCount = 0;   
}
