#include<avr/io.h>
#include<avr/interrupt.h>
volatile uint8_t count;
main()
{
DDRB=0b111111111;
TCCR0=0b00000101;

TIMSK |=(1<<TOIE0);
TCNT0=0;
count=0;
sei();
while(1);
}
ISR(TIMER0_OVF_vect)
{
if(count==230)        
{
PORTB=~PORTB;
count=0;
}
else
count++;
}

