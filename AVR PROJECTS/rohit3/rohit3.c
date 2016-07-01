#include <avr/io.h>        // includes input/output header file
#define F_CPU 12000000UL  
#include <util/delay.h>       
#include"lcd_16.h"         
#include"lcd_16.c"
#include<avr/io.h>         


int main (void)            
{
lcd_init(LCD_DISP_ON);     

	while(1)               
	{
	lcd_puts("   Hello World!  ");   
	_delay_ms(50);                   

	for(int i=0;i<15;i++)  
		{
		lcd_command(LCD_MOVE_DISP_LEFT);
		_delay_ms(500);    
		}                  

	lcd_clrscr();  		   
	_delay_ms(50);         

	}                      
    }                     
