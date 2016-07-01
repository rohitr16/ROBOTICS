#include<avr/io.h>
#include<util/delay.h>
 int print_digit(int d)   
	{
	if(d<10)
		{
		switch(d)
{
case 0:PORTD=0b11111100;
       _delay_ms(1000);
        break;
case 1:PORTD=0b01100000;
       _delay_ms(1000);
	    break;
case 2:PORTD=0b11011010;
       _delay_ms(1000);
	    break;
case 3:PORTD=0b11110010;
       _delay_ms(1000);
	    break;
case 4:PORTD=0b01100110;
       _delay_ms(1000);
	    break;
case 5:PORTD=0b10110110;
       _delay_ms(1000);
	    break;
case 6:PORTD=0b10111110;
       _delay_ms(1000);
	    break;
case 7:PORTD=0b11100000;
       _delay_ms(1000);
	    break;
case 8:PORTD=0b11111110;
       _delay_ms(1000);
	   break;
case 9:PORTD=0b11110110;
       _delay_ms(1000);
	   break;
}
		}
	}

main()
{
DDRB=0b00011110; 
DDRD=0b11111111;;
int d,num;    

while(1)    
	{
	for(int i=0;i<=9999;i++)
		{
		for(int j=0;j<50;j++)
			{
			num=i;
			d=(num/1000);
			PORTB=0b00010000;
			print_digit(d);
			_delay_ms(10);
            
			d=(num/100);
			PORTB=0b00001000;
			print_digit(d);
			_delay_ms(10);
			
			d=(num/10);
			PORTB=0b0000100;
			print_digit(d);
			_delay_ms(10);
			
			
			d=(num);
			PORTB=0b00000010;
			print_digit(d);
			_delay_ms(10);
			}
		}
	}  							
}  								
