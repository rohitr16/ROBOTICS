#include<avr/io.h>
#include<util/delay.h>
main()
{
int x;
DDRB=0b00011110;
DDRC=0b11110110;
while(1)
{
x=PINC&0b00001001;
if(x==0b00000000)
{
PORTB=0b00010010;
}
if(x==0b00001000)
{
PORTB=0b00001100;
_delay_ms(10000);
PORTB=0b00011010;
_delay_ms(10000);
_delay_ms(10000);
}
if(x==0b00000001)
{
PORTB=0b00001100;
_delay_ms(10000);
PORTB=0b00010000;
_delay_ms(10000);
_delay_ms(10000);
}
if(x==0b00001001)
{
PORTB=0b00001100;
_delay_ms(10000);
PORTB=0b00011010;
_delay_ms(10000);
_delay_ms(10000);
}
}
}
