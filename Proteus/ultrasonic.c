#include<avr/io.h>
#include<util/delay.h>
#include"lcd_16.h"
#include"lcd_16.c"
#define tar 1
void main()         
{
      char buff[6];       
      unsigned int x;
      TCNT1=0;            
      TCCR1A=0x00;
      lcd_init(LCD_DISP_ON);
while(1)
     {
          lcd_gotoxy(0,0);
          lcd_puts("distance=");
          DDRC=0b11111111;
		  PORTC=0x00;
		  _delay_us(10);
		  PORTC=0x01;
		  _delay_us(15);
		  PORTC=0x00;
		  _delay_ms(20);
		  DDRC=0x00;
       TCNT1=0;
        while((PINC&tar)==0);  
        TCCR1A=0x00;
        TCCR1B=0x01;        
         while((PINC&tar)==1); 
         x=TCNT1;              
         x=x/58;
         lcd_gotoxy(9,0);
         sprintf(buff,"%4d",x);
         lcd_puts(buff);  
         lcd_puts("cm");
          _delay_ms(10);
}   }

