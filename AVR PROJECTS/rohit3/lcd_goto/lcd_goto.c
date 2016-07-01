#include<avr/io.h>
#include"lcd_16.c"
#include"lcd_16.h"
#include<util/delay.h>
main()
{
int i,j;
lcd_init(LCD_DISP_ON);
lcd_clrscr();
lcd_puts("ROHIT\nRANJAN");
while(1)
{
for(i=1;i<=10;i++)
{
lcd_command(LCD_MOVE_DISP_RIGHT);
_delay_ms(5000);
}
i=1;
for(j=16;j>=7;j--)
{
lcd_command(LCD_MOVE_DISP_LEFT);
}
j=16;
}
}

