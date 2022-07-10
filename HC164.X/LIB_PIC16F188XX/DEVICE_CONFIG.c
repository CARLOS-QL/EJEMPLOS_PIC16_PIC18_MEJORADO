
#include "DEVICE_CONFIG.h"

/*******************************************************************************
 *  Funciones de inicializacion                                                 
 ******************************************************************************/

void SYSTEM_init(void)
{
    PIN_MANAGER_init();
    OSC_init();
    /* Incluir inicializacion de perifericos */
}

/*******************************************************************************
 * Configiracion del oscilador    
 * OSC: EXTOSC. HFINTOSC, LFINTOSC, SOSC, EXTOSC_PLLX4, HFINTOSC_PLLX2
 * DIV: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512      
 * FREQ: 1, 2, 4, 8, 12, 16, 32                                                                 
 ******************************************************************************/

void OSC_init(void)
{  
    OSCCON1bits.NOSC = NOSC_HFINTOSC;   // Configuracion nuevo oscilador   
    OSCCON1bits.NDIV = NDIV_1;          // Configuracion nuevo divisor freq
    OSCFRQbits.HFFRQ = HFFRQ_4;         // Frecuencia del oscilador interno 
}

/*******************************************************************************
 * Configuracion de pines GPIO
 ******************************************************************************/

void PIN_MANAGER_init(void)
{
    LATA = 0b00000000;          // Iniciar LAT en 0 
    LATB = 0b00000000;          // Valor inicial desconocido 
    LATC = 0b00000000; 
    LATD = 0b00000000;
    LATE = 0b00000000;          // Solo tiene hasta RE3

    TRISA = 0b11111111;         // Por defecto IN digital
    TRISB = 0b11100111;         // 1=INPUT, 0=OUTPUT
    TRISC = 0b10111111;           
    TRISD = 0b11111111;
    TRISE = 0b11111111;         // Solo tiene hasta RE3

    ANSELA = 0b11111111;        // Por defecto IN analogicas
    ANSELB = 0b11100111;        // 1=analogico, 0=digital
    ANSELC = 0b11111111;       
    ANSELD = 0b11111111;        
    ANSELE = 0b11111111;        // Solo tiene hasta RE3
            
    WPUA = 0b00000000;          // Por defecto pull up off
    WPUB = 0b00000000;          // 1=ON, 0=OFF
    WPUC = 0b00000000;
    WPUD = 0b00000000;          
    WPUE = 0b00000000;          // Solo tiene hasta RE3

    ODCONA = 0b00000000;        // Por defecto OUT push pull              
    ODCONB = 0b00000000;        // 1=open drain, 0=push pull
    ODCONC = 0b00000000;
    ODCOND = 0b00000000;
    ODCONE = 0b00000000;        // Solo tiene hasta RE3
}
  
