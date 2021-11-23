#include "systick.h"
//----------------------------------------------------------------------------------------------------
unsigned long long int SysTicCounter=0;
systick SysTick;
//----------------------------------------------------------------------------------------------------
void SysTick_Interrupt(void)
{
	SysTick.inc();
}
//----------------------------------------------------------------------------------------------------
systick::systick()
{
	//--------------------
	// Set SysTick_Regs to memory location
	//--------------------
		systick_regs=(systick_TypeDef*)systick_Address;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// reset SysTickValue
	//--------------------
		SysTickCounter=0;
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
void systick::init()
{
	//--------------------
	// Set SysTick_Regs to memory location
	//--------------------
		systick_regs=(systick_TypeDef*)systick_Address;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// reset SysTickValue
	//--------------------
		SysTickCounter=0;
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
void systick::set()
{
	systick_regs->STCSR=7;
	systick_regs->STRVR=8000;//1125;
	systick_regs->STCVR=0;
}
//----------------------------------------------------------------------------------------------------
void systick::inc()
{
	SysTickCounter++;
}
//----------------------------------------------------------------------------------------------------
void systick::delay(int ms)
{
	unsigned long long int tmp=SysTickCounter;
	while((tmp+ms)>SysTickCounter);
}
//----------------------------------------------------------------------------------------------------