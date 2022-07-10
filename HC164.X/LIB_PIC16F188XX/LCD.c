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

#include "LCD.h"

/*******************************************************************************
 * Inicializacion de LCD
 ******************************************************************************/

void LCD_init(void)
{
    EN = 0;             //Limpiamos pines de Control
    RS = 0;     
    D4 = 0;                     // Limpiamos pines de Datos
    D5 = 0;
    D6 = 0;
    D7 = 0;

    __delay_ms(20);             // Espera que se estabilicen puertos
    LCD_write_nible(0x03);      //por fabricante
    __delay_ms(5);
    LCD_write_nible(0x03);      //por fabricante
    __delay_us(100);
    LCD_write_nible(0x03);      //por fabricante
    __delay_us(100);
    LCD_write_nible(0x02);      //Initial function set to change interface,   
    __delay_us(100);            //Configurar modo 4 bits

    LCD_cmd(0x28);				//LCD con fuente de 5*7
    LCD_cmd(LCD_CURSOR_OFF);    //Cursor apagado
    LCD_cmd(LCD_CLEAR);
    LCD_cmd(0x06);              //Modo incremental, sin desplazamiento
    LCD_cmd(0x80);              //Address DDRam superior izquierda
}

/*******************************************************************************
 * Envia Nible al puerto de datos
 ******************************************************************************/

void LCD_write_nible(char lcdNible)
{  
    if (lcdNible & (1<<0)) D4 = 1; else D4 = 0;             
    if (lcdNible & (1<<1)) D5 = 1; else D5 = 0;
    if (lcdNible & (1<<2)) D6 = 1; else D6 = 0;
    if (lcdNible & (1<<3)) D7 = 1; else D7 = 0;
    EN = 1;     
    NOP(); NOP();	    //Enable pulse width PWeh min 230ns
    EN = 0; 
}

/*******************************************************************************
 * Envia comando al LCD 
 ******************************************************************************/

void LCD_cmd(char lcdCmd)
{   
    RS = 0; 
    LCD_write_nible(lcdCmd >> 4);
    LCD_write_nible(lcdCmd & 0x0F);
    if(lcdCmd == LCD_CLEAR || lcdCmd == LCD_HOME)
        __delay_ms(2);              //Tiempo m�nimo 1.6ms    
    else
        __delay_us(55);             //Tiempo 55us en real	
}

/*******************************************************************************
 * Envia caracter al LCD
 ******************************************************************************/

void LCD_char(char lcdData)
{   
    RS = 1; 
    LCD_write_nible(lcdData >> 4);
    LCD_write_nible(lcdData & 0x0F);
	__delay_us(55);                 //Tiempo 55us en real	
}

/*******************************************************************************
 * Env�a cadena de caracteres al LCD
 ******************************************************************************/

void LCD_write_text(char *lcdText)
{
    while (*lcdText) LCD_char(*lcdText++);
}

/*******************************************************************************
 * Cursor a una posicion x y 
 ******************************************************************************/

void LCD_gotoxy(char x, char y)
{
    char address;
    switch(y) 
    { 
        case 1: address = 0x00; break; 
        case 2: address = 0x40; break; 
        case 3: address = 0x14; break; 
        case 4: address = 0x54; break; 
        default: address = 0x00; break; 
    } 
    address += x-1;
    LCD_cmd(0x80 | address);   
}

/*******************************************************************************
 * Para personalizar caracter
 ******************************************************************************/

void LCD_custom_char(char gcramAddress, char *lcdText)
{
    if(gcramAddress<8)
    {
        LCD_cmd(0x40+(gcramAddress*8));     /* Command 0x40 and onwards forces the device to point CGRAM address */
        for(uint8_t i=0;i<8;i++)            /* Write 8 byte for generation of 1 character */
            LCD_char(*lcdText++);
    }   
}

