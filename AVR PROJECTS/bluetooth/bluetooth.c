#include <avr/io.h>
#include <util/delay.h>
#include"lcd_16.h" 
#include"lcd_16.c" 



int i=0;
 
void wait(float x)
{
for(i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}

void USARTInit(uint16_t ubrr_value)
{
/*
Baud rate = 9600
Data bits =8
Parity = None
Stop bits = 1
Flow Control = None
Transmission Mode = Asynchronous
USART Reciever = ON
USART Transmitter = ON
U2X = 0
UBRR value = 77

ATMega16 Calibrated Internal RC Oscilator Frequency = 8 MHz

*/




   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);
   UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);


   UCSRB=(1<<RXEN)|(1<<TXEN);


}

unsigned char USARTReadChar()
{

  while(!(UCSRA & (1<<RXC)));
    return UDR;
}

void USARTWriteChar(char data)
{

   while(!(UCSRA & (1<<UDRE)));
    UDR=data;
 
}

char buffer[5];

 main()
{
unsigned char data;
DDRB=0b00011110;


   USARTInit(77);  

lcd_init(LCD_DISP_ON);
   while(1)
   {


      data=USARTReadChar();
	  if(data=='w')
	  {
	  PORTB=0b00010010;
	  lcd_clrscr();
	  lcd_puts("'w' received");
	 USARTWriteChar(data);
	  lcd_puts("\nsending w");
	  wait(.1);
	  }

	 if(data=='a')
	  {
	  PORTB=0b00010000;
	  lcd_clrscr();
	  lcd_puts("'a' received");
	  USARTWriteChar(data);
	  lcd_puts("\nsending a");
	  wait(.1);
	 
	  }

	if(data=='d')
	  {
	  PORTB=0b00000010;
	  lcd_clrscr();
	  lcd_puts("'d' received");
	 USARTWriteChar(data);
	  lcd_puts("\nsending d");
	  wait(.1);
	  }
 
	if(data=='x')
	  {
	  PORTB=0b00001100;
	  lcd_clrscr();
	  lcd_puts("'x' received");
	  USARTWriteChar(data);
	  lcd_puts("\nsending x");
	  wait(.1);
	  }

	if(data=='s')
	  {
	  PORTB=0b00011000;
	  lcd_clrscr();
	  lcd_puts("'s' received");
	  USARTWriteChar(data);
	  lcd_puts("\nsending s");
	  wait(.1);
	  }
	}
}
