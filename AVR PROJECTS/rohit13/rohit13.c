#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file  


/* Program for intelligent Line follower by Robosapiens India using Atmega16 microcontroller*/

//connect the left sensors on CN3 and right one on CN2

void wait(int n)
{
for(int i=0;i<n;i++)
_delay_loop_2(0);
}


int main(void)
{
DDRB=0b00011110; //PORTC as output Port connected to motors
DDRC=0b11110110; //PORTA Input port connected to Sensors


int left_sensor=0, right_sensor=0;
int counter=1;
while(1) // infinite loop
{
     left_sensor=PINC&0b00001000; // mask PA4 bit of Port A
     right_sensor=PINC&0b00000001;// mask PA5 bit of Port A
	 
	 
             if((left_sensor==0b00001000) & (right_sensor==0b00000001)) //if both sensors "on"
              {
                  PORTB=0b00010010; // move straight
               
               }
			      
			if((left_sensor==0b00000000)&(right_sensor==0b00000001))
              {
                  PORTB=0b00010000; // turn left

               }
			                     
								 
			if((left_sensor==0b00001000)&(right_sensor==0b00000000))
              {
                 PORTB=0b00000010; // turn right

				

               }
			 if((left_sensor==0b00000000) & (right_sensor==0b00000000)&(counter==1)) //if both sensors "off"
     {
                 PORTB=0b00010000; // stop
				 wait(.1);
				 counter++;
				 left_sensor=127;  // any illigal value
				 right_sensor=127; // any illigal value
			
      }

	 if((left_sensor==0b00000000) & (right_sensor==0b00000000)&(counter==2)) //if both sensors "off"
     {
                 PORTB=0b00000010; // stop
				 wait(.1);
				 counter++;
				 left_sensor=127;  // any illigal value
				 right_sensor=127; // any illigal value
			
      }


	  if((left_sensor==0b00000000) & (right_sensor==0b00000000)&(counter==3)) //if both sensors "off"
      {
                 PORTB=0b00010000; // stop
				 wait(.1);
				 counter++;
				 left_sensor=127;  // any illigal value
				 right_sensor=127; // any illigal value
			
      }

			  if((left_sensor==0b00000000) & (right_sensor==0b00000000)&(counter==4)) //if both sensors "off"
              {
                 PORTB=0b00010010; // stop
				 wait(.1);
				 counter++;
				 left_sensor=127;  // any illigal value
				 right_sensor=127; // any illigal value
			
               }

			  if((left_sensor==0b00000000) & (right_sensor==0b00000000)&(counter==5)) //if both sensors "off"
              {
                 PORTB=0b00000000; // stop
				 exit(0);
               }



 }
 }

