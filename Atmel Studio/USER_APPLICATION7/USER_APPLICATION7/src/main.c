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

unsigned int cmd(unsigned int cd);
unsigned int dat(unsigned int dt);

 main (void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	int i=0,j=0,g=0;
	unsigned char a[7]="DIGNIFY";
	cmd(0x38);
	_delay_ms(100);
    cmd(0x01);
	_delay_ms(100);
	cmd(0x0E);
	_delay_ms(100);
	cmd(0x06);
	_delay_ms(100);
	while(i<7)
	{
		
		dat(a[i]);
		_delay_ms(100);
		i++;
	}
	while(1)
	{
		
	   while(j<9 && g==0)
	   {
		 j++;
		 cmd(0x1C);
		 _delay_ms(100);
		 
	   }
	   g=1;
	   while(j>0 && g==1)
	   {
		 j--;
		 cmd(0x18);
		 _delay_ms(100);
		 
	   }
	   g=0;
	}	 
}

unsigned int cmd(unsigned int cd)
{
	PORTA=cd;
	PORTB=(0<<PB0)|(0<<PB1)|(1<<PB2);
	
	PORTB=(0<<PB0)|(0<<PB1)|(0<<PB2);
	return ;
}
unsigned int dat(unsigned int dt)
{
	PORTA=dt;
	PORTB=(1<<PB0)|(0<<PB1)|(1<<PB2);
	
	PORTB=(1<<PB0)|(0<<PB1)|(0<<PB2);
	return ;
}