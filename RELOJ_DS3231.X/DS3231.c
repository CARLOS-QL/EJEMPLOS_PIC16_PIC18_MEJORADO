
#include "DS3231.h"

void convertirHora(void){
    
    for(uint8_t i=0; i<7; i++){
        Hora[i] &= 0x0F;
    }
    
    hora = ((Hora[0]<<4)+ Hora[1]);
    min = ((Hora[2]<<4)+ Hora[3]);
    sec = ((Hora[4]<<4)+ Hora[5]);
}

void convertirFecha(void){
    
    for(uint8_t i=0; i<7; i++){
        Fecha[i] &= 0x0F;
    }
    
    dia = ((Fecha[0]<<4)+ Fecha[1]);
    mes = ((Fecha[2]<<4)+ Fecha[3]);
    anio = ((Fecha[4]<<4)+ Fecha[5]);
}

void enviar_hora(void)
{  
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x00);        //Posición de los segundos
    I2C_write(sec);         //Posición donde va leer
    I2C_write(min);         //Posición donde va leer
    I2C_write(hora);        //Posición donde va leer
    I2C_stop();             //Detiene la comunicaión I2C
}

void leer_hora(void)
{  
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x00);        //Posición donde va leer
    I2C_restart();          //Reinicia la comuniación I2C
    I2C_write(0xD1);        //Leer posición
    sec = I2C_read();      //lee posicion de reloj
    I2C_ack();
    min = I2C_read();      //lee posicion de reloj
    I2C_ack();
    hora = I2C_read();      //lee posicion de reloj
    I2C_nack();
    I2C_stop();             //Termina comunicaion I2C
}

void enviar_fecha(void)
{    
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x04);        //Posición de los segundos
    I2C_write(dia);         //Posición donde va leer
    I2C_write(mes);         //Posición donde va leer
    I2C_write(anio);        //Posición donde va leer
    I2C_stop();             //Detiene la comunicaión I2C
}

void leer_fecha(void)
{  
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x04);        //Posición donde va leer
    I2C_restart();          //Reinicia la comuniación I2C
    I2C_write(0xD1);        //Leer posición
    dia = I2C_read();      //lee posicion de reloj
    I2C_ack();
    mes = I2C_read();      //lee posicion de reloj
    I2C_ack();
    anio = I2C_read();      //lee posicion de reloj
    I2C_nack();
    I2C_stop();             //Termina comunicaion I2C
}


void mostrar_hora(void)
{ 
    LCD_dato((hora>>4)+0x30);
    LCD_dato((hora & 0x0F)+0x30);
    LCD_dato(':');
    LCD_dato((min>>4)+0x30);
    LCD_dato((min & 0x0F)+0x30);
    LCD_dato(':');
    LCD_dato((sec>>4)+0x30);
    LCD_dato((sec & 0x0F)+0x30);
}

void mostrar_fecha(void)
{
    LCD_dato((dia>>4)+0x30);
    LCD_dato((dia & 0x0F)+0x30);
    LCD_dato('/');
    LCD_dato((mes>>4)+0x30);
    LCD_dato((mes & 0x0F)+0x30);
    LCD_dato('/');   
    LCD_dato((anio>>4)+0x30);
    LCD_dato((anio & 0x0F)+0x30);
}

