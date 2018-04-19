#ifndef _DELAY_H
#define _DELAY_H

#include <hidef.h>           /* common defines and macros */ 
#include "derivative.h"      /* derivative-specific definitions */

void delay_us(int n);     //1us 
void delay_10us(int n);         //10us 
void delay_ms( unsigned int z);     //1ms

#endif