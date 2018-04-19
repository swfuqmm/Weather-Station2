#ifndef _12864_H
#define _12864_H

#include <hidef.h>           /* common defines and macros */ 
#include "derivative.h"      /* derivative-specific definitions */

void Check_Busy(void);
void write_com(unsigned char Cmd);
void write_date(unsigned char Data);
void LCD_Init(void);
void DisplayCGRAM(uchar x,uchar y);
void LCD_PutString(unsigned char x,unsigned char y,unsigned char *s);
void ClrScreen(void);
void Display_W(char *character,uchar len);
void Display_D_temp(uint data,uchar len);
void xianshihuanhang(uchar x);//补空格函数，输入量为所需空格数
void  Display(uchar *character,uchar len);


#define  DataPort PORTA  
#define  RS  PORTB_PB7 //PTS_PTS7 
#define  RW  PORTB_PB6 //PTJ_PTJ7 
#define  EN  PORTB_PB5 //PTJ_PTJ6 
#define  PSB PORTB_PB3 


#endif