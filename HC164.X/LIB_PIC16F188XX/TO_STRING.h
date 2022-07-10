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

#ifndef TO_STRING_H
#define	TO_STRING_H

#include "DEVICE_CONFIG.h"

void INT_to_string(signed long number, char *text);
void FLOAT_to_string(double number, char *text, char decimal);

#endif	/* TO_STRING_H */


