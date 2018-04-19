#ifndef _AD_H
#define _AD_H

#include <hidef.h>           /* common defines and macros */ 
#include "derivative.h"      /* derivative-specific definitions */


void AD_Init(void);
void AD_Sample(void);    //AD采样中值滤波
void AD_voctry(void);    //AD采样均值滤波
void AD_torque(void);    //AD采样后的值
void AD_GetValue(int *AD_wValue1, int *AD_wValue2);

#endif