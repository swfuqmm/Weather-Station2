#include "PIT.h"


/*************************************************************/
/*                          PIT定时                          */
/*************************************************************/
void PIT_Init(void)                    //定时间断初始化函数 1ms定时间断设置 
{
  PITCFLMT_PITE=0;                      //关PIT
  PITCE_PCE0=1;                         //定时器通道0使能 
  PITMTLD0=127;                        //8位定时器初值设定,32分频，在32MHzBusClock下，为1MHz。即1us 
  PITLD0=49999;                       //16位定时器初值设定。50000*0.2us=0.1s 
  PITINTE_PINTE0=1;                     //定时器间断通道0间断使能 
  PITCFLMT_PITE=1;                      //使能PIT 
}
//--------------------通道0输入捕捉初始化-------------------//
void ECT1_Init(void)
{
 /* TSCR2=0X80;
  TIOS_IOS0=0; //设定pt0输入捕捉口
  TCTL4=0X01;
  TIE=0X01;
  TSCR1=0X80; */
  
    TIOS_IOS1 = 0; // channel 0 as INput CAPTURE
    TIE_C1I = 1;  // 使能 channel 0 中断
    
    TCTL4_EDG1A = 1;
    TCTL4_EDG1B = 0;  // 检测上升沿
    
    TSCR1_TFFCA = 1; // 定时器标志位快速清除

    TSCR1_TEN = 1; // 定时器使能位. 1=允许定时器正常工作; 0=使主定时器不起作用(包括计数器)
   // TSCR2=0X80; 
    TSCR2 = 0x07; // 预分频系数pr2-pr0:111,时钟周期为4us,

    TFLG1 = 0xff; // 清除各IC/OC中断标志位

    TFLG2 = 0xff; // 清除自由定时器中断标志位
}

void PAI_Init(void)
{
  PACTL_PAEN=0;//0－16b计数禁止，1允许,先禁止
  PACTL_PAMOD=0;//0－计数模式，1－门时计数模式，设0
  PACTL_PEDGE=0;//0下降沿，1－上升沿，指定有IOC7－PT7口输入，此位受PACTL_PAMOD影响，此设0
  PACTL_CLK1=0;//当计数位外部脉冲，此设置无意义，都设0
  PACTL_CLK0=0;
  PACTL_PAOVI=0;//0－溢出中断禁止，1－允许，本例计数个数有time0时钟中断读取，不需要溢出中断，设0
  PACTL_PAI=0;//0禁止中断，1允许，设0
  PACNT=0;//计数器寄存器的值，可以使0000～FFFF，先清0
  //PAFLG_PAOVF=1;//计数溢出FFFF>0000
  PAFLG_PAIF=1;//脉冲数入1=IOC7-PT7,最大65536个脉冲
  PACTL_PAEN=1;//16b计数允许
}