#ifndef INTERRUPT_H
	#define INTERRUPT_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	#include "utility.h"
	//----------------------------------------------------------------------------------------------------
	#define EXTI_Address (DEVICES_Address+0x00010400)
	//----------------------------------------------------------------------------------------------------
	struct EXTI_IMR_T
	{
		volatile unsigned long
			MR0:1,
			MR1:1,
			MR2:1,
			MR3:1,
			MR4:1,
			MR5:1,
			MR6:1,
			MR7:1,
			MR8:1,
			MR9:1,
			MR10:1,
			MR11:1,
			MR12:1,
			MR13:1,
			MR14:1,
			MR15:1,
			MR16:1,
			MR17:1,
			MR18:1,
			MR19:1,
			reserved:12;
	};
	//----------------------------------------------------------------------------------------------------
	struct EXTI_EMR_T
	{
		volatile unsigned long
			MR0:1,
			MR1:1,
			MR2:1,
			MR3:1,
			MR4:1,
			MR5:1,
			MR6:1,
			MR7:1,
			MR8:1,
			MR9:1,
			MR10:1,
			MR11:1,
			MR12:1,
			MR13:1,
			MR14:1,
			MR15:1,
			MR16:1,
			MR17:1,
			MR18:1,
			MR19:1,
			reserved:12;
	};
	//----------------------------------------------------------------------------------------------------
	struct EXTI_RTSR_T
	{
		volatile unsigned long
			TR0:1,
			TR1:1,
			TR2:1,
			TR3:1,
			TR4:1,
			TR5:1,
			TR6:1,
			TR7:1,
			TR8:1,
			TR9:1,
			TR10:1,
			TR11:1,
			TR12:1,
			TR13:1,
			TR14:1,
			TR15:1,
			TR16:1,
			TR17:1,
			TR18:1,
			TR19:1,
			reserved:12;
	};
	//----------------------------------------------------------------------------------------------------
	struct EXTI_FTSR_T
	{
		volatile unsigned long
			TR0:1,
			TR1:1,
			TR2:1,
			TR3:1,
			TR4:1,
			TR5:1,
			TR6:1,
			TR7:1,
			TR8:1,
			TR9:1,
			TR10:1,
			TR11:1,
			TR12:1,
			TR13:1,
			TR14:1,
			TR15:1,
			TR16:1,
			TR17:1,
			TR18:1,
			TR19:1,
			reserved:12;
	};
	//----------------------------------------------------------------------------------------------------
	struct EXTI_SWIER_T
	{
		volatile unsigned long
			SWIER0:1,
			SWIER1:1,
			SWIER2:1,
			SWIER3:1,
			SWIER4:1,
			SWIER5:1,
			SWIER6:1,
			SWIER7:1,
			SWIER8:1,
			SWIER9:1,
			SWIER10:1,
			SWIER11:1,
			SWIER12:1,
			SWIER13:1,
			SWIER14:1,
			SWIER15:1,
			SWIER16:1,
			SWIER17:1,
			SWIER18:1,
			SWIER19:1,
			reserved:12;
	};
	//----------------------------------------------------------------------------------------------------
	struct EXTI_PR_T
	{
		volatile unsigned long
			PR0:1,
			PR1:1,
			PR2:1,
			PR3:1,
			PR4:1,
			PR5:1,
			PR6:1,
			PR7:1,
			PR8:1,
			PR9:1,
			PR10:1,
			PR11:1,
			PR12:1,
			PR13:1,
			PR14:1,
			PR15:1,
			PR16:1,
			PR17:1,
			PR18:1,
			PR19:1,
			reserved:12;
	};
	//----------------------------------------------------------------------------------------------------
	struct INTERRUPT_T
	{
		EXTI_IMR_T IMR;
		EXTI_EMR_T EMR;
		EXTI_RTSR_T RTSR;
		EXTI_FTSR_T FTSR;
		EXTI_SWIER_T SWIER;
		EXTI_PR_T PR;
	};
	//----------------------------------------------------------------------------------------------------
	class interrupt_T
	{
		private:
		INTERRUPT_T* interrupt_regs;
		public:
		interrupt_T();
		void init();
	};
	//----------------------------------------------------------------------------------------------------
	extern interrupt_T interrupt;
#endif
