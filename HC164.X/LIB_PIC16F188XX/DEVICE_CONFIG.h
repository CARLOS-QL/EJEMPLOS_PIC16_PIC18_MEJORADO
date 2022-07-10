
#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H

/*******************************************************************************
 * Configuracion de  FUSES del microcontrolador
 ******************************************************************************/

//================ CONFIG1 Configuracion del Oscilador =========================
 
#pragma config FCMEN = ON       // Monitor de seguridd de reloj FCMEN (ON, OFF)
#pragma config CSWEN = ON      	// Escribir en NOSC y NDIV para cambio de reloj (ON, OFF)
#pragma config CLKOUTEN = OFF 	// Salida de reloj (ON, OFF)
#pragma config RSTOSC = HFINT1 	// EXT1X, HFINT1, LFINT, SOSC, EXT4X, HFINTPLL, HFINT32                                                                
#pragma config FEXTOSC = HS   	// ECH, ECM, ECL, OFF, HS, XT, LP   

//================ CONFIG2 Configuracion de los supervisores ===================

#pragma config MCLRE = ON    	// Master Clear (ON, OFF)
#pragma config PWRTE = ON    	// Power-up Timer (ON, OFF)
#pragma config LPBOREN = OFF    // Low-Power BOR (ON, OFF)
#pragma config BOREN = OFF    	// Brown-out reset enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO    	// Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices
#pragma config ZCD = OFF    	// Zero-cross detect disable->Zero-cross detect circuit is disabled at POR.
#pragma config PPS1WAY = ON    	// Peripheral Pin Select one-way control->The PPSLOCK bit can be cleared and set only once in software
#pragma config STVREN = ON    	// Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset
#pragma config DEBUG = OFF    	// Background Debugger->Background Debugger disabled

// CONFIG3
#pragma config WDTCPS = WDTCPS_31   // WDT Period Select bits->Divider ratio 1:65536; software control of WDTPS
#pragma config WDTE = OFF    		// WDT operating mode->WDT Disabled, SWDTEN is ignored
#pragma config WDTCWS = WDTCWS_7    // WDT Window Select bits->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = SC    		// WDT input clock selector->Software Control

// CONFIG4
#pragma config WRT = OFF    		// UserNVM self-write protection bits->Write protection off
#pragma config SCANE = available    // Scanner Enable bit->Scanner module is available for use
#pragma config LVP = OFF    		// Low Voltage Programming Enable bit->High Voltage on MCLR/Vpp must be used for programming

// CONFIG5
#pragma config CP = OFF             // UserNVM Program memory code protection bit->Program Memory code protection disabled
#pragma config CPD = OFF            // DataNVM code protection bit->Data EEPROM code protection disabled

/********************************************************
 * Frecuencia de trabajo para el microcontrolador 
 *******************************************************/

#define _XTAL_FREQ 4000000

/********************************************************
 * Librerias utilizadas en el proyecto 
 *******************************************************/

#include <xc.h>		
#include <stdint.h>         //Para usar enteros
#include <stdbool.h>		//Para usar booleanos
#include <stdio.h>          //Para usa printf y sprintf
#include <string.h>         //Para el manejo de cadenas
#include <stdlib.h>

//========== Para incluir librerias propias ==============

#include "DEF_PIC16F188XX.h"
#include "TO_STRING.h"


/********************************************************
 * Prototipo de funciones de inicializacion 
 *******************************************************/
	
void SYSTEM_init(void);
void OSC_init(void);
void PIN_MANAGER_init(void);


#endif	/* DEVICE_CONFIG_H */