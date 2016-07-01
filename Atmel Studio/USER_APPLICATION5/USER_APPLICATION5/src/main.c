/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <avr/io.h>
#include <util/delay.h>

main (void)
{
	DDRA=0xFF;
	int n=1;
	while(1)
	{
		
		
		PORTA=0xFF;
		_delay_ms(500);
		for(n=1;n<=8;n++)
	    {
			PORTA=(<<n);
			_delay_ms(500);
		}		
		
	}
}
