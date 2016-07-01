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
	while(1)
	{
		PORTA=0b01100000;
		_delay_ms(300);
		PORTA=0b00000000;
		_delay_ms(300);
	}

	// Insert application code here, after the board has been initialized.
}
