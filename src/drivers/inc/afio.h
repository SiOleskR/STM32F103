#ifndef AFIO_H
	#define AFIO_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	//----------------------------------------------------------------------------------------------------
	#define AFIO_Address (DEVICES_Address+0x00010000)
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		AFIO_PORT_A=0,
		AFIO_PORT_B=1,
		AFIO_PORT_C=2,
		AFIO_PORT_D=3,
		AFIO_PORT_E=4
	}T_AFIO_PORT;
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		AFIO_PIN_0=1,
		AFIO_PIN_1=2,
		AFIO_PIN_2=3,
		AFIO_PIN_3=4,
		AFIO_PIN_4=5,
		AFIO_PIN_5=6,
		AFIO_PIN_6=7,
		AFIO_PIN_7=8,
		AFIO_PIN_8=9,
		AFIO_PIN_9=10,
		AFIO_PIN_10=11,
		AFIO_PIN_11=12,
		AFIO_PIN_12=13,
		AFIO_PIN_13=14,
		AFIO_PIN_14=15,
		AFIO_PIN_15=16
	}T_AFIO_PIN;
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_EVCR
	{
		volatile unsigned long
			reserved:24,
			EVOE:1,
			PORT:3,
			PIN:4;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_MAPR
	{
		volatile unsigned long
			reserved1:5,
			SWJ_CFG:3,
			reserved2:3,
			ADC2_ETRGREG_REMAP:1,
			ADC2_ETRGINJ_REMAP:1,
			ADC1_ETRGREG_REMAP:1,
			ADC1_ETRGINJ_REMAP:1,
			TIM5CH4_IREMAP:1,
			PD01_REMAP:1,
			CAN_REMAP:2,
			TIM4_REMAP:1,
			TIM3_REMAP:2,
			TIM2_REMAP:2,
			TIM1_REMAP:2,
			USART3_REMAP:2,
			USART2_REMAP:1,
			USART1_REMAP:1,
			I2C1_REMAP:1,
			SPI1_REMAP:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_EXTICR1
	{
		volatile unsigned long
			reserved:16,
			EXTI3:4,
			EXTI2:4,
			EXTI1:4,
			EXTI0:4;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_EXTICR2
	{
		volatile unsigned long
			reserved:16,
			EXTI7:4,
			EXTI6:4,
			EXTI5:4,
			EXTI4:4;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_EXTICR3
	{
		volatile unsigned long
			reserved:16,
			EXTI11:4,
			EXTI10:4,
			EXTI9:4,
			EXTI8:4;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_EXTICR4
	{
		volatile unsigned long
			reserved:16,
			EXTI15:4,
			EXTI14:4,
			EXTI13:4,
			EXTI12:4;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_AFIO_MAPR2
	{
		volatile unsigned long
			reserved1:21,
			FSMC_NADV:1,
			TIM14_REMAP:1,
			TIM13_REMAP:1,
			TIM11_REMAP:1,
			TIM10_REMAP:1,
			TIM9_REMAP:1,
			reserved2:5;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_GPIO_AFIO
	{
		T_AFIO_EVCR EVCR;
		T_AFIO_MAPR MAPR;
		T_AFIO_EXTICR1 EXTICR1;
		T_AFIO_EXTICR2 EXTICR2;
		T_AFIO_EXTICR3 EXTICR3;
		T_AFIO_EXTICR4 EXTICR4;
		T_AFIO_MAPR2 MAPR2;

	};
	//----------------------------------------------------------------------------------------------------
	class afio
	{
		private:
			T_GPIO_AFIO* AFIO_regs;
		public:
			afio();
			void setEVCR(bool enabled,T_AFIO_PORT port,T_AFIO_PIN pin);
	};
	//----------------------------------------------------------------------------------------------------	
#endif
