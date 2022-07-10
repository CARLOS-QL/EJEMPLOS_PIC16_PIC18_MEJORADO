
#include "INTERRUPT.h"
#include "DEVICE_CONFIG.h"

void __interrupt() INTERRUPT_InterruptManager (void)
{

    if(PIE0bits.INTE == 1 && PIR0bits.INTF == 1)            //Interrupcion INT
    {
       // printf("carlos");
    }
    else if(PIE0bits.IOCIE == 1 && PIR0bits.IOCIF == 1)     //Interrupcion IOC
    {
        //printf("carlos");
    }
    else if(PIE0bits.TMR0IE == 1 && PIR0bits.TMR0IF == 1)   //Interrupcion TMR0
    {
        
    } 
    else if(INTCONbits.PEIE == 1)
    {
        if(PIE3bits.RCIE == 1 && PIR3bits.RCIF == 1)        //Interrupcion por RX       
        {
            UART_receive_ISR();
        } 
        else if(PIE1bits.OSFIE ==1 && PIR1bits.OSFIF)
        {
            SP1BRGL = 0x38;                 // Para 12MHz externo
            SP1BRGH = 0x01;                 // SP1BRGH 0;	
            printf("Interrupcion por OSF\n\r");
            //OSF_ISR();
            INTERRUPT_OSF_disable();
        }     
        else if(PIE1bits.CSWIE ==1 && PIR1bits.CSWIF)
        {         
            printf("Interrupcion por CSW\n\r");
            INTERRUPT_CSW_disable();
        }
       
    }      
    else
    {
        //Interrupcion no controlada
    }
}