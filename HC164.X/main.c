/****************************************************
 * File:   main.c
 * Author: CarlosQL
 * Date:   01/01/2022
 ***************************************************/

#include "LIB_PIC16F188XX/DEVICE_CONFIG.h"

#define CLK_164 LATBbits.LATB3
#define DATA_164  LATBbits.LATB4

/*******************************************************************************
 Envía el número por HC164 a 6 digitos
 ******************************************************************************/

void SHIFT164_write_byte(uint16_t dato, uint8_t bits)
{   
    //__delay_ms(1);
    for(uint8_t i=0; i<bits; i++)
    {
        CLK_164 = 0;
        NOP();
        if((dato&(1<<i))==0)   
            DATA_164 = 0; 
        else
            DATA_164 = 1;
        NOP();
        CLK_164 = 1;    
        NOP();
        //__delay_ms(200);
    }
   // CLK_164 = 0;
    //__delay_ms(200);
}




/***************************************************
 * Función principal PIC16F
 **************************************************/

void main(void) {
    
    SYSTEM_init();          //Inicialización de perifericos
    
     //SHIFT164_write_byte(0b1100111000, 10);
     SHIFT164_write_byte(0b0011001110, 10); 
    // descomponerNumero(0b1100111011);
    //    mostrarDato();     
        __delay_ms(1000);
    while(1)
    {
       
    }
    return;
}
