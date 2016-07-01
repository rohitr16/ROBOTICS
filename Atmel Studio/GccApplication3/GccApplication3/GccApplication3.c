/*
 * GccApplication3.c
 *
 * Created: 27-07-2015 17:14:27
 *  Author: ROHIT
 */ 


#include <avr/io.h>
#include <util/delay.h>

  main(void)
{
    DDRB=0b11111111;
	while(1)
    {
		PORTB=0b00001001;
		_delay_ms(1000);
		PORTB=0b00001010;
		_delay_ms(1000);
		PORTB=0b00001100;
		_delay_ms(1000);
		PORTB=0b00000110;
		_delay_ms(1000);
		PORTB=0b00001000;
		_delay_ms(1000);
        
    }
}