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

int main(){
    SPI_init();
    max7219_init();
    clear_matrix();

    // Example: Light up LEDs in a pattern
    while (1) {
        for (int i = 0; i < 8; i+=2) {
            for(int j = 0; j < 8; j+=2) {
                set_led(i, j, 1);
                set_led(i, j+1, 1);
                set_led(i+1, j, 1);
                set_led(i+1, j+1, 1);
                _delay_ms(1000);
            }
        }
        clear_matrix();
        _delay_ms(500);
        max7219_init();
        clear_matrix();
        _delay_ms(500);
    }

    return 0;
}
