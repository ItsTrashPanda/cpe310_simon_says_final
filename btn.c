#define F_CPU 16000000UL
#include "btn.h"
#include "lcd.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

//Columns are on PORTD[4:7], rows are on PORTD[0:3]

void initBtnMatrix() {
    // Set PD4-PD7 as inputs for powering columns
    BTN_DDR &= ~0xF0;
    // Set PD0-PD3 as ouputs for reading rows
    BTN_DDR |= 0x0F;
    // Enable pull-up resistors on PD4-PD7
    BTN_PORT |= 0xF0;
}

void buttonPressed() {
	unsigned char anyKeyPressed;
	
	// Loop until a key is pressed
	do {
		// Ground all rows
		BTN_PORT = 0x0 | (PIND & 0xF0);
		anyKeyPressed = PIND & 0xF0;
	} while (anyKeyPressed == 0xF0);
}

void debounce() {
	// Wait and loop until get 2nd sample of key pressed
	do {
		_delay_ms(20);
	} while ( (PIND & 0xF0) == 0xF0 );
}

uint8_t identifyPressedKey() {
	unsigned char column, row; // Record column and row of pressed key
	unsigned char found = 0;   // Set to 1 when pressed key found
	
	// Array to hold keypad values
	uint8_t keypad[4][4] = {	{0, 1, 2, 3},
	{4, 5, 6, 7},
	{8, 9, 10, 11},
	{12, 13, 14, 15}};

	// Check each row till find pressed key
	if (!found) {
		// Ground row 0
		BTN_PORT = 0x07;
		_delay_ms(20);
		column = PIND & 0xF0;
		
		if (column != 0xF0) {
			row = 0;
			found = 1;
		}		
	}
	
	if (!found) {
		// Ground row 1
		BTN_PORT = 0x0B;
		_delay_ms(20);
		column = PIND & 0xF0;
		
		if (column != 0xF0) {
			row = 1;
			found = 1;
		}
	}

	if (!found) {
		// Ground row 2
		BTN_PORT = 0x0D;
		_delay_ms(20);
		column = PIND & 0xF0;
		if (column != 0xF0) {
			row = 2;
			found = 1;
		}
	}

	if (!found) {
		// Ground row 3
		BTN_PORT = 0x0E;
		_delay_ms(20);
		column = PIND & 0xF0;
		if (column != 0xF0) {
			row = 3;
			found = 1;
		}
	}

	// Decode column
	switch (column) {
		case 0xE0:		column = 0; break;
		case 0xD0:		column = 1; break;
		case 0xB0:		column = 2; break;
		case 0x70:		column = 3; break;
		default:		column = 3;
	}
	
	return keypad[row][column];
}