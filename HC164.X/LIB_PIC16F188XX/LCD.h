/*******************************************************************************
 * Libreria: LCD  
 * Autor:    Carlos QL
 * Fecha:    01/02/2022
 * Autor:    Carlos QL
 * Version   2.1	
 * Descripcion:
 *      Compatible con pantallas de 2x16 o 4x20
 *      Libreria con todos los pines remapeables
 *      4 bits de datos y 2 bits de control
 ******************************************************************************/

#ifndef LCD_H
#define LCD_H

#include "DEVICE_CONFIG.h"

/*******************************************************************************
 * Declaracion de pines de datos y control
 * Los pines a usar deben estar configurado como salida
 * Deshabilitar las entradas analogicas
 ******************************************************************************/

#define RS      LATAbits.LATA2      //Pin 4 LCD
#define EN      LATAbits.LATA3      //Pin 6 LCD

#define D4      LATCbits.LATC0      //Pin 11 lcd         
#define D5      LATCbits.LATC1      //Pin 12 lcd            
#define D6      LATCbits.LATC2      //Pin 13 lcd               
#define D7      LATCbits.LATC3      //Pin 14 lcd


/******************* Definiciones de Comandos de LCD **************************/

#define     LCD_CLEAR	    0x01    //Limpia pantalla
#define     LCD_HOME	    0x02    //Retorno al inicio
#define     LCD_CURSOR_ON	0x0F    //Cursor on
#define     LCD_CURSOR_OFF	0x0C    //Cursor off
#define     LCD_ROW1	    0x00	//Promera Fila
#define     LCD_ROW2		0XC0	//Segunda Fila
#define     LCD_ROW3		0x94	//Tercera Fila
#define     LCD_ROW4		0xD4	//Cuarta Fila
#define     LCD_LEFT		0x10	//Cursor a la izquierda
#define     LCD_RIGHT		0x14	//Cursor a la derecha
#define     LCD_ROT_LEFT	0x18	//Rotar a la izquierda
#define     LCD_ROT_RIGHT	0x1C	//Rotar a la derecha	
#define     LCD_OFF 		0x08	//apaga el display

/******************* Declaracion de funcione **********************************/

void LCD_init(void);                        //Inicializa LCD
void LCD_write_nible(char lcdNible);                 //Envia nible a LCD   
void LCD_cmd(char lcdCmd);                 //Envia comando a LCD
void LCD_char(char lcdData);               //Envia caracteer a LCD
void LCD_write_text(char *lcdText);
void LCD_gotoxy(char x, char y);            //Posiciona cursor
void LCD_custom_char(char gcramAddress, char *lcdText);

#endif	/* LCD_H */