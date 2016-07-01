#include<avr/io.h>
#include<util/delay.h>
main()
{
int x,i;
DDRB=0b11111111;
for(i=1;i<=2;i++)
{
PORTB=i;
_delay_ms(10000);
x=4*i;
PORTB=x;
_delay_ms(10000);
}
}
