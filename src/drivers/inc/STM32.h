#ifndef STM32_H
	#define STM32_H	
	//------------------------------------------------------------------------
	#define FLASH_Address 	0x08000000
	#define RAM_Address   	0x20000000
	#define DEVICES_Address	0x40000000
	//------------------------------------------------------------------------
	#define NULLbit	0x00
	#define bit0	0x01
	#define bit1	0x02
	#define bit2	0x04
	#define bit3	0x08
	#define bit4	0x10
	#define bit5	0x20
	#define bit6	0x40
	#define bit7	0x80
	#define bit8	0x100
	#define bit9	0x200
	#define bit10	0x400
	#define bit11	0x800
	#define bit12	0x1000
	#define bit13	0x2000
	#define bit14	0x4000
	#define bit15	0x8000
	#define bit16	0x10000
	#define bit17	0x20000
	#define bit18	0x40000
	#define bit19	0x80000
	#define bit20	0x100000
	#define bit21	0x200000
	#define bit22	0x400000
	#define bit23	0x800000
	#define bit24	0x1000000
	#define bit25	0x2000000
	#define bit26	0x4000000
	#define bit27	0x8000000
	#define bit28	0x10000000
	#define bit29	0x20000000
	#define bit30	0x40000000
	#define bit31	0x80000000
	//----------------------------------------------------------------------------------------------------
	#define PIN_NULL	0
	#define PIN_0 		1
	#define PIN_1		2
	#define PIN_2		3
	#define PIN_3		4
	#define PIN_4		5
	#define PIN_5		6
	#define PIN_6		7
	#define PIN_7		8
	#define PIN_8		9
	#define PIN_9		10
	#define PIN_10		11
	#define PIN_11		12
	#define PIN_12		13
	#define PIN_13		14
	#define PIN_14		15
	#define PIN_15 		16
	//----------------------------------------------------------------------------------------------------
	typedef void (*functionPointer_T)(void);
	typedef unsigned int* memPointer_T;
	typedef enum {disabled=0,disable=0,enabled=1,enable=1}state_T;
	//----------------------------------------------------------------------------------------------------
#endif
