#include<avr/io.h>
#include<util/delay.h>
#include"lcd_16.h"
#include"lcd_16.c"
main()
{
int i,j;
lcd_init(LCD_DISP_ON);
while(1)
{
lcd_clrscr();
lcd_putc('R');
lcd_command(LCD_MOVE_DISP_RIGHT);
lcd_gotoxy(0,0);
lcd_putc('O');
}
}
