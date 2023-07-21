#include<at89c5131.h>
#include<stdio.h>
#include<stdlib.h>
#include "lcd.h"

code unsigned char display_msg1[]="Prod1=";
code unsigned char display_msg2[]="Time1=";
long unsigned int x ;
long unsigned int y ;
long unsigned int x1 , x0 , y1 , y0 , z0 , z1 , z2 , z3 ;
long unsigned int z;
int i ;
char product[10];
int k , ki;
int usec ; 
char display_time[5];
void main()
{
	lcd_init();
	TMOD = 0x01;
	TH0 = 0x00;
	TL0 = 0x00 ;
	x = 14571 ;
y = 8636 ;
	TR0 = 1;

x1 = x/10 ;
x0 = x%10 ;
y1 = y/10 ;
y0 = y%10 ;
z0 = x0*y0 ;
z1 = x0*y1 ;
z2 = x1*y0 ;
z3 = x1*y1 ;
z = z0 + (z1 + z2)*10 + z3*100  ;
TR0 = 0 ;    //stop timer
	for(k=9 ; k>=0 ; k--)
	{
	 product[k] = z%10 + '0';
		z = z/10;
	}
	usec = (256*TH0 + TL0)/2; 
	for(ki = 4 ; ki>=0 ; ki--)
	{
	display_time[ki] = usec%10 + '0';
		usec /= 10; 
	}
	
	lcd_cmd(0x80);    //Move Cursor to first row
	lcd_write_string(display_msg1);
	lcd_write_string(product);
	lcd_cmd(0xC0);
	lcd_write_string(display_msg2);
	lcd_write_string(display_time);
	lcd_write_char('u');
	lcd_write_char('s');

	
	while(1);

}
