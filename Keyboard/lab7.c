	
//    P3.4  R1      1      2      3      A
//    P3.5  R2      4      5      6      B
//    P3.6  R3      7      8      9      C
//    P3.7  R4      *      0      #      D
//                  C1     C2     C3     C4
//                P3.3   P3.2   P3.1   P3.0
#include<at89c5131.h>
#include<stdio.h>
#include<stdlib.h>
#include "lab7.h"
code unsigned char display_msg1[]="ENTER PASSWORD :";
code unsigned char display_msg2[]=" ACCESS GRANTED ";
code unsigned char display_msg3[]="  ACCESS DENIED ";
unsigned char a ;
unsigned char b;
unsigned char c;
int i;
int j;
int column;
char password_store[4][4] = { {'A' , '3' , '2' , '1'}  , {'B' , '6' , '5' , '4'} , {'C' , '9' , '8' , '7'} , {  'D'  , '#', '0' , '*'}    } ; 
char password[9];

	int m;
	int w;
void main()
{
	lcd_init();
	lcd_cmd(0x80);
	msdelay(4);
	lcd_write_string(display_msg1);
	for(w = 0 ; w<8 ; w++)
	{
	 //start
	   
     P3 = 0x00 ;
JUMP:  P3 = 0x0F ;  // set columns to take input
       a = P3;
	   while( a != 0x0F)
		{
    P3 = 0x0F;
		a = P3;
	}
	//checked if previously pressed key is released
	P3 = 0x0F;
	a = P3;
	while(a == 0x0F)
	{ 
	
		P3 = 0x0F;
		a = P3;
	}
	msdelay(20);
	
	P3 = 0x0F;
	a = P3;
	if(a == 0x0F)
	{
     goto JUMP ;	
	}
	c = 0xEF;
	for(m=0 ; m<4 ; m++)
	{
	P3 = c;
	a = P3 ;
	a  =  a & 0x0F;
	for(j = 0 ; j<4 ; j++)
{
   b = a & 0x01;
	a = a >> 1;
	if(b == 0)
	{
		column = j;
	  break;
	}
	if(j == 3)
	{
	 column = 5;
	
	}
	
}


if(column < 4 )
{
   password[w] = password_store[m][column];
	password[w+1] = '\0';
	lcd_cmd(0xC0);
	lcd_write_string(password) ;
	break;
}

c = c & 0x7f ;
c = c << 1;
c = c | 0x0F;
	}
	
	

	
	
}
	

if(password[0] == '1' && password[1] == '5' && password[2] == 'A' && password[3] == '8' && password[4] == '*' && password[5] == 'D' && password[6] == '6' && password[7] == '#')
{
   lcd_cmd(0x80);	//Move cursor to first line
	 lcd_write_string(display_msg2);
}
else
{
	 lcd_cmd(0x80);	//Move cursor to first line
lcd_write_string(display_msg3);
}



while(1);
	}
	
	
	


	
	
	