#ifndef LCD_H
#define LCD_H

#define LCD_RS (1 << 0)
#define LCD_RW (1 << 1)
#define LCD_EN (1 << 2)
#define LCD_BL (1 << 3)
#define LCD_ADDR 0x27 // I2C address of the LCD

void lcdCommanda(unsigned char cmnd);
void lcdData(unsigned char data);
void lcd_init();
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_print(unsigned char * str);
void lcd_clear();
void lcd_expander_write(int data);
void pulse_enable(int data);
void lcd_write4bits(int data);
void lcd_send(int value, int rs);

#endif