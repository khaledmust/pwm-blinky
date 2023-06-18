/*
**@file     : common.h
**@brief    : This is header file for common usage macros and definations
**@author   : KHALED MUSTAFA
**@date     : 13 june 2023
**@version  : 0.1
*/


#ifndef COMMON_H_
#define COMMON_H_

/* INCLUDES*/
#include "stdint.h"


/* MACROS*/
#define SUCCESS               (0)
#define ERROR                 (-1)
#define INVALID_INPUT         (-2)
#define NULL                  ((void *)0)
#define HIGH                  (1)
#define LOW                   (0)


#ifndef TRUE                  
#define TRUE                  (1)
#endif                        
											        
#ifndef FALSE                 
#define FALSE                 (0)
#endif                   
											   

/* BIT MATH OPERATIONS*/
#define GET_BIT_STATUS(reg,bit_num) ((reg>>bit_num)&1)
#define SET_BIT(reg,bit_num)        (reg|=(1<<bit_num))
#define CLR_BIT(reg,bit_num)        (reg&=(~(1<<bit_num)))
#define TOGGLE_BIT(reg,bit_num)     (reg^=(1<<bit_num))

#endif
