#include "rcc.h"
#include "STM32.h"
//----------------------------------------------------------------------------------------------------
rcc Rcc;
//----------------------------------------------------------------------------------------------------

//--------------------
// constants
//--------------------
	const unsigned long rcc::HSI_RC=8000000; //default clock
//~~~~~~~~~~~~~~~~~~~~

//----------------------------------------------------------------------------------------------------
rcc::rcc()
{
	//--------------------
	// Set RCC_Regs to memory RCC location
	//--------------------
		RCC_regs=(RCC_T*)RCC_Address;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Set HSE frequency
	//--------------------
		HSE_RC=0;
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
void rcc::init(unsigned long HSE)
{
	//--------------------
	// Set RCC_Regs to memory RCC location
	//--------------------
		RCC_regs=(RCC_T*)RCC_Address;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Set HSE frequency
	//--------------------
		HSE_RC=HSE;
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_PLL_Clk()
{
	unsigned long sysclockfreq=0;
	// zalezy od:
	// 1: PLL Source Mux (HSI/2) lub (HSE/X) (PLLSRC:)
	// 2: PLLMul (x2 .. x16) (PLLMUL:)
	if(RCC_regs->CFGR.PLLSRC==0)
	{
		sysclockfreq=HSI_RC/2;
	}
	else
	{
		if(RCC_regs->CFGR.PLLXTPRE=1)
		{
			sysclockfreq=HSE_RC/2;
		}
		else
		{
			sysclockfreq=HSE_RC;
		}
	}

	if(RCC_regs->CFGR.PLLMUL+2<=16)
		sysclockfreq=(RCC_regs->CFGR.PLLMUL+2)*sysclockfreq;
	else
		sysclockfreq=(16)*sysclockfreq;

	return sysclockfreq;
}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_Sys_Clk()
{
	unsigned long prediv=0, pllclk=0, pllmul=0;
	unsigned long sysclockfreq=0;

	switch (RCC_regs->CFGR.SWS)
	{
		//00: HSI oscillator used as system clock
		//01: HSE oscillator used as system clock
		//10: PLL used as system clock
		//11: not applicable

	    case 0:
	    {
	    	// moze byc tylko wewnetrzny oscylator 8MHz
	    	sysclockfreq=HSI_RC;
	    	break;
	    }
	    case 1:
	    {
	    	// moze byc tylko zewnetrzny oscylator 4-16MHz
	    	sysclockfreq=HSE_RC;
	    	break;
	    }
	    case 2:
	    {
	    	sysclockfreq=Get_PLL_Clk();
	    	break;
	    }
	    case 3:
	    {
	    	sysclockfreq=HSI_RC;
	    	break;
	    }
	}

	return sysclockfreq;
}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_H_Clk()
{
	switch(RCC_regs->CFGR.HPRE)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			return Get_Sys_Clk();
			break;
		case 8:
			return Get_Sys_Clk()/2;
			break;
		case 9:
			return Get_Sys_Clk()/4;
			break;
		case 10:
			return Get_Sys_Clk()/8;
			break;
		case 11:
			return Get_Sys_Clk()/16;
			break;
		case 12:
			return Get_Sys_Clk()/64;
			break;
		case 13:
			return Get_Sys_Clk()/128;
			break;
		case 14:
			return Get_Sys_Clk()/256;
			break;
		case 15:
			return Get_Sys_Clk()/512;
			break;
	}
}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_P_Clk1()
{
	switch(RCC_regs->CFGR.PPRE1)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			return Get_H_Clk();
			break;
		case 4:
			return Get_H_Clk()/2;
			break;
		case 5:
			return Get_H_Clk()/4;
			break;
		case 6:
			return Get_H_Clk()/8;
			break;
		case 7:
			return Get_H_Clk()/16;
			break;
	}
}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_P_Clk2()
{
	switch(RCC_regs->CFGR.PPRE2)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			return Get_H_Clk();
			break;
		case 4:
			return Get_H_Clk()/2;
			break;
		case 5:
			return Get_H_Clk()/4;
			break;
		case 6:
			return Get_H_Clk()/8;
			break;
		case 7:
			return Get_H_Clk()/16;
			break;
	}
}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_Cortex_System_Timer_Clk()
{

}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_APB1_Timer_Clk()
{

}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_APB2_Timer_Clk()
{

}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_ADC_Clk()
{
	switch(RCC_regs->CFGR.ADC_PRE)
	{
		case 0:
			return Get_P_Clk2()/2;
			break;
		case 1:
			return Get_P_Clk2()/4;
			break;
		case 2:
			return Get_P_Clk2()/6;
			break;
		case 3:
			return Get_P_Clk2()/8;
			break;
	}

}
//----------------------------------------------------------------------------------------------------
unsigned long rcc::Get_USB_Clk()
{
	unsigned long tmp=Get_PLL_Clk()*1.5f;
	switch(RCC_regs->CFGR.OTGFSPRE)
	{
		case 0:
				//spraedzicz to 8000*1.1;
			return tmp*1;//*1.5 czek t
			break;
		case 1:
			return Get_PLL_Clk();
			break;
	}
}
//----------------------------------------------------------------------------------------------------
void rcc::clockPortA(state_T state)
{
	RCC_regs->APB2ENR.IOPAEN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockPortB(state_T state)
{
	RCC_regs->APB2ENR.IOPBEN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockPortC(state_T state)
{
	RCC_regs->APB2ENR.IOPCEN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockPortD(state_T state)
{
	RCC_regs->APB2ENR.IOPDEN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockPortE(state_T state)
{
	RCC_regs->APB2ENR.IOPEEN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetPortA()
{
	RCC_regs->APB2RSTR.IOPARST=1;
	RCC_regs->APB2RSTR.IOPARST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetPortB()
{
	RCC_regs->APB2RSTR.IOPBRST=1;
	RCC_regs->APB2RSTR.IOPBRST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetPortC()
{
	RCC_regs->APB2RSTR.IOPCRST=1;
	RCC_regs->APB2RSTR.IOPCRST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetPortD()
{
	RCC_regs->APB2RSTR.IOPDRST=1;
	RCC_regs->APB2RSTR.IOPDRST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetPortE()
{
	RCC_regs->APB2RSTR.IOPERST=1;
	RCC_regs->APB2RSTR.IOPERST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockUSART1(state_T state)
{
	RCC_regs->APB2ENR.USART1EN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockUSART2(state_T state)
{
	RCC_regs->APB1ENR.USART2EN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockUSART3(state_T state)
{
	RCC_regs->APB1ENR.USART3EN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockUART4(state_T state)
{
	RCC_regs->APB1ENR.UART4EN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::clockUART5(state_T state)
{
	RCC_regs->APB1ENR.UART5EN=state;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetUSART1()
{
	RCC_regs->APB2RSTR.USART1RST=1;
	RCC_regs->APB2RSTR.USART1RST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetUSART2()
{
	RCC_regs->APB1RSTR.USART2RST=1;
	RCC_regs->APB1RSTR.USART2RST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetUSART3()
{
	RCC_regs->APB1RSTR.USART3RST=1;
	RCC_regs->APB1RSTR.USART3RST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetUART4()
{
	RCC_regs->APB1RSTR.UART4RST=1;
	RCC_regs->APB1RSTR.UART4RST=0;
}
//----------------------------------------------------------------------------------------------------
void rcc::resetUART5()
{
	RCC_regs->APB1RSTR.UART5RST=1;
	RCC_regs->APB1RSTR.UART5RST=0;
}
//----------------------------------------------------------------------------------------------------
