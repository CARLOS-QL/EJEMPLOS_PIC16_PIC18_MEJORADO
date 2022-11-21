

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DS3231_H
#define	DS3231_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "I2C.h"
#include "LCD.h"

uint8_t sec, min, hora;
uint8_t dia, mes, anio;

char Hora[] = "105845";
char Fecha[] = "200319";

void enviar_hora(void);
void leer_hora(void);
void enviar_fecha(void);
void leer_fecha(void);
void mostrar_hora(void);
void mostrar_fecha(void);
void convertirHora(void);
void convertirFecha(void);


#endif	/* XC_HEADER_TEMPLATE_H */

