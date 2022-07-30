

#include "LCD_595.h"

void SHIFT595_write(uint8_t dato)
{   
    for(uint8_t i=7; i<255; i--)
    {
        CLK_595 = 0;
        LATCH_595 = 0;
        NOP();

        if((dato&(1<<i))==0)   
            DATA_595 = 0; 
        else
            DATA_595 = 1;
        
        NOP();
        CLK_595 = 1;    
        NOP();
    }
    CLK_595 = 0;
    LATCH_595 = 1;
    NOP();
}

/* Envia comando por LCD ------------------------------------------*/

void LCD_595_cmd(char cmd)
{
  	char data_u, data_l;
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
    
    SHIFT595_write(data_u|0b0010);  //en=1, rs=0  1100
	SHIFT595_write(data_u|0b0000);  //en=0, rs=0  1000
	SHIFT595_write(data_l|0b0010);  //en=1, rs=0
	SHIFT595_write(data_l|0b0000);  //en=0, rs=0
    __delay_ms(2);
    
}

/* Envia dato por LCD ------------------------------------------*/

void LCD_595_char(char data)
{
	char data_u, data_l;
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
  
    SHIFT595_write(data_u|0b0011);  //en=1, rs=1  1101
	SHIFT595_write(data_u|0b0001);  //en=0, rs=1  1001
	SHIFT595_write(data_l|0b0011);  //en=1, rs=1  1101
	SHIFT595_write(data_l|0b0001);  //en=0, rs=1  1001
    __delay_ms(2);
}

/* Inicializa LCD -----------------------------------------------*/

void LCD_595_init(void)
{
	LCD_595_cmd(0x02);
	LCD_595_cmd(0x28);
	LCD_595_cmd(0x0c);
	LCD_595_cmd(0x80);
	LCD_595_cmd(LCD_CLEAR);
}

/* Envia cadena de caracteres al LCD -----------------------------*/

void LCD_595_write_text(char *str)
{
	while (*str) LCD_595_char(*str++);
}

