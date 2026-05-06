#ifndef BTN_H
#define BTN_H

#include <stdint.h>

#define BTN_DDR DDRD
#define BTN_PORT PORTD

void initBtnMatrix();
void debounce();
void buttonUnPressed();
void buttonPressed();
uint8_t identifyPressedKey();

#endif