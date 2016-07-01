/*
 * GccApplication4.c
 *
 * Created: 02-08-2015 22:31:42
 *  Author: ROHIT
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xFF;
    while(1)
    {
        PORTC=0b10000001;
		_delay_ms(1000);
		PORTC=0b00000000;
		_delay_ms(500); 
    }
}