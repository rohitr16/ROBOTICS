#include<avr/io.h>
#include"lcd_16.c"
#include"lcd_16.h"
main()
{
lcd_init(LCD_DISP_ON);
lcd_clrscr();
lcd_puts("HELLOW");
}
