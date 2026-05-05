#define F_CPU 16000000UL
#include "btn.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

//Columns are on PORTD[4:7], rows are on PORTD[0:3]

uint8_t poweredColumn;  // Currently Powered column
uint8_t lastBtnPressed; // Index of which button was last pressed
uint8_t btnPressed = 0; // Bool to indicate a button was pressed

void initBtnMatrix() {
    // Set PD4-PD7 as outputs for powering columns
    BTN_DDR |= 0xF0;
    // Set PD0-PD3 as inputs for reading rows
    BTN_DDR &= ~0x0F;
    // Enable pull-up resistors on PD0-PD3
    BTN_PORT |= 0x0F;
}

void runBtnMatrix() {
    // Cycle through columns 0-3
    for (poweredColumn = 0; poweredColumn < 4; poweredColumn++) {
        BTN_PORT = (BTN_PORT & 0x0F) & ~(1 << (poweredColumn));
        _delay_ms(5);
    }
}

// Returns the button pressed as a number 0-15, or 255 if no button is pressed
uint8_t buttonPressed() {
    if (btnPressed) {
        btnPressed = 0; // Reset flag
        return lastBtnPressed;
    }
    return 255; // No button pressed
}

 // Check which button is pressed and update poweredColumn accordingly
ISR(PCINT2_vect) {
    uint8_t rowState = BTN_PORT & 0x0F;
    for (uint8_t row = 0; row < 4; row++) {
        if (!(rowState & (1 << row))) {
            lastBtnPressed = poweredColumn + 4*row;
            btnPressed = 1;
            break;
        }
    }
}