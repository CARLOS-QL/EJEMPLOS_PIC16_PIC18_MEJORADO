/*
 * File:   main.c
 * Author: CarlosQL
 *
 * Created on November 20, 2022, 3:07 PM
 */


#include <xc.h>

//================ CONFIG1 Configuracion del Oscilador =========================
 
#pragma config FCMEN = ON           // Monitor de seguridd de reloj FCMEN (ON, OFF)
#pragma config CSWEN = ON           // Escribir en NOSC y NDIV para cambio de reloj (ON, OFF)
#pragma config CLKOUTEN = OFF       // Salida de reloj (ON, OFF)
#pragma config RSTOSC = HFINT1      // EXT1X, HFINT1, LFINT, SOSC, EXT4X, HFINTPLL, HFINT32                                                                
#pragma config FEXTOSC = HS         // ECH, ECM, ECL, OFF, HS, XT, LP   

//================ CONFIG2 Configuracion de los supervisores ===================

#pragma config MCLRE = ON           // Master Clear (ON, OFF)
#pragma config PWRTE = ON           // Power-up Timer (ON, OFF)
#pragma config LPBOREN = OFF        // Low-Power BOR (ON, OFF)
#pragma config BOREN = OFF          // Brown-out reset enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO            // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices
#pragma config ZCD = OFF            // Zero-cross detect disable->Zero-cross detect circuit is disabled at POR.
#pragma config PPS1WAY = ON         // Peripheral Pin Select one-way control->The PPSLOCK bit can be cleared and set only once in software
#pragma config STVREN = ON          // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset
#pragma config DEBUG = OFF          // Background Debugger->Background Debugger disabled

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


#include "LCD.h"
#include "I2C.h"
#include "DS3231.h"

void OSC_init(void)
{  
    OSCCON1bits.NOSC = 0b110;     
    OSCCON1bits.NDIV = 0b0000;         
    OSCFRQbits.HFFRQ = 0b010;         
}

void PIN_MANAGER_init(void)
{
	TRISC = 0b11111111;  
	TRISD = 0b00001111; 
	TRISE = 0b11111111; 

	ANSELC = 0b11100111;
	ANSELD = 0b00001111;
	ANSELE = 0b11111001;
}

void main(void) {
    
    PIN_MANAGER_init();
    OSC_init();
    
    LCD_init();
    I2C_init();
    
    convertirHora();
    enviar_hora();
      
    convertirFecha();
    enviar_fecha();
    
    while(1)
    {
        LCD_goto(2, 1);
        LCD_printf("Hora  ");
        leer_hora();
        mostrar_hora();
        
        LCD_goto(2, 2);
        LCD_printf("Fecha ");
        leer_fecha();
        mostrar_fecha();
        __delay_ms(100);
    }
    return;
}
