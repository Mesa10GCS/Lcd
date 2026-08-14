#ifndef Lcd_H
#define Lcd_H
#include "stm32f103xb.h"

typedef struct{
GPIO_TypeDef* puerto_pines;
int d[8];
int rw;
int rs;
} lcd_t;

void lcd_init(lcd_t*);
void lcd_clear(lcd_t*);
void lcd_setCursor(lcd_t*);
void lcd_print(lcd_t*);
void lcd_scrollDisplayLeft(lcd_t);
void lcd_scrollDisplayRight(lcd_t*);
void lcd_createChar (lcd_t*);






#endif
