#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRD=0b11111110;
DDRB=0b00011110;
PORTB=0b00011110;
int x;
while(1)
{
for(x=0;x<=9;x++)
{
switch(x)
{
case 0:PORTD=0b11111100;
       _delay_ms(1000);
        break;
case 1:PORTD=0b01100000;
       _delay_ms(1000);
	    break;
case 2:PORTD=0b11011010;
       _delay_ms(1000);
	    break;
case 3:PORTD=0b11110010;
       _delay_ms(1000);
	    break;
case 4:PORTD=0b01100110;
       _delay_ms(1000);
	    break;
case 5:PORTD=0b10110110;
       _delay_ms(1000);
	    break;
case 6:PORTD=0b10111110;
       _delay_ms(1000);
	    break;
case 7:PORTD=0b11100000;
       _delay_ms(1000);
	    break;
case 8:PORTD=0b11111110;
       _delay_ms(1000);
	   break;
case 9:PORTD=0b11110110;
       _delay_ms(1000);
	   break;
}
}
}
}
