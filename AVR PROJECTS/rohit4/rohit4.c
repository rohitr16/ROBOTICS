#include<avr/io.h>
int main()
{
DDRB=0b11111111;
DDRC=0b11111110;
int f=1;
int x;
int c=0;
while(1)
{ x=PINC&0b00000001;
if((x==0b00000001) && f==1)
{
f=0;
}
x=PINC&0b00000001;
if((x==0b00000000) && f==0)
{
c=c+1;
f=1;
PORTB=2*c;
}
}
}
