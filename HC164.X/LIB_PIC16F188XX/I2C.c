/***************************************
*  Configuracion pines I2C1  
*  Solo PUERTOS B y C   
****************************************/

#include "I2C.h"

typedef enum { I2C1_GOOD, I2C1_FAIL_TIMEOUT } i2c1_error;
static i2c1_error lastError = I2C1_GOOD;

/**********************************************
 * Inicializa I2C1, 
 *********************************************/

void I2C_init(void)
{
    SSP1DATPPS = SDA1_IN;           // PIN SDA1 IN 
    SSP1CLKPPS = SCL1_IN;           // PIN SCL1 IN 
    SDA1_OUT = PPSOUT_SDA1;         // PIN SDA1 OUT           
    SCL1_OUT = PPSOUT_SCL1;         // PIN SCL1 OUT
  
	SSP1STATbits.SMP = 1;           // Velocidad: 1=standart, 0=alta
    SSP1STATbits.CKE = 0;           // SMBus: 1=on, 0=off
    SSP1CON1bits.SSPM = 0b1000;     // I2C maestro velocidad=Fosc/(4*SSPADD+1)
    SSP1CON1bits.SSPEN = 1;         // Habilitacion I2C: 1=ON, 0=OFF 
    
	SSP1ADD = SSP1ADD_VAL;          // BaudRate para I2C
}

/**********************************************
 * Para enviar dato por I2C, no bloqueante
 *********************************************/

static inline void I2C_master_wait(void)
{    
    uint8_t waitCount = 255;
    if(lastError == I2C1_GOOD)
    {
        while(--waitCount)
        {
            if(PIR3bits.SSP1IF)           
                return;    
            else
                __delay_us(1);              
        }
        lastError = I2C1_FAIL_TIMEOUT;
    }
}

/**********************************************
 * Envia start, se restaura por hardware
 *********************************************/

void I2C_start(void)
{
    SSP1CON2bits.SEN = 1;           // Start I2C   
    while(SSP1CON2bits.SEN == 1);   // Espera termine start
}

/**********************************************
 * Envia restart, se restaura por hardware
 *********************************************/

void I2C_restart(void)
{
    SSP1CON2bits.RSEN = 1;          //reinicia la comunicaci�n i2c
     while(SSP1CON2bits.RSEN == 1);
}

/**********************************************
 * Envia stop, se restaura por hardware
 *********************************************/

void I2C_stop(void)
{    
    SSP1CON2bits.PEN = 1;           //detener la comunicaci�n i2c	
    while(SSP1CON2bits.PEN == 1);
}

/**********************************************
 * Envia dato I2C, retorna si hubo ack
 *********************************************/

uint8_t I2C_write(uint8_t I2C_data)
{   
    PIR3bits.SSP1IF=0;              // Limpia bandera
    SSP1BUF = I2C_data;             //send databyte
    I2C_master_wait();
    if(SSP1CON2bits.ACKSTAT==0)
       return 1;       //No hubo ack
    else
        return 0;       //Si Hubo ack
}

/**********************************************
 * Envia dato I2C, retorna si hubo ack
 *********************************************/

uint8_t I2C_read(void)
{
    PIR3bits.SSP1IF=0;
    SSP1CON2bits.RCEN = 1;       	//set the receive enable bit to initiate a read of 8 bits from the serial eeprom
    I2C_master_wait(); 
    return SSP1BUF;           //Data from eeprom is now in the SSPBUF so return that value             
}

/*************** Env�o de ACK **************/
void I2C_ack(void)
{
    SSP1CON2bits.ACKDT = 0;             // 0 = ACK
    SSP1CON2bits.ACKEN = 1;             // Envia ACK
    while(SSP1CON2bits.ACKEN == 1);     // Espera que termine envio
}

/*************** Env�o de NACK **************/
void I2C_nack(void)
{
    SSP1CON2bits.ACKDT = 1;             // 1 = NOAC
    SSP1CON2bits.ACKEN = 1;             // Envia ACK
    while(PIR3bits.SSP1IF == 0);        // Espera que termine envio
}

/************* Envio de un dato ****************/
void I2C_write_1register(uint8_t address, uint8_t data)
{
    I2C_start();                // Inicia la comunicacion I2C
    I2C_write(address);         // Env�a el dato
    I2C_write(data);            // Env�o de dato I2C
    I2C_stop();                 // Fin de transmisi�n
}