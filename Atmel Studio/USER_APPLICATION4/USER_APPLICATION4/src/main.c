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
	int i,n=1,g=0,m;
	while(1)
	{
	    if(n==1 && g==0)
		{
			for(i=1;i<=8;i++)
		{ 
			n=n*2;
			m=n-1;
			PORTA=m;
			_delay_ms(500);
			g=1;
		}
	  }		
		if(n==256 && g==1)
		{
		for(i=1;i<=9;i++)
		{
			m=n-1;
			PORTA=m;
			n=n/2;
			_delay_ms(500);
			g=0;
			if(n==0)
			{
				n=1;
			}
		}
	 }		
	}
}
