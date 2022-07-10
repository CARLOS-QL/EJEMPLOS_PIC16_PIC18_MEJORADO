/*******************************************************************************
 * Libreria: KEYPAD  
 * Autor:    Carlos QL
 * Fecha:    01/02/2022
 * Autor:    Carlos QL
 * Version   2.1	
 * Descripcion:
 *      Compatible con teclado de 4x4
 *      Necesita PULL-UP en las COLUMNAS
 *      Todos los pines son reemapeables
 *      Solo utiliza un arreglo para las teclas
 ******************************************************************************/ 

#ifndef KEYPAD_H
#define	KEYPAD_H

#include "DEVICE_CONFIG.h"

/*********** Etiquetas para las FILAS como salidad con LAT ********************/

#define ROW1        LATBbits.LATB3
#define ROW2        LATBbits.LATB2
#define ROW3        LATBbits.LATB1
#define ROW4        LATBbits.LATB0

/********* Etiquetas para las COLUMNAS como entrada con PORT ******************/

#define COL1        PORTCbits.RC3
#define COL2        PORTCbits.RC2
#define COL3        PORTCbits.RC1
#define COL4        PORTCbits.RC0

/****************** Tabla de valores para teclado *****************************/

const uint8_t key_table[16] ={
		'1', '2', '3', 'A',
		'4', '5', '6', 'B',
		'7', '8', '9', 'C',
		'*', '0', '#', 'D'};

/*********************** Prototipos de funciones ******************************/

void ROW_scan(uint8_t row);
uint8_t COL_scan(uint8_t row);
uint8_t KEYPAD_read(void);


#endif	/* KEYPAD_H */

