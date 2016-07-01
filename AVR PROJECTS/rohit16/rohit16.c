#include<avr/io.h>
#include<util/delay.h>
main()
{
int x,num=1,ones=0,tens=0;
DDRD=0b11111111;
DDRB=0b00011110;
while(num<=99)
{
ones=num%10;
tens=(num/10)%10;
switch(ones)
{
case 0:PORTD=0b11111100;
        _delay_ms(8);
		break;
case 1:PORTD=0b01100000;
	    _delay_ms(8);
		break;
case 2:PORTD=0b11011010;
		_delay_ms(8);
		break;
case 3:PORTD=0b11110010;
		_delay_ms(8);
		break;
case 4:PORTD=0b01100110;
		_delay_ms(8);
		break;
case 5:PORTD=0b10110110;
	    _delay_ms(8);
		break;
case 6:PORTD=0b10111110;
		_delay_ms(8);
		break;
case 7:PORTD=0b11100000;
		_delay_ms(8);
		break;
case 8:PORTD=0b11111110;
	   _delay_ms(8);
	   break;
case 9:PORTD=0b11110110;
	   _delay_ms(8);
	   break;
}
PORTB=0b00000010;
_delay_ms(700);
switch(tens)
{
case 0:PORTD=0b11111100;
        _delay_ms(10);
		break;
case 1:PORTD=0b01100000;
	    _delay_ms(10);
		break;
case 2:PORTD=0b11011010;
	    _delay_ms(10);
		break;
case 3:PORTD=0b11110010;
	    _delay_ms(10);
		break;
case 4:PORTD=0b01100110;
		_delay_ms(10);
		break;
case 5:PORTD=0b10110110;
	    _delay_ms(10);
		break;
case 6:PORTD=0b10111110;
	    _delay_ms(10);
		break;
case 7:PORTD=0b11100000;
		_delay_ms(10);
		break;
case 8:PORTD=0b11111110;
	   _delay_ms(10);
	   break;
case 9:PORTD=0b11110110;
	   _delay_ms(10);
	   break;
}
PORTB=0b00000100;
_delay_ms(700);
PORTB=0b00000110;
num++;
}
}
