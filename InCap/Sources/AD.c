#include "AD.h"

/****************AD��������*************************/
/*
unsigned char Sample, voctry, torque;

void AD_Init(void) 
{
  ATD0CTL1 = 0X00;     //��ֹ�ⲿ�жϣ�����ǰ���ϵ磬8 bit data
  ATD0CTL2 = 0X40;     //��ֹת������жϣ���������
  ATD0CTL3 = 0X88;     //ÿ������1��ת����NO FIFO,Freezeģʽ�¼��� �Ҷ����޷���
  ATD0CTL4 = 0X83;     //8λ���ȣ�2��ADת��ʱ�䣬ATDClock=[BusClokc*0.5]/[PRS+1];PRS=3,divider=8
  ATD0CTL5 = 0X00;     //����ͨ��������ͨ��0
  ATD0DIEN = 0X00;     //��ֹ��������
}


void AD_Sample(void)    //AD������ֵ�˲�
{

//  ATD0CTL5 =0x20; 
//  ATD0DIEN = 0X00;     //��ֹ�������� 
  while (!(ATD0STAT0_SCF)); //�ȴ�AD�������
  Sample= ATD0DR0L;          //��ȡAD�������ֵ
  }

void AD_voctry(void)//AD������ֵ�˲�
{
  
  ATD0DIEN = 0X00; 
  ATD0CTL5 =0x21;
  while (!(ATD0STAT0_SCF)); //�ȴ�AD�������
  voctry= ATD0DR1L;   //��ȡAD�������ֵ
  
}  

void AD_torque(void) //AD�������ֵ
{
  
  ATD0CTL5 =0x22;
  ATD0DIEN = 0X00;     //��ֹ�������� 
  while (!(ATD0STAT0_SCF)); //�ȴ�AD�������
  torque= ATD0DR2L; //��ȡAD�������ֵ
  
}
  
 */
 /*************************************************************/
/*                         AD��ʼ��                          */
/*************************************************************/
void AD_Init(void)
{   
   	ATD0CTL1=0x00;                      //8λ���� 	        
    ATD0CTL2=0X40;   	                  //�������
    ATD0CTL3=0XF8;                      //�Ҷ��� ����16
    ATD0CTL4=0X31;                      //ADclock = 32/(2*(1+1)) = 8M ADclock���8.3M
}

/*************************************************************/
/*                        AD�ɼ�����                         */
/*************************************************************/

void AD_GetValue(int *AD_wValue1, int *AD_wValue2) 
{
  //  ATD0CTL5=0X00;                      //����ת�� 
    ATD0CTL5 = 0X10;                      //���ת��
    while(!(ATD0STAT0_SCF==1));   
    *AD_wValue1 = ATD0DR0; 
    *AD_wValue2 = ATD0DR1;
} 