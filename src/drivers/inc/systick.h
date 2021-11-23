#ifndef systick_H
	#define systick_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	//----------------------------------------------------------------------------------------------------
	#define systick_Address (0xE000E010)
	//----------------------------------------------------------------------------------------------------
	struct systick_TypeDef
	{
		volatile unsigned long STCSR;	//Offset 0x00 Reset value 0x0000 0000	RW
		volatile unsigned long STRVR;	//Offset 0x04 Reset value Unknown		RW
		volatile unsigned long STCVR;	//Offset 0x08 Reset value Unknown		RW
		volatile unsigned long STCR;	//Offset 0x0C Reset value STCALIB		RO
	};
	//--------------------------------------------------------------------------------
	class systick
	{
		private:
			systick_TypeDef* systick_regs;
			unsigned long long int SysTickCounter;
		public:
			systick();
			void init();
			void set();
			void inc();
			void delay(int ms);
	};
	//----------------------------------------------------------------------------------------------------
	extern systick SysTick;
	//----------------------------------------------------------------------------------------------------
#endif
