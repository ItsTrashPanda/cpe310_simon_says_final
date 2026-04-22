#include "spi.h"
#include <avr/io.h>
#include <util/delay.h>

// Pin definitions for ATmega328PB
#define DDR_SPI DDRB
#define PORT_SPI PORTB
#define DD_MOSI PB3
#define DD_SCK PB5
#define DD_SS PB2

// SPI initialization for AVR (ATmega328PB uses SPI0)
void SPI_init(void) {
    // Set MOSI, SCK, SS as output
    DDR_SPI |= (1 << DD_MOSI) | (1 << DD_SCK) | (1 << DD_SS);
    // Enable SPI0, Master mode, clock rate fck/16 (adjust SPR00/SPR01 for speed)
    SPCR0 = (1 << SPE0) | (1 << MSTR0) | (1 << SPR00);
}

// Send a byte over SPI
void SPI_send(uint8_t data) {
    SPDR0 = data;
    while (!(SPSR0 & (1 << SPIF0)));  // Wait for transmission complete
}

// Send data to MAX7219 (address: register, data: value)
void max7219_send(uint8_t address, uint8_t data) {
    PORT_SPI &= ~(1 << MAX7219_CS);  // CS low to start transfer
    SPI_send(address);
    SPI_send(data);
    PORT_SPI |= (1 << MAX7219_CS);   // CS high to latch data
}

// Initialize MAX7219
void max7219_init() {
    max7219_send(0x0C, 0x01);  // Shutdown register: normal operation (0x00 for shutdown)
    max7219_send(0x09, 0x00);  // Decode mode: no decode for LED matrix
    max7219_send(0x0A, 0x0F);  // Intensity: maximum brightness (0x00-0x0F)
    max7219_send(0x0B, 0x07);  // Scan limit: display all 8 digits (rows)
    max7219_send(0x0F, 0x00);  // Display test: off (0x01 for test mode)
}

// Set a row of the 8x8 matrix (row 0-7, data: 8-bit pattern for columns)
void set_row(uint8_t row, uint8_t data) {
    if (row < 8) {
        max7219_send(row + 1, data);  // Digit registers: 0x01-0x08 for rows 0-7
    }
}

// Turn on/off a specific LED (row 0-7, col 0-7, on: 1=on, 0=off)
void set_led(uint8_t row, uint8_t col, uint8_t on) {
    static uint8_t matrix[8] = {0};  // Store current state (one byte per row)
    if (on) {
        matrix[row] |= (1 << col);
    } else {
        matrix[row] &= ~(1 << col);
    }
    set_row(row, matrix[row]);
}

// Clear the entire matrix
void clear_matrix() {
    for (uint8_t i = 0; i < 8; i++) {
        set_row(i, 0x00);
    }
}