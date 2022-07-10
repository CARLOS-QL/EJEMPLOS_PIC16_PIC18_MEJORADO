/***************************************
*  Configuracion pines I2C1  
*  Solo PUERTOS B y C   
****************************************/

#include "DEVICE_CONFIG.h"

#define SDA1_OUT        RB4PPS         //SDA salida
#define SCL1_OUT        RB3PPS         //SCL salida
#define SDA1_IN         PPSIN_RB4      //SDA entrada
#define SCL1_IN         PPSIN_RB3      //SCL entrada

#define I2C_BAUD_RATE   100000UL
#define SSP1ADD_VAL     ((_XTAL_FREQ/(4UL * I2C_BAUD_RATE))-1)


void I2C_init(void);
static inline void I2C_master_wait(void);
void I2C_start(void);
void I2C_restart(void);
void I2C_stop(void);
uint8_t I2C_write(uint8_t I2C_data);
uint8_t I2C_read(void);
void I2C_ack(void);
void I2C_nack(void);
void I2C_write_1register(uint8_t address, uint8_t data);

