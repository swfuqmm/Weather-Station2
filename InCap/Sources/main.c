#include <hidef.h>           /* common defines and macros */ 
#include "derivative.h"      /* derivative-specific definitions */ 
#include <math.h> 
#include <stdlib.h>
#include <stdio.h>


#include "12864.h"
#include "Delay.h"

#include "SCI.h"
#include "PIT.h"
 

char str[10]; 

unsigned short buf[11];
unsigned char flag=0, j = 0;
unsigned int dt0,dt1;
unsigned int time01,time11;
unsigned int time02,time12;
float u8Fre = 0;
/*************************************************************/
/*                      初始化锁相环                         */
/*************************************************************/
void PLL_32M(void)                      //BUS CLOCK = 32MHZ, PLL CLOCK = 64MHZ
{
  CLKSEL &= 0x7f;                       //set OSCCLK as sysclk
  PLLCTL &= 0x8F;                       //Disable PLL circuit   
  CRGINT &= 0xDF;

  SYNR = 0x43;                             
  REFDV = 0x81;                         //PLLCLK=2×OSCCLK×(SYNR+1)/(REFDV+1)＝64MHz ,fbus=32M

  PLLCTL = PLLCTL | 0x70;               //Enable PLL circuit
  asm NOP;
  asm NOP;
  while(!(CRGFLG&0x08));                //PLLCLK is Locked already
  CLKSEL |= 0x80;                       //set PLLCLK as sysclk
}
/********************************************************* * 
主函数                                              
* *********************************************************/  
void main(void)  
{ 
  long interval = 0;

   char i = 0;
   PLL_32M();    
   SCI_Init();
   ECT1_Init();
   flag = 0;  
   j = 0;	
   EnableInterrupts;  

    
   sprintf(str, "%d", 123);
   SCI_PutStr(str);                                              
   for(;;)    
   {       
       
       u8Fre = 1.0 / (4 * dt1) * 1000000;
       sprintf(str, "%f", u8Fre);
       SCI_PutStr(str);
       sprintf (str, "%s", "Hz\t");
       
        SCI_PutStr(str);
 
        delay_ms(100);        
   }  
}
#pragma CODE_SEG  NON_BANKED
void  interrupt 9 capture1_ISR() 
{
    TFLG1_C1F = 1;   //clear channel 0 interrupt flag
    //TIE_C1I = 0;
    time11 = time12;               //记录上一时刻的捕捉值
    time12 = TC1;                 //读取这一次的捕捉值
    dt1= time12-time11;     //计算时间差
    //TIE_C1I = 1;

}

#pragma CODE_SEG DEFAULT
