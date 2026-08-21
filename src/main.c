#include "stm32f103xb.h"
#include "lcd.h"

int pines[8]={0,1,2,3,4,5,6,7};

int main(void){
    lcd_t lcd;
    lcd.puerto_pines=GPIOA;
    for(int i=0;i<8;i++){
        lcd.d[i]=pines[i];
    }
    lcd.rw=8;
    lcd.rs=9;
    lcd_init(&lcd);
    while(1){
        lcd_print(&lcd, "Digitales");
        for(int i=0;i<10;i++){
        delay(1000);
        lcd_scrollDisplayRight(&lcd);
        }

    }
}

