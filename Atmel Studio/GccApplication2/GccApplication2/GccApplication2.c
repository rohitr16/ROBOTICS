/*
 * GccApplication2.c
 *
 * Created: 17-07-2015 00:46:47
 *  Author: ROHIT
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1200000UL
#include <math.h>


        

         int powe(int x);

         void wait(float x)
         {
	         for(int i=0;i<(int)(x*1302);i++)
	         _delay_loop_1(0);
         }


         void main()
         {
	         DDRB=0xFF;
	         int i,j,k,p=0;
	         j=1;

	         while(1)
	         {
		         for(i=7;i>=0;i--)
		         {
			         for(k=0;k<=i;k++)
			         {
				         PORTB=p+(1<<k);
				         wait(.5);
			         }
			       p=p+powe(i);  
		         }
		         p=0;
	         }
         }

        int powe(int x)
        {
	        int d=1;
	        for (int i=0;i<x;i++)
	        {
		        d=d*2;
	        }
	        return d;
        } 
    
