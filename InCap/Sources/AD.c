#include "AD.h"

/****************AD采样命令*************************/
/*
unsigned char Sample, voctry, torque;

void AD_Init(void) 
{
  ATD0CTL1 = 0X00;     //禁止外部中断，采用前不上电，8 bit data
  ATD0CTL2 = 0X40;     //禁止转换完成中断，快速清零
  ATD0CTL3 = 0X88;     //每个序列1次转换，NO FIFO,Freeze模式下继续 右对齐无符号
  ATD0CTL4 = 0X83;     //8位精度，2个AD转换时间，ATDClock=[BusClokc*0.5]/[PRS+1];PRS=3,divider=8
  ATD0CTL5 = 0X00;     //，单通道采样，通道0
  ATD0DIEN = 0X00;     //禁止数字输入
}


void AD_Sample(void)    //AD采样中值滤波
{

//  ATD0CTL5 =0x20; 
//  ATD0DIEN = 0X00;     //禁止数字输入 
  while (!(ATD0STAT0_SCF)); //等待AD采样完成
  Sample= ATD0DR0L;          //获取AD采样后的值
  }

void AD_voctry(void)//AD采样均值滤波
{
  
  ATD0DIEN = 0X00; 
  ATD0CTL5 =0x21;
  while (!(ATD0STAT0_SCF)); //等待AD采样完成
  voctry= ATD0DR1L;   //获取AD采样后的值
  
}  

void AD_torque(void) //AD采样后的值
{
  
  ATD0CTL5 =0x22;
  ATD0DIEN = 0X00;     //禁止数字输入 
  while (!(ATD0STAT0_SCF)); //等待AD采样完成
  torque= ATD0DR2L; //获取AD采样后的值
  
}
  
 */
 /*************************************************************/
/*                         AD初始化                          */
/*************************************************************/
void AD_Init(void)
{   
   	ATD0CTL1=0x00;                      //8位精度 	        
    ATD0CTL2=0X40;   	                  //快速清除
    ATD0CTL3=0XF8;                      //右对齐 序列16
    ATD0CTL4=0X31;                      //ADclock = 32/(2*(1+1)) = 8M ADclock最大8.3M
}

/*************************************************************/
/*                        AD采集函数                         */
/*************************************************************/

void AD_GetValue(int *AD_wValue1, int *AD_wValue2) 
{
  //  ATD0CTL5=0X00;                      //单次转换 
    ATD0CTL5 = 0X10;                      //多次转换
    while(!(ATD0STAT0_SCF==1));   
    *AD_wValue1 = ATD0DR0; 
    *AD_wValue2 = ATD0DR1;
} 