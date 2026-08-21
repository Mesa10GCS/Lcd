#include "lcd.h"

#define clear_display 0x51
#define desp_izq 0x49
#define desp_der 0x4A

int filas_hex[2]={0x00,0x40};
int char_cond;

void lcd_init(lcd_t*  lcd){
    if(lcd->puerto_pines==GPIOA) RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    if(lcd->puerto_pines==GPIOB) RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
    if(lcd->puerto_pines==GPIOC) RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;
    for(int i=0;i<8;i++){
        if(lcd->d[i]<8){
            lcd->puerto_pines->CRL|=(0xF<<(lcd->d[i]*4));
            lcd->puerto_pines->CRL|=(0x1<<(lcd->d[i]*4));
        }else{
            lcd->puerto_pines->CRH|=(0xF<<(lcd->d[i]*4));
            lcd->puerto_pines->CRH|=(0x1<<(lcd->d[i]*4));
        }
    }
}

lcd_send(lcd_t* lcd, uint8_t dato, int char_cmd){
    if(char_cmd) lcd->puerto_pines->BSRR|=(1<<lcd->rs);
    else lcd->puerto_pines->BSRR|=(1<<(lcd->rs+16));
    for(int i=0;i<8;i++){
        if(dato&(1<<i))
            lcd->puerto_pines->BSRR|=(1<<lcd->d[i]);
            else lcd->puerto_pines->BSRR|=(1<<(lcd->d[i]+16));
    }
}

void lcd_clear(lcd_t*lcd){
    lcd_send(lcd, clear_display, 0);
}

void lcd_setCursor(lcd_t* lcd, int col, int fil){
        lcd_send(lcd, col+filas_hex[fil], 0);
}

void lcd_print(lcd_t*lcd,char *txt){
    while(*txt){
        lcd_send(lcd,*txt,1 );
        txt++; 
    }
}

void lcd_scrollDisplayLeft(lcd_t* lcd){
    lcd_send(lcd, desp_izq, 0);
}
void lcd_scrollDisplayRight(lcd_t* lcd){
    lcd_send(lcd, desp_der, 0);
}