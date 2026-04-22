#ifndef SPI_H
#define SPI_H

#include <stdint.h>

// Pin definitions for ATmega328PB
#define MAX7219_CS PB2   // Chip select pin

// Function prototypes
void SPI_init(void);
void SPI_send(uint8_t data);
void max7219_send(uint8_t address, uint8_t data);
void max7219_init(void);
void set_row(uint8_t row, uint8_t data);
void set_led(uint8_t row, uint8_t col, uint8_t on);
void clear_matrix(void);

#endif // SPI_H
