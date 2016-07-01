#include<avr/io.h> 				
#include<util/delay.h> 			

int main(void)					
{	
DDRB=0b11111110;  				

int x=0,c=1;            

while(1)          				
	{
	x=(PINB&0b00000001);       
		
	if((x==0b00000001) && (c==1))	      
	{       
	 PORTB=0b00010010;  					
		 	 
    		
			c=0;

		 	_delay_ms(10000);

	}
	x=PINB&0b00000001;     	

	if((x==0b00000001) && (c==0))
	{
	 PORTB=0b00001100;			

	 c=1;

	 _delay_ms(10000);

	}
	
	}


}

