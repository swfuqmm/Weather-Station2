#include "Delay.h"

/********ÑÓÊ±º¯Êý**********/ 
void delay_us(int n)     //1us 
{     
  while(n--)
  {          
    _asm(nop);         
    _asm(nop);         
    _asm(nop);          
    _asm(nop);          
    _asm(nop);     
  } 
}


void delay_10us(int n)         //10us 
{     
  int x;     
  while(n--) 
  {
    
    for(x=0;x<26;x++)     
    {       
     _asm(nop);       
     _asm(nop);       
     _asm(nop);      
     _asm(nop);       
     _asm(nop);       
     _asm(nop);     
    } 
  }
}

void delay_ms( uint z)     //1ms 
{ 
  int x;     
  while(z--) 
  {
    
    for(x=0;x<1000;x++)     
    {       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);       
    _asm(nop);  _asm(nop);  _asm(nop);  _asm(nop);      
     _asm(nop);  _asm(nop);      
     } 
   }
 } 