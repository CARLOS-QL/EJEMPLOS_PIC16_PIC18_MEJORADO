/*******************************************************************************
 * Librería: TO_STRING  
 * Autor:    Carlos QL
 * Fecha:    01/02/2022
 * Autor:    Carlos QL
 * Version   2.1	
 * Descripcion:
 *      Convierte numeros enteros a cadena
 *      Convierte numeros flotantes a cadena
 ******************************************************************************/

#include "TO_STRING.h"

/*******************************************************************************
 * Convierte numeros enteros a cadena de caracteres
 * Solo hasta 32767 a -32768 ó 0 a 65535
 * Solo números positivos hasta 32 bits
 ******************************************************************************/

void INT_to_string(signed long number, char *text)
{
    char* temp = text;
    signed long signo = number;
    if ((signo=number) < 0) 
        number = -number;
    do{
        *temp++ = (number % 10) + '0';
    }while(number/=10);
    
    if(signo<0) *temp++='-';
    *temp-- ='\0';
    char aux;  
    while(temp>text)   
        aux=*temp, *temp--=*text, *text++=aux; 
}

/*******************************************************************************
 * Convierte de flotantes a cadena de caracteres
 ******************************************************************************/

void FLOAT_to_string(double number, char *text, char decimal)
{ 
    int largo_entera, largo_n, cont_for, tempo_int;
    double tempo_float;

    largo_n = decimal + 1;
    largo_entera = 0;
    
    if (number < 0)         //Es negativo ?
    {
        *text++ = '-';
        number = -number;
    }
    //si es menor que no multiplica por 10
    if (number > 0.0) while (number < 1.0)
    {
        number =number* 10.00;
        largo_entera--;
    }

    //realiza division varias veces hasta que sea menor que 10
    while (number >= 10.0)
    {
        number = number/10.0;
        largo_entera++;   //sube el largo de la trama por ser deciaml
    }
    largo_n = largo_n+largo_entera;   //el largo es la decimal mas la parte entera

    // round. num is between 1 and 10 and largo_n will be printed to
    // right of decimal point so rounding is ...
    
    for (tempo_float = cont_for = 1; cont_for < largo_n; cont_for++)
        tempo_float = tempo_float/10.0;
    
    number += tempo_float/2.0;
    if (number >= 10.0)
    {
        number = 1.0; 
        largo_entera++;
    }
    if (largo_entera<0)                                 //  si tiene decimales
    {
        *text++ = '0'; *text++ = '.';
        if (largo_n < 0) 
            largo_entera = largo_entera-largo_n;
        for (cont_for = -1; cont_for > largo_entera; cont_for--)  
            *text++ = '0';
    }
    for (cont_for=0; cont_for < largo_n; cont_for++)
    {
        tempo_int = (int)number;
        *text++ = (char)tempo_int + 48;                  //convierte a ascci
        if (cont_for ==  largo_entera ) 
            *text++ = '.';
        number -= (tempo_float=tempo_int);
        number = number *10.0;
    }
    *text =0;                                            //anexa final de linea
}