#ifndef _SCI_H
#define _SCI_H

#include <hidef.h>           /* common defines and macros */ 
#include "derivative.h"      /* derivative-specific definitions */

void SCI_Init(void);
void SCI_Send(unsigned char data);
void SCI_PutStr(char *putchar);
unsigned char SCI_Rev(void);

#define   BUS_CLOCK  32000000
#define   BAUD       4800

#endif