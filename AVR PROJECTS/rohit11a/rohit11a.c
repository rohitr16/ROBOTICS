#include<avr/io.h>
main()
{
int x,f=1,g=1;
DDRB=0b00011110;
while(1)
{
x=PINB&0b00000001;
if(x==0b00000001 && f==1)
{
g=0;
while((PINB&0b00000001)!=0b00000000)
{
PORTB=0b00000010;
}
PORTB=0b00010010;
}
if(x==0b00000000 && g==1)
{
f=0;
while((PINB&0b00000001)!=0b00000001)
{
PORTB=0b00010000;
}
PORTB=0b00010010;
}
}
}
