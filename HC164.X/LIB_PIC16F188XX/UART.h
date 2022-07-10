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

#ifndef UART_H
#define UART_H

#include "DEVICE_CONFIG.h"

/*******************************************************************************
 * Definicion de pines para TX y RX
 ******************************************************************************/

#define TX_PIN          RB6PPS          // Pin PPS para TX
#define RX_PIN          PPSIN_RB7       // Pin PPS para RX
#define UART_BAUD_RATE  9600UL          // BaudRate

/*-------------- Formula para alta velocidad a 16 bits -----------------------*/
#define SPBRG_VAL   ((_XTAL_FREQ /(UART_BAUD_RATE * 4)) -1) 

#define SPBRG_H         SPBRG_VAL >> 8          //Parte alta Baudrate    
#define SPBRG_L         0x00FF & SPBRG_VAL      //Parte baja Baudrate

/*******************************************************************************
* Declaracion variables y arreglos para RX
*******************************************************************************/

#define UART_RX_BUFFER_SIZE 8

volatile uint8_t uartRxBuffer[UART_RX_BUFFER_SIZE];
volatile uint8_t uartRxCount;

/*******************************************************************************
* Declaracion de funcion para TX y RX
*******************************************************************************/

void UART_init(void);
void UART_write(uint8_t txData);
void UART_write_text(char *uartText);
uint8_t UART_read(void);
void UART_read_text(char *uartText, uint8_t length);
void UART_receive_ISR(void);

#endif	/* UART_H */
