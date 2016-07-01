/**
 * \file
 * \brief Empty user application template
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_16.h"
#include "lcd_16.c"
#define F_CPU 12000000UL

 void USARTInit(uint16_t val)
{
	UBRRL= val;
	UBRRH = 0;
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB = (1<<RXEN)|(1<<TXEN);
}

 unsigned USARTRead()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}
 void USARTWrite(char data)
 {
	 while(!(UCSRA & (1<<UDRE)));
	 UDR = data;
 }

 uint8_t EEPROMRead(uint16_t address)
 {
	 while(EECR & (1<<EEWE));
	 EEAR=address;
	 EECR|= (1<<EERE);
	 return EEDR;
 }
 void EEPROMWrite(uint16_t address,uint8_t data)
 {
	 while(EECR & (1<<EEWE));
	 EEAR=address;
	 EEDR=data;
	 EECR|= (1<<EEMWE);
	 EECR|= (1<<EEWE);
 }
 
 
 main (void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	unsigned char data;
	unsigned int addr=1,eep=0;
	
	
	USARTInit(51);
	lcd_init(LCD_DISP_ON);
	

	if(EEPROMRead(0)!=255)
	{
	  lcd_putc(EEPROMRead(0));
	  while(EEPROMRead(addr)!=255);
	  lcd_putc(EEPROMRead(addr++));	
	}
	
	lcd_gotoxy(0,0);
	
	while(1)
	{
		data = USARTRead();
		EEPROMWrite(eep++,data);
		lcd_putc(data);
		_delay_ms(1000);
	
   }			
}

