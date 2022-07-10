/********************************************************
* Etiquetas y Macos para el proyecto
********************************************************/

#define INPUT               1
#define OUTPUT              0
#define HIGH                1
#define LOW                 0
#define ANALOG              1
#define DIGITAL             0
#define PULL_UP_ENABLED     1
#define PULL_UP_DISABLED    0

/*******************************************************************
* Etiquetas y para la configracion del oscilador
*******************************************************************/

//Para configurar en OSCCON1bits.NOSC el nuevo oscildor

#define NOSC_EXTOSC 		0b111       // Oscilador Externo
#define NOSC_HFINTOSC 		0b110       // Interno de alta velocidad (1-32 MHz)
#define NOSC_LFINTOSC 		0b101       // Interno de baja velocidad 31 KHz
#define NOSC_SOSC           0b100       // Oscilador secundario
#define NOSC_EXTOSC_PLLX4 	0b010       // Osclidaor externo con PLL x 4
#define NOSC_HFINTOSC_PLLX2 0b001       // Interno altta velocidad con PLL x 2

// Para configurar en OSCCON1bits.NDIV el nuevo divisor de frecuencia 

#define NDIV_512            0b1001      //Postscaler x 512
#define NDIV_256            0b1000      //Postscaler x 256
#define NDIV_128            0b0111      //Postscaler x 128
#define NDIV_64             0b0110      //Postscaler x 64
#define NDIV_32             0b0101      //Postscaler x 32
#define NDIV_16             0b0100      //Postscaler x 16
#define NDIV_8              0b0011      //Postscaler x 8
#define NDIV_4              0b0010      //Postscaler x 4
#define NDIV_2              0b0001      //Postscaler x 2
#define NDIV_1              0b0000      //Postscaler x 1

// Para configurar en OSCFRQbits.HFFRQ la frecuencia del oscilador interno

#define HFFRQ_32            0b110       // 32 MHz
#define HFFRQ_16            0b101       // 16 MHz
#define HFFRQ_12            0b100       // 12 MHz
#define HFFRQ_8             0b011       // 8 MHz
#define HFFRQ_4             0b010       // 4 MHz
#define HFFRQ_2             0b001       // 2 MHz
#define HFFRQ_1             0b000       // 1 MHz


/*************************************************************
 *  Interrupciones Globales y de perifericos 
 ************************************************************/

#define INTERRUPT_global_enable()       (INTCONbits.GIE = 1)
#define INTERRUPT_global_disable()      (INTCONbits.GIE = 0)
#define INTERRUPT_peripheral_enable() 	(INTCONbits.PEIE = 1)
#define INTERRUPT_peripheral_disable() 	(INTCONbits.PEIE = 0)


/*********************************************************
 * Etiquetas para remapear pines PPS 
 * Compatible para la familia 16F188xx
 *********************************************************/

/******************************************************************
 Etiquetas para definir PPS de entrada de perifericos
 Este valor debe asignarse a uno de los (PERIFERICO)PPS de entrada
 RXPPS = PPSIN_RC7
******************************************************************/

#define PPSIN_RA0   0x00
#define PPSIN_RA1   0x01
#define PPSIN_RA2   0x02
#define PPSIN_RA3   0x03
#define PPSIN_RA4   0x04
#define PPSIN_RA5   0x05
#define PPSIN_RA6   0x06
#define PPSIN_RA7   0x07

#define PPSIN_RB0   0x08
#define PPSIN_RB1   0x09
#define PPSIN_RB2   0x0A
#define PPSIN_RB3   0x0B
#define PPSIN_RB4   0x0C
#define PPSIN_RB5   0x0D
#define PPSIN_RB6   0x0E
#define PPSIN_RB7   0x0F

#define PPSIN_RC0   0x10
#define PPSIN_RC1   0X11
#define PPSIN_RC2   0x12
#define PPSIN_RC3   0x13
#define PPSIN_RC4   0x14
#define PPSIN_RC5   0x15
#define PPSIN_RC6   0x16
#define PPSIN_RC7   0x17

#define PPSIN_RD0   0x18
#define PPSIN_RD1   0x19
#define PPSIN_RD2   0x1A
#define PPSIN_RD3   0x1B
#define PPSIN_RD4   0x1C
#define PPSIN_RD5   0x1D
#define PPSIN_RD6   0x1E
#define PPSIN_RD7   0x1F

#define PPSIN_RE0   0x20
#define PPSIN_RE1   0x21
#define PPSIN_RE2   0x22
#define PPSIN_RE3   0x23

/********************************************************
 Etiquetas para definir PPS para salida de perifericos
 Este valor debe agregarse al registro (PIN)PPS
 RC6PPS = PPSOUT_TX
********************************************************/

#define PPSOUT_ADGRDG 	0x25
#define PPSOUT_ADGRDA 	0x24
#define PPSOUT_CWG3D  	0x23
#define PPSOUT_CWG3C	0x22
#define	PPSOUT_CWG3B	0x21
#define	PPSOUT_CWG3A	0x20
#define PPSOUT_CWG2D	0x1F
#define PPSOUT_CWG2C	0x1E
#define PPSOUT_CWG2B	0x1D
#define PPSOUT_CWG2A	0x1C
#define	PPSOUT_DSM      0x1B
#define	PPSOUT_CLKR     0x1A
#define	PPSOUT_NCO      0x19
#define	PPSOUT_TMR0     0x18
#define	PPSOUT_SDO2    	0x17
#define	PPSOUT_SDA2     0x17
#define PPSOUT_SCK2    	0x16
#define PPSOUT_SCL2     0x16
#define PPSOUT_SD01     0x15
#define PPSOUT_SDA1     0x15
#define	PPSOUT_SCK1    	0x14
#define	PPSOUT_SCL1     0x14
#define	PPSOUT_C2OUT	0x13
#define	PPSOUT_C1OUT	0x12
#define	PPSOUT_DT       0x11
#define	PPSOUT_TX       0x10
#define	PPSOUT_CK       0x10
#define PPSOUT_PWM7     0x0F
#define	PPSOUT_PWM6     0x0E
#define	PPSOUT_CCP5     0x0D
#define PPSOUT_CCP4     0x0C
#define PPSOUT_CCP3     0x0B
#define PPSOUT_CCP2     0x0A
#define	PPSOUT_CCP1     0x09
#define PPSOUT_CWG1D	0x08
#define PPSOUT_CWG1C	0x07
#define PPSOUT_CWG1B	0x06
#define PPSOUT_CWG1A	0x05
#define PPSOUT_CLC4   	0x04
#define PPSOUT_CLC3   	0x03
#define PPSOUT_CLC2     0x02
#define PPSOUT_CLC1     0x01

