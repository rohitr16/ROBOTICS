#include<avr/io.h>
main()
{
int x,f=0,g=0;
DDRB=0b00011110;
DDRC=0b11110110;
while(1)
{
x=PINC&0b00001001;
if(x==0b00001001)
PORTB=0b00010010;
if(x==0b00001000)
{
if(x==0b00001000 && f==0)
{
PORTB=0b00010000;
f=1;
}
if(x==0b00000000 && f==1)
{
PORTB=0b00011010;
f=0;
}
}
if(x==0b00000001)
{
if(x==0b00000001 && g==0)
{
PORTB=0b00011010;
g=1;
}
if(x==0b00000000 && g==1)
{
PORTB=0b00010000;
g=0;
}
}
if(x==0b00000000)
PORTB=0b00000000;
}
}
