#include<LPC21XX.H>
#include "delay.h"
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
#define LCD_D 0XFF<<0
#define RS 1<<21
#define E 1<<22
int main(){
LCD_INIT();
LCD_COMMAND(0x80);
LCD_DATA('A');
}
void LCD_INIT(void){
IODIR0=LCD_D|RS|E;
LCD_COMMAND(0x01);
LCD_COMMAND(0x02);
LCD_COMMAND(0x38);
}
void LCD_COMMAND(unsigned char cmd){
IOCLR0=LCD_D;
IOSET0=cmd;
IOCLR0=RS;
IOSET0=E;
delay_millisecond(2);
IOCLR0=E;
}
void LCD_DATA(unsigned char d){		 
IOCLR0=LCD_D;
IOSET0=d;
IOSET0=RS;
IOSET0=E;
delay_millisecond(2);
IOCLR0=E;
}