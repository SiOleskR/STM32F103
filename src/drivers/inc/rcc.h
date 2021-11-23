#ifndef RCC_H
	#define RCC_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	//----------------------------------------------------------------------------------------------------
	#define RCC_Address (DEVICES_Address+0x00021000)
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_CR
	{
		volatile unsigned long
			HSION:1,
			HSIRDY:1,
			reserved3:1,
			HSITRIM:5,
			HSICAL:8,
			HSEON:1,
			HSERDY:1,
			HSEBYP:1,
			CSSON:1,
			reserved2:4,
			PLLON:1,
			PLLRDY:1,
			PLL2ON:1,
			PLL2RDY:1,
			PLL3ON:1,
			PLL3RDY:1,
			reserved1:2;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_CFGR
	{
		volatile unsigned long
			SW:2,
			SWS:2,
			HPRE:4,
			PPRE1:3,
			PPRE2:3,
			ADC_PRE:2,
			PLLSRC:1,
			PLLXTPRE:1,
			PLLMUL:4,
			OTGFSPRE:1,
			reserved2:1,
			MCO:4,
			reserved1:4;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_CIR
	{
		volatile unsigned long
			LSIRDYF:1,
			LSERDYF:1,
			HSIRDYF:1,
			HSERDYF:1,
			PLLRDYF:1,
			PLL2RDYF:1,
			PLL3RDYF:1,
			CSSF:1,
			LSIRDYIE:1,
			LSERDYIE:1,
			HSIRDYIE:1,
			HSERDYIE:1,
			PLLRDYIE:1,
			PLL2RDYIE:1,
			PLL3RDYIE:1,
			reserved2:1,
			LSIRDYC:1,
			LSERDYC:1,
			HSIRDYC:1,
			HSERDYC:1,
			PLLRDYC:1,
			PLL2RDYC:1,
			PLL3RDYC:1,
			CSSC:1,
			reserved1:8;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_APB2RSTR
	{
		volatile unsigned long
			AFIORST:1,
			reserved4:1,
			IOPARST:1,
			IOPBRST:1,
			IOPCRST:1,
			IOPDRST:1,
			IOPERST:1,
			reserved3:2,
			ADC1RST:1,
			ADC2RST:1,
			TIM1RST:1,
			SPI1RST:1,
			reserved2:1,
			USART1RST:1,
			reserved1:17;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_APB1RSTR
	{
		volatile unsigned long
			TIM2RST:1,
			TIM3RST:1,
			TIM4RST:1,
			TIM5RST:1,
			TIM6RST:1,
			TIM7RST:1,
			reserved5:5,
			WWDGRST:1,
			reserved4:2,
			SPI2RST:1,
			SPI3RST:1,
			reserved3:1,
			USART2RST:1,
			USART3RST:1,
			UART4RST:1,
			UART5RST:1,
			I2C1RST:1,
			I2C2RST:1,
			reserved2:2,
			CAN1RST:1,
			CAN2RST:1,
			BKPRST:1,
			PWRRST:1,
			DACRST:1,
			reserved1:2;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_AHBENR
	{
		volatile unsigned long
			DMA1EN:1,
			DMA2EN:1,
			SRAMEN:1,
			reserved5:1,
			FLITFEN:1,
			reserved4:1,
			CRCEN:1,
			reserved3:5,
			OTGFSEN:1,
			reserved2:1,
			ETHMACEN:1,
			ETHMACTXEN:1,
			ETHMACRXEN:1,
			reserved1:15;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_APB2ENR
	{
		volatile unsigned long
			AFIOEN:1,
			reserved4:1,
			IOPAEN:1,
			IOPBEN:1,
			IOPCEN:1,
			IOPDEN:1,
			IOPEEN:1,
			reserved3:2,
			ADC1EN:1,
			ADC2EN:1,
			TIM1EN:1,
			SPI1EN:1,
			reserved2:1,
			USART1EN:1,
			reserved1:17;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_APB1ENR
	{
		volatile unsigned long
			TIM2EN:1,
			TIM3EN:1,
			TIM4EN:1,
			TIM5EN:1,
			TIM6EN:1,
			TIM7EN:1,
			TIM12EN:1,
			TIM13EN:1,
			TIM14EN:1,
			reserved5:2,
			WWDGEN:1,
			reserved4:2,
			SPI2EN:1,
			SPI3EN:1,
			reserved3:1,
			USART2EN:1,
			USART3EN:1,
			UART4EN:1,
			UART5EN:1,
			I2C1EN:1,
			I2C2EN:1,
			USBEN:1,
			reserved2:1,
			CAN1EN:1,
			CAN2EN:1,
			BKPEN:1,
			PWREN:1,
			DACEN:1,
			reserved1:2;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_BDCR
	{
		volatile unsigned long
			LSEON:1,
			LSERDY:1,
			LSEBYP:1,
			reserved3:5,
			RTCSEL:2,
			reserved2:5,
			RTCEN:1,
			BDRST:1,
			reserved1:15;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_CSR
	{
		volatile unsigned long
			LSION:1,
			LSIRDY:1,
			reserved2:22,
			RMVF:1,
			reserved1:1,
			PINRSTF:1,
			PORRSTF:1,
			SFTRSTF:1,
			IWDGRSTF:1,
			WWDGRSTF:1,
			LPWRRSTF:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_AHBRSTR
	{
		volatile unsigned long
			reserved3:12,
			OTGFSRST:1,
			reserved2:1,
			ETHMACRST:1,
			reserved1:17;
	};
	//----------------------------------------------------------------------------------------------------
	struct T_RCC_CFGR2
	{
		volatile unsigned long
			PREDIV1:4,
			PREDIV2:4,
			PLL2MUL:4,
			PLL3MUL:4,
			PREDIV1SRC:1,
			I2S2SRC:1,
			I2S3SRC:1,
			reserved1:13;
	};
	//----------------------------------------------------------------------------------------------------
	struct RCC_T
	{
		T_RCC_CR CR;				//Offset 0x00 Reset value 0x0000 XX83
		T_RCC_CFGR CFGR;			//Offset 0x04 Reset value 0x0000 0000
		T_RCC_CIR CIR;				//Offset 0x08 Reset value 0x0000 0000
		T_RCC_APB2RSTR APB2RSTR;	//Offset 0x0C Reset value 0x0000 0000
		T_RCC_APB1RSTR APB1RSTR;	//Offset 0x10 Reset value 0x0000 0000
		T_RCC_AHBENR AHBENR;		//Offset 0x14 Reset value 0x0000 0014
		T_RCC_APB2ENR APB2ENR;		//Offset 0x18 Reset value 0x0000 0000
		T_RCC_APB1ENR APB1ENR;		//Offset 0x1C Reset value 0x0000 0000
		T_RCC_BDCR BDCR; 			//Offset 0x20 Reset value 0x0000 0000
		T_RCC_CSR CSR; 				//Offset 0x24 Reset value 0x0C00 0000
		T_RCC_AHBRSTR AHBRSTR;		//Offset 0x28 Reset value 0x0000 0000
		T_RCC_CFGR2 CFGR2;			//Offset 0x2C Reset value 0x0000 0000
	};
	//--------------------------------------------------------------------------------
	class Rcc
	{
		private:
			static const unsigned long HSI_RC;
			unsigned long HSE_RC;
			RCC_T* regs;
		public:
			Rcc();
			void init(unsigned long HSE);

			unsigned long Get_PLL_Clk();
			unsigned long Get_Sys_Clk();
			unsigned long Get_H_Clk();
			unsigned long Get_P_Clk1();
			unsigned long Get_P_Clk2();
			unsigned long Get_Cortex_System_Timer_Clk();
			unsigned long Get_APB1_Timer_Clk();
			unsigned long Get_APB2_Timer_Clk();
			unsigned long Get_ADC_Clk();
			unsigned long Get_USB_Clk();

			void clockPortA(state_T state);
			void clockPortB(state_T state);
			void clockPortC(state_T state);
			void clockPortD(state_T state);
			void clockPortE(state_T state);
			void resetPortA();
			void resetPortB();
			void resetPortC();
			void resetPortD();
			void resetPortE();

			void clockUSART1(state_T state);
			void clockUSART2(state_T state);
			void clockUSART3(state_T state);
			void clockUART4(state_T state);
			void clockUART5(state_T state);
			void clockUSB(state_T state);
			void resetUSART1();
			void resetUSART2();
			void resetUSART3();
			void resetUART4();
			void resetUART5();
	};
	//----------------------------------------------------------------------------------------------------
	extern Rcc rcc;
	//----------------------------------------------------------------------------------------------------
#endif
