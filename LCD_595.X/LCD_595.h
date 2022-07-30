/* 
 * File:   LCD_595.h
 * Author: carlo
 *
 * Created on July 28, 2022, 1:13 PM
 */

#include "mcc_generated_files/mcc.h"

#ifndef LCD_595_H
#define	LCD_595_H

#define CLK_595 LATBbits.LATB3
#define DATA_595  LATBbits.LATB4
#define LATCH_595 LATBbits.LATB5

#define     LCD_CLEAR	    0x01    //Limpia pantalla
#define     LCD_HOME	    0x02    //Retorno al inicio
#define     LCD_CURSOR_ON	0x0F    //Cursor on
#define     LCD_CURSOR_OFF	0x0C    //Cursor off
#define     LCD_LINEA1	    0x00	//Promera Fila
#define     LCD_LINEA2		0XC0	//Segunda Fila
#define     LCD_LINEA3		0x94	//Tercera Fila
#define     LCD_LINEA4		0xD4	//Cuarta Fila
#define     LCD_LEFT		0x10	//Cursor a la izquierda
#define     LCD_RIGHT		0x14	//Cursor a la derecha
#define     LCD_ROT_LEFT	0x18	//Rotar a la izquierda
#define     LCD_ROT_RIGHT	0x1C	//Rotar a la derecha
#define     LCD_OFF 		0x08	//apaga el display


void SHIFT595_write(uint8_t dato);
void LCD_595_cmd(char cmd);
void LCD_595_char(char data);
void LCD_595_init(void);
void LCD_595_write_text(char *str);


#endif	/* LCD_595_H */

