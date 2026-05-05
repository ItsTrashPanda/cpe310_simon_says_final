/**
 * @file main.c
 * @author adam
 * @date 2026-04-22
 * @brief Main function for Simon Says with MAX7219 LED Matrix
 */

#define F_CPU 16000000UL  // Define CPU frequency for delay functions

#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"

uint8_t sequence[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};


int main(){
    lcd_init();
    lcd_clear();

    SPI_init();
    max7219_init();
    clear_matrix();

    lcd_gotoxy(1,1);
    lcd_print("Press any button");
    lcd_gotoxy(1,2);
    lcd_print("to start");

    while(1) {
        // Main game loop
        runBtnMatrix();
        if(buttonPressed() != 255) {
            // Start game logic here
            lcd_clear();
            lcd_gotoxy(1,1);
            lcd_print("Game Started!");

        }

    }

    return 0;
}
