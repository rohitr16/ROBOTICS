#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include"lcd_16.h"
#include"lcd_16.c"

char buffer[5];


int ReadADC(uint8_t ch)
{
   //ADC=0;
   //Select ADC Channel ch must be 0-7
   //ADMUX = ADMUX & 0b11100000;
   ch=ch&0b00000111;
   ADMUX|=ch;

   //Start Single conversion
   ADCSRA |= (1<<ADSC);

   //Wait for conversion to complete
   while(!(ADCSRA&(1<<ADIF)));

   //Clear ADIF by writing one to it
   //Note you may be wondering why we have write one to clear it
   //This is standard way of clearing bits in io as said in datasheets.
   //The code writes '1' but it result in setting bit to '0' !!!

   ADCSRA|=(1<<ADIF);

   return(ADC);
}

void initADC()
{
ADMUX=(1<<REFS0);  // For Aref=AVcc;
ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1) |(1<<ADPS1); //Prescalar div factor =128
}


void wait(float x)
{
int i;
for(i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}


int main()
{

DDRA=0x00;
lcd_init(LCD_DISP_ON);
lcd_clrscr();
lcd_puts("ADC:");
int reading=0,temperature=0;
initADC();

int x;
DDRD = 0xFF;
while(1)
{




reading=ReadADC(0);

temperature=reading/2;

lcd_gotoxy(0,0);

sprintf(buffer,"Temperature: %3d",temperature);

lcd_puts(buffer);

wait(.1);

}
return 0; 
}

