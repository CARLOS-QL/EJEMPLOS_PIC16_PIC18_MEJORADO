
/* 
 * File:        i2C   
 * Author:      cARLOS qL
 * Comments:
 * Revision history: 
 */


#ifndef I2C_H
#define	I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define _XTAL_FREQ 4000000
#define BAUDRATE 100000UL
#define VALOR ((_XTAL_FREQ/(4UL*BAUDRATE))-1)

void I2C_init();
void I2C_start(void);
void I2C_restart(void);
void I2C_stop(void);
char I2C_read(void);
void I2C_ack(void);
void I2C_nack(void);
void I2C_write(char I2C_data);

#endif	/* XC_HEADER_TEMPLATE_H */

