/**
 * @file main.c
 * @author adam
 * @date 2026-04-22
 * @brief Main function for Simon Says with MAX7219 LED Matrix
 */

#define F_CPU 16000000UL  // Define CPU frequency for delay functions

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "spi.h"
#include "lcd.h"
#include "btn.h"
#include "i2c.h"

uint8_t sequence[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
uint8_t level = 1;

uint8_t pressed = 255;
uint8_t pressedSequence[16] = {255};
uint8_t usrIndex = 0;

unsigned char control = 'H';

int main(){
    lcd_init();
    lcd_clear();

    SPI_init();
    max7219_init();
    clear_matrix();

    //*
    lcd_gotoxy(1,1);
    lcd_print((unsigned char *)"Press any button");
    lcd_gotoxy(1,2);
    lcd_print((unsigned char *)"to start");
    //*/

    
    initBtnMatrix();
/*
    unsigned char * temp = 'thisissomething';

    while(1) {
        runBtnMatrix();

        lcd_clear();
        sprintf(temp, "I: %d", triggered);
        lcd_print(temp);
        _delay_ms(50);
    }
    //*/

    while(1) {
        // Main game loop
        buttonPressed();
        debounce();
        pressed = identifyPressedKey();
        switch(control) {
            case 'H': { //Hold
                if(pressed != 255) {
                    level = 1;
                    usrIndex = 0;
                    //control = 'D';
                    lcd_clear();
                    lcd_gotoxy(1,1);
                    //lcd_print((unsigned char *)("Pay Attention!"));
                    unsigned char * temp = "thisissomething";
                    lcd_clear();
                    sprintf(temp, "I: %d", pressed);
                    lcd_print(temp);
                    _delay_ms(50);
                }
                break;
            }
            case 'D': { //Display
                clear_matrix();
                for(int i = 0; i < level; i++) {
                    uint8_t pixel = sequence[i];
                    uint8_t r = (pixel - pixel % 4) / 4;
                    uint8_t c = pixel % 4;
                    set_led(r,c,1);
                    _delay_ms(500);
                    set_led(r,c,0);
                } 
                control = 'P';
                break;
            }
            case 'P': { //Play
                if(pressed != 255) {
                    pressedSequence[usrIndex] = pressed;
                    usrIndex++;
                }
                if(usrIndex == level) {
                    control = 'C';
                }
                break;
            }
            case 'C': { //Check
                uint8_t passed = 1;
                for(int i = 0; i < level; i++) {
                    if(sequence[i] != pressedSequence[i]) {
                        passed = 0;
                        break;
                    }
                }
                if(passed == 0) {
                    lcd_clear();
                    lcd_gotoxy(1,1);
                    lcd_print((unsigned char *)"You Failed!");
                    lcd_gotoxy(1,2);
                    lcd_print((unsigned char *)"Play again?");
                    control = 'H';
                    break;
                }
                if(level != 16) {
                    lcd_clear();
                    lcd_gotoxy(1,1);
                    lcd_print((unsigned char *)"You Passed!");
                    _delay_ms(500);
                    level++;
                    control = 'D';
                } else {
                    lcd_clear();
                    lcd_gotoxy(1,1);
                    lcd_print((unsigned char *)"You Won!");
                    lcd_gotoxy(1,2);
                    lcd_print((unsigned char *)"Play again?");
                    control = 'H';
                }
                break;
            }
        }
    }

    return 0;
}
