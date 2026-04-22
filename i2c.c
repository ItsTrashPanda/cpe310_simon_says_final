#include "i2c.h"
#include <avr/io.h>

void ERROR(){
    // Handle error (e.g., blink an LED, send a message, etc.)
    while(1); // Infinite loop to indicate error
}

void i2c_init(){
    TWSR0 = 0x00;          // prescaler = 1
    TWBR0 = 72;            // 100kHz for 16MHz clock
    TWCR0 = (1<<TWEN);
}

void i2c_start(){
    TWCR0 = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR0 & (1<<TWINT)));
}

void i2c_address(unsigned char address){
    TWDR0 = address;
    TWCR0 = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR0 & (1 << TWINT)));
}

void i2c_data(unsigned char data){
    TWDR0 = data;
    TWCR0 = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR0 & (1 << TWINT)));
}

void i2c_stop(){
    TWCR0 = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); // Turns off TWI/I2c by clearing twint, twen, and twisto
}

void i2c(unsigned char data, unsigned char address){
    i2c_init();
    i2c_start();
    i2c_address(address); // Write address
    i2c_data(data); // Write data
    i2c_stop();
}