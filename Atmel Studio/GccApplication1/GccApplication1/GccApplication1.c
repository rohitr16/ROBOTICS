/*
 * GccApplication1.c
 *
 * Created: 08-07-2015 12:08:05
 *  Author: ROHIT
 */ 


#include <avr/io.h>
#include <util/delay.h>

 unsigned char buffer[11];
 unsigned char bufferi[11];
 void ADC_init(void);
 int ADC_read(uint8_t ch);
 unsigned int cmd(unsigned int cd)
 {
	 PORTD=cd;
	 PORTC=(0<<PC0)|(0<<PC1)|(1<<PC2);
	 
	 PORTC=(0<<PC0)|(0<<PC1)|(0<<PC2);
	 return ;
 }
 unsigned int dat(unsigned int dt)
 {
	 PORTD=dt;
	 PORTC=(1<<PC0)|(0<<PC1)|(1<<PC2);
	 
	 PORTC=(1<<PC0)|(0<<PC1)|(0<<PC2);
	 return ;
 }

  main(void)
{
	int value1=0,value2=0;
	int i,j=0;
	DDRA=0x00;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0xFF;
	cmd(0x38);
	_delay_ms(100);
	cmd(0x01);
	_delay_ms(100);
	cmd(0x0E);
	_delay_ms(100);
	cmd(0x06);
	_delay_ms(100);
	
	ADC_init();
	
    while(1)
    {
         
		 value1=ADC_read(0);
		 value2=ADC_read(1);
		 sprintf(buffer,"VALUE1:%d",value1);
		  while(i<11)
		{	 
			 dat(buffer[i]);
			 i++;
			 _delay_ms(1);
		 }
		 i=0;
		 cmd(0xC0);
		  sprintf(bufferi,"VALUE2:%d",value2);
		  while(j<11)
		  {
			  dat(bufferi[j]);
			  j++;
			  _delay_ms(1);
		  }
		  _delay_ms(500);
		 cmd(0x01);
		 j=0;
		 if(value1>650 && value2>650)
		 {
			 PORTB=0b11111111;
		 }
		 if(value1>650 && value2<650)
		 {
			 PORTB=0b00001111;
		 }
		 if(value1<650 && value2>650)
		 {
			 PORTB=0b11110000;
		 }
		 if(value1<650 && value2<650)
		 {
			 PORTB=0b00000000;
		 }		 
    }
}
 void ADC_init(void)
 {
	 ADMUX = (1<<REFS0);
	 ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
 }
 
  int ADC_read(uint8_t ch)
 {
	 
	 ADC=0;
	 ch= ch&0b00000111;
	 ADMUX = ADMUX & 0b11100000;
	 ADMUX |= ch; 
	 ADCSRA |=(1<<ADSC);
	 while(!(ADCSRA&(1<<ADIF)));
	 ADCSRA |= (1<<ADIF);
	 return(ADC);
	 
 }