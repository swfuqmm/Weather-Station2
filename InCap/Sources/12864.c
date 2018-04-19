#include "12864.h"

/********检测忙位**********/ 
void Check_Busy(void) 
{      
  DDRA=0x00;               //置总线为读入     
  asm(nop);     
  asm(nop);     
  RS=0;     
  RW=1;     
  EN=1;     
  while((DataPort&0x80)==0x80);//忙则等待     
  EN=0;     
  DDRA=0xFF;               //置总线为输出 
} 
/********写命令**********/ 
void write_com(unsigned char Cmd) 
{ 	
  Check_Busy(); 	
  RS=0; 	
  RW=0; 
  EN=1; 	
  DataPort=Cmd; 	
  delay_10us(1); 	
  EN=0; 	
  delay_10us(3); 
} 
/********写数据**********/  
void write_date(unsigned char Data) 
{ 	
  Check_Busy(); 	
  RS=1; 	
  RW=0; 	
  EN=1; 	
  DataPort=Data; 	
  delay_10us(1); 	
  EN=0; 	
  delay_10us(3);
} 
/******液晶屏初始化******/ 
void LCD_Init(void) 
{          
  PSB=1;    
  delay_ms(50);           //大于40MS的延时程序    
  write_com(0x30);       //选择基本指令集    
  delay_10us(12);         //延时大于100us    
  write_com(0x30);       //选择8bit数据流    
  delay_10us(4);         //延时大于37us    
  write_com(0x0c);       //开显示(无游标、不反白)    
  delay_10us(12);         //延时大于100us    
  write_com(0x01);       //清除显示，并且设定地址指针为00H   
  delay_ms(12);          //延时大于10ms    
  write_com(0x06);       //指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位，光标从右向左加1位移动    
  delay_10us(12);           //延时大于100us    
 } 
 /******显示字符******/  
 void DisplayCGRAM(uchar x,uchar y) 
 {   
   switch(x)      
   { 	  
     case 1: write_com(0x80+y);break; 	  
     case 2: write_com(0x90+y);break; 	  
     case 3: write_com(0x88+y);break; 	  
     case 4: write_com(0x98+y);break;       
     default:break; 	 
   }    
  write_date(1);     
  write_date(1);  
 }           
 /***********************************************                    
     显示字符串 
 x:横坐标值，范围0~8 
 y:纵坐标值，范围1~4 
 ************************************************/ 
void LCD_PutString(unsigned char x,unsigned char y,unsigned char *s) 
{  
 switch(x)      
  { 	  
    case 1: write_com(0x80+y);break; 	  
    case 2: write_com(0x90+y);break; 	 
    case 3: write_com(0x88+y);break; 	  
    case 4: write_com(0x98+y);break;       
    default:break; 	
  } 
   
    while(*s>0)    
    {        
      write_date(*s);       
      s++;       
      delay_10us(5);    
    } 
}  
/******清屏******/ 
void ClrScreen(void) 
{  
  write_com(0x01); 
  delay_ms(5);    
}
/******显示字符串******/ 
void Display_W(char *character,uchar len) 
{   
  uchar i;   
  for(i=0;i<len;i++)   
  {     
    write_date(character[i]);   
  } 
}
 /******显示数据******/ 
void Display_D_temp(uint data,uchar len) 
{   
  uchar i;   
  for(i=0;i<len;i++)   
  {     
    write_date(data);   
  } 
}

void xianshihuanhang(uchar x)//补空格函数，输入量为所需空格数 
{   
  uint i_xshh=0;   
  for(;i_xshh<x;i_xshh++)
  {     
    Display_D_temp(32,1);  
  } 
}  
/******显示字符串******/ 
void  Display(uchar *character,uchar len) 
{   
  uchar i;   
  for(i=0;i<len;i++)  
  {     
    write_date(character[i]);   
  } 
}