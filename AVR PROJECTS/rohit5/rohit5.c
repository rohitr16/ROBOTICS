#include<avr/io.h>
main()
{
DDRB=0b11111110;
int f=0,x,c=0;
while(1)
{ x=PINB&0b00000001;
if(x==0b00000001 && f==0)
f=1;
if(x==0b00000000 && f==1)
{
c=c+1;
f=0;
PORTB=c;
}
}
}
