/********************************************************
 * libreria para la atención de las Interrupciones
 * Contiene Macros de on, off de interrupciones
 * Creacion 3/05/2020
 ********************************************************/

#ifndef INTERRUPT_H
#define INTERRUPT_H

/******** Interrupciones Globales y de perifericos ********/

#define INTERRUPT_global_enable()       (INTCONbits.GIE = 1)
#define INTERRUPT_global_disable()      (INTCONbits.GIE = 0)
#define INTERRUPT_peripheral_enable() 	(INTCONbits.PEIE = 1)
#define INTERRUPT_peripheral_disable() 	(INTCONbits.PEIE = 0)

/************ Interrupciones principales  ***********/

#define INTERRUPT_TMR0_enable()         (PIE0bits.TMR0IE = 1)
#define INTERRUPT_TMR0_disable()        (PIE0bits.TMR0IE = 0)
#define INTERRUPT_IOC_enable()          (PIE0bits.IOCIE = 1)
#define INTERRUPT_IOC_disable()         (PIE0bits.IOCIE = 0)
#define INTERRUPT_INT_enable()          (PIE0bits.INTE = 1)
#define INTERRUPT_INT_disable()         (PIE0bits.INTE = 0)


/************ Interrupciones de perifericos  ***********/

#define INTERRUPT_OSF_enable()          (PIE1bits.OSFIE = 1)
#define INTERRUPT_OSF_disable()         (PIE1bits.OSFIE = 0)
#define INTERRUPT_CSW_enable()          (PIE1bits.CSWIE = 1)
#define INTERRUPT_CSW_disable()         (PIE1bits.CSWIE = 0)
#define INTERRUPT_ADT_enable()          (PIE1bits.ADIE = 1)
#define INTERRUPT_ADT_disable()         (PIE1bits.ADIE = 0)
#define INTERRUPT_AD_enable()           (PIE1bits.ADIE = 1)
#define INTERRUPT_AD_disable()          (PIE1bits.ADIE = 0)

#define INTERRUPT_ZCD_enable()          (PIE2bits.ZCDIE = 1)
#define INTERRUPT_ZCD_disable()         (PIE2bits.ZCDIE = 0)
#define INTERRUPT_C2_enable()           (PIE2bits.C2IE = 1)
#define INTERRUPT_C2_disable()          (PIE2bits.C2IE = 0)
#define INTERRUPT_C1_enable()           (PIE2bits.C1IE = 1)
#define INTERRUPT_C1_disable()          (PIE2bits.C1IE = 0)

#define INTERRUPT_RX_enable()           (PIE3bits.RCIE = 1)
#define INTERRUPT_RX_disable()          (PIE3bits.RCIE = 0)
#define INTERRUPT_TX_enable()           (PIE3bits.TXIE = 1)
#define INTERRUPT_TX_disable()          (PIE3bits.TXIE = 0)
#define INTERRUPT_BCL2_enable()         (PIE3bits.BCL2IE = 1)
#define INTERRUPT_BCL2_disable()        (PIE3bits.BCL2IE = 0)
#define INTERRUPT_SSP2_enable()         (PIE3bits.SSP2IE = 1)
#define INTERRUPT_SSP2_disable()        (PIE3bits.SSP2IE = 0)
#define INTERRUPT_BCL1_enable()         (PIE3bits.BCL1IE = 1)
#define INTERRUPT_BCL1_disable()        (PIE3bits.BCL1IE = 0)
#define INTERRUPT_SSP1_enable()         (PIE3bits.SSP2IE = 1)
#define INTERRUPT_SSP1_disable()        (PIE3bits.SSP2IE = 0)

#endif	/* INTERRUPT_H */