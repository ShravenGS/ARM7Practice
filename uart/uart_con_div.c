#include"uart_driver.h"
#define LEDs (0xFF)
void delay(unsigned int ms){
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x03;
	T0TCR=0x00;
}

void LED_CON(void){
	int i;
	

	 for(i=0;i<=3;i++){
	 IOCLR0=((1<<(3-i))|(1<<(3+i)));
	 delay(500);
	 IOSET0=((1<<(3-i))|(1<<(3+i)));
	}
}

void LED_DIV(void){
	int i;

	 for(i=3;i>=0;i--){
	 IOSET0=((1<<(3-i))|(1<<(3+i)));
	 delay(500);
	 IOCLR0=((1<<(3-i))|(1<<(3+i)));
	}
}

int main(){
	UART0_CONFIG();
	IODIR0=(LEDs<<2);
	IOSET0=(LEDs<<2);

	while(1){
	unsigned char ch;
	 ch=UART0_RX();
	 if(ch=='1'){
	 LED_CON();
	 }

	 else if(ch=='2'){
	 LED_DIV();
	 }
	}
 }



