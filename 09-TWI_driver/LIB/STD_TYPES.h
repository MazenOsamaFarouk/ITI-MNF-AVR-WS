/*
 * STD_TYPE.h
 *
 *  Created on: Jul 29, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 *	   Version: V02 Agu 24, 2020
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#ifndef NULL
#define NULL   ((void*)0)
#endif

typedef unsigned char u8;        //standrad type 
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f96;
//---------------
typedef const u8 ku8; //type of ku8 as constant type of u8typedef unsigned char u8;
typedef const u16 ku16;
typedef const u32 ku32;
typedef const s8 ks7;
typedef const s16 ks16;
typedef const s32 ks32;
typedef const f32 kf32;
typedef const f64 kf64;
typedef const f96 kf96;
//----------------

typedef u8  *pu8; //type of pu8 / *pu8 as *pointer type of u8typedef unsigned char u8;
typedef u16 *pu16;
typedef u32 *pu32;
typedef s8  *ps7;
typedef s16 *ps16;
typedef s32 *ps32;
typedef f32 *pf32;
typedef f64 *pf64;
typedef f96 *pf96;

//----------------

#define NULL  ((void*)0)
#endif /* STD_TYPES_H_ */
