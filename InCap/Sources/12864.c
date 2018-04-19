#include "12864.h"

/********���æλ**********/ 
void Check_Busy(void) 
{      
  DDRA=0x00;               //������Ϊ����     
  asm(nop);     
  asm(nop);     
  RS=0;     
  RW=1;     
  EN=1;     
  while((DataPort&0x80)==0x80);//æ��ȴ�     
  EN=0;     
  DDRA=0xFF;               //������Ϊ��� 
} 
/********д����**********/ 
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
/********д����**********/  
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
/******Һ������ʼ��******/ 
void LCD_Init(void) 
{          
  PSB=1;    
  delay_ms(50);           //����40MS����ʱ����    
  write_com(0x30);       //ѡ�����ָ�    
  delay_10us(12);         //��ʱ����100us    
  write_com(0x30);       //ѡ��8bit������    
  delay_10us(4);         //��ʱ����37us    
  write_com(0x0c);       //����ʾ(���αꡢ������)    
  delay_10us(12);         //��ʱ����100us    
  write_com(0x01);       //�����ʾ�������趨��ַָ��Ϊ00H   
  delay_ms(12);          //��ʱ����10ms    
  write_com(0x06);       //ָ�������ϵĶ�ȡ��д��ʱ���趨�α���ƶ�����ָ����ʾ����λ�������������1λ�ƶ�    
  delay_10us(12);           //��ʱ����100us    
 } 
 /******��ʾ�ַ�******/  
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
     ��ʾ�ַ��� 
 x:������ֵ����Χ0~8 
 y:������ֵ����Χ1~4 
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
/******����******/ 
void ClrScreen(void) 
{  
  write_com(0x01); 
  delay_ms(5);    
}
/******��ʾ�ַ���******/ 
void Display_W(char *character,uchar len) 
{   
  uchar i;   
  for(i=0;i<len;i++)   
  {     
    write_date(character[i]);   
  } 
}
 /******��ʾ����******/ 
void Display_D_temp(uint data,uchar len) 
{   
  uchar i;   
  for(i=0;i<len;i++)   
  {     
    write_date(data);   
  } 
}

void xianshihuanhang(uchar x)//���ո�����������Ϊ����ո��� 
{   
  uint i_xshh=0;   
  for(;i_xshh<x;i_xshh++)
  {     
    Display_D_temp(32,1);  
  } 
}  
/******��ʾ�ַ���******/ 
void  Display(uchar *character,uchar len) 
{   
  uchar i;   
  for(i=0;i<len;i++)  
  {     
    write_date(character[i]);   
  } 
}