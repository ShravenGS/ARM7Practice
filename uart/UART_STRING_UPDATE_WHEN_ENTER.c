#include <LPC21XX.h>
#include "lcd_n.h"

#define LED1 (1 << 17)
#define LED2 (1 << 18)
#define LED3 (1 << 19)

void UART0_CONFIG(void) {
    PINSEL0 = 0x5; 
    U0LCR = 0x83; 
    U0DLL = 97;  
    U0DLM = 0;
    U0LCR = 0x03; 
}

void UART0_TX(unsigned char txByte) {
    while (((U0LSR >> 5) & 1) == 0);
    U0THR = txByte;
}

unsigned char UART0_RX() {
    while ((U0LSR & 1) == 0);
    return U0RBR;
}

int main() {
    unsigned char buffer[50];
	unsigned char ch;
	int i;
	UART0_CONFIG();
	LCD_INIT();
	while(1)
	{
		i=0;
		while(1)
		{
		ch=UART0_RX();
		if(ch=='\r')
		{
		LCD_COMMAND(0x01);
		LCD_COMMAND(0x80);
		LCD_STR(buffer);
		}
		else
		buffer[i++]=ch;
		}
		}
}
