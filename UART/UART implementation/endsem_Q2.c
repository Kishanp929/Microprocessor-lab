#include<at89c5131.h>
#include<stdio.h>
#include<stdlib.h>
#include "lcd.h"
#include "serial.h"

unsigned char scarcity[4] = { '5' , '5' , '8' ,'6'  };
void main()
{
	unsigned char ch;
	unsigned char cha;
	unsigned char chb;
	unsigned char quantity;
	unsigned char quantity2;
   uart_init();
	
	
		initial_state1:
		initial_state2:
	transmit_string(" \r\n");
	transmit_string("Resources available: DSO-");
		transmit_char(scarcity[0]);
		transmit_string("AFG-");
		transmit_char(scarcity[1]);
		transmit_string("DMM-");
    transmit_char(scarcity[2]);
		transmit_string("DPS-");
		transmit_char(scarcity[3]);
	transmit_string(" \r\n");
		
		transmit_string("Press I for Issue and R for Return\r\n");
		
		ch = receive_char();
		if(ch == 'I' || ch == 'i')
		{
		transmit_string("Enter Resource to be borrowed:\r\n");
			cha = receive_char();
			transmit_string("Enter quantity:\r\n");
			quantity = receive_char();			
			if(cha == '1')
			{
			if(scarcity[0] < quantity)
			{
				 transmit_string("Requested resource not available...");
			}	
      else 
      {
				transmit_string("Requested resource allocated!");
				scarcity[0] = scarcity[0] - quantity + '0';
       }	
			}
			
			else if(cha == '2')
			{
			if(scarcity[1] < quantity)
			{
				 transmit_string("Requested resource not available...");
			}	
      else 
      {
				transmit_string("Requested resource allocated!");
				scarcity[1] = scarcity[1] - quantity + '0';
       }	
			}
			
						else if(cha == '3')
			{
			if(scarcity[2] < quantity)
			{
				 transmit_string("Requested resource not available...");
			}	
      else 
      {
				transmit_string("Requested resource allocated!");
				scarcity[2] = scarcity[2] - quantity + '0';
       }	
			}
			
				else if(cha == '4')
			{
			if(scarcity[3] < quantity)
			{
				 transmit_string("Requested resource not available...");
			}	
      else 
      {
				transmit_string("Requested resource allocated!");
				scarcity[3] = scarcity[3] - quantity + '0';
       }	
			}
			
			goto initial_state1;
			
			
			
		}
		else if(ch = 'R' || ch == 'r')
		{
			transmit_string("Enter Resource to be returned:\r\n");
			chb = receive_char();
			transmit_string("Enter quantity:\r\n");
			quantity2 = receive_char();
		
			if(chb == '1')
			{
				if(scarcity[0] == '5')
				{
					transmit_string("You can’t return what you don’t have...");
				}
				else 
				{
				transmit_string("Returned resource received!");
					scarcity[0] = scarcity[0] + quantity2 - '0';
				}
				
			}
			
			else if(chb == '2')
			{
				if(scarcity[1] == '5')
				{
					transmit_string("You can’t return what you don’t have...");
				}
				else 
				{
				transmit_string("Returned resource received!");
					scarcity[1] = scarcity[1] + quantity2 - '0';
				}
				
			}
			
			else if(chb == '3')
			{
				if(scarcity[2] == '8')
				{
					transmit_string("You can’t return what you don’t have...");
				}
				else 
				{
				transmit_string("Returned resource received!");
					scarcity[2] = scarcity[2] + quantity2 - '0';
				}
				
			}
			
			else if(chb == '4')
			{
				if(scarcity[3] == '6')
				{
					transmit_string("You can’t return what you don’t have...");
				}
				else 
				{
				transmit_string("Returned resource received!");
					scarcity[3] = scarcity[3] + quantity2 - '0';
				}
				
			}
			goto initial_state2 ;
			
		
		}
		
	
	
	
	
	while(1);
	
}

