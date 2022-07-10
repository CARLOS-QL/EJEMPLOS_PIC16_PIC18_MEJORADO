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

#include "KEYPAD.h"

/*******************************************************************************
 * Realiza el barrido por las 4 filas
 ******************************************************************************/

void ROW_scan(uint8_t row)
{
	ROW1 = 1;
	ROW2 = 1;
	ROW3 = 1;
	ROW4 = 1;
	switch(row)
	{
		case 1: ROW1 = 0; break;
		case 2: ROW2 = 0; break;
		case 3: ROW3 = 0; break;
		case 4: ROW4 = 0; break;
	}
	asm("NOP");
}

/*******************************************************************************
 * Lee el estado de las 4 columnas
 ******************************************************************************/

uint8_t COL_scan(uint8_t row)
{
	if(COL1 == 0)
        return 1+row;
	if(COL2 == 0)
        return 2+row;
	if(COL3 == 0)
        return 3+row;
	if(COL4 == 0)
        return 4+row;
	return 0;
}

/*******************************************************************************
 * retorna con el valor de la tecla pulsada, retorna 0 si no han presionado
 ******************************************************************************/

uint8_t KEYPAD_read(void)
{
	__delay_ms(10);
	uint8_t veces=0;

	for (uint8_t row = 1; row <= 4; row++)
	{
		ROW_scan(row);
		uint8_t key =COL_scan(veces);
		if (key != 0)
		{
			while(COL1 == 0 || COL2 == 0 || COL3 == 0 || COL4 == 0);
			__delay_ms(50);
			return key_table[key-1];
		}
		veces= veces+4;
	}
	return 0;   //Retorna 0 si no hay tecla presionada
}