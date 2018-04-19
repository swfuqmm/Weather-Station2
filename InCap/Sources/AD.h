#ifndef _AD_H
#define _AD_H

#include <hidef.h>           /* common defines and macros */ 
#include "derivative.h"      /* derivative-specific definitions */


void AD_Init(void);
void AD_Sample(void);    //AD������ֵ�˲�
void AD_voctry(void);    //AD������ֵ�˲�
void AD_torque(void);    //AD�������ֵ
void AD_GetValue(int *AD_wValue1, int *AD_wValue2);

#endif