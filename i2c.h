#ifndef I2C_H
#define I2C_H

#define START       0x08
#define REPEATED_START  0x10
#define MT_SLA_ACK  0x18
#define MT_SLA_NACK 0x20
#define MT_DATA_ACK  0x28
#define MT_DATA_NACK 0x30
#define Arbitration_Lost 0x38
#define MR_SLA_ACK  0x40
#define MR_SLA_NACK 0x48
#define MR_DATA_ACK  0x50
#define MR_DATA_NACK 0x58


void ERROR();
void i2c_init();
void i2c_start();
void i2c_address(unsigned char address);
void i2c_data(unsigned char data);
void i2c_stop();
void i2c(unsigned char data, unsigned char address);

#endif