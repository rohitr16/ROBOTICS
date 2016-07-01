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

    DDRA = 0xFF;
	int i,n=1,g=0;
	while(1)
	{
		if(n==1 && g==0)
		{
			for(i=1;i<=7;i++)
		 {
             PORTA=n; 
			 n=n*2;			
			 _delay_ms(500);
			 if(n==128)
			 {
				 g=1;
			 }
			
		 }
		 if(n==128 && g==1)
		 for(i=1;i<=7;i++)
		 {
			 PORTA=n;
			 n=n/2;
			 _delay_ms(500);
			 if(n==1)
			 {
				 g=0;
			 }
		}
	  }				 
	}
	// Insert application code here, after the board has been initialized.
}
