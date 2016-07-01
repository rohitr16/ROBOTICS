#include<avr/io.h>
int main()
{
int x;
DDRB=0b00011110;
DDRC=0b11111110;
while(1)
{
x=PINC&0b00000001;
if(x==0b00000000)                                   
PORTB=0b00010000;
if(x==0b00000001)
PORTB=0b00011010;
}
}

