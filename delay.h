/*Using Timer concept in LPC2129 board*/
typedef unsigned int U32
delay_second(unsigned int s){
T0PR=15000000-1;
T0TCR=0x01;
while(T0PC<s);
T0TCR=0x03;
T0TCR=0x01;
}
delay_millisecond(U32 ms){
T0PR=15000-1;
T0TCR=0x01;
while(T0PC<s);
T0TCR=0x03;
T0TCR=0x01;
}
delay_microsecond(U32 ns){
T0PR=15-1;
T0TCR=0x01;
while(T0PC<s);
T0TCR=0x03;
T0TCR=0x01;
}
