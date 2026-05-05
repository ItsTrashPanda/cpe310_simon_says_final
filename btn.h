#ifndef BTN_H
#define BTN_H

#include <stdint.h>

#define BTN_DDR DDRD
#define BTN_PORT PORTD

void initBtnMatrix();
void runBtnMatrix();
uint8_t buttonPressed();

#endif