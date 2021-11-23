#include "../inc/interrupt_vectors.h"
#include "STM32.h"
#include "STM32F103C8T.h"
//------------------------------------------------------------------------
#define STACK_TOP 0x20005000
//------------------------------------------------------------------------
extern unsigned int _ROM_DATA_START;	//declared in ld file
extern unsigned int _RAM_DATA_START;	//declared in ld file
extern unsigned int _RAM_DATA_STOP;		//declared in ld file
extern unsigned int _BSS_DATA_START;	//declared in ld file
extern unsigned int _BSS_DATA_STOP;		//declared in ld file
//------------------------------------------------------------------------
// reservation FLASH for interrupt vector
// set interrupt array values to function
//------------------------------------------------------------------------
functionPointer_T __attribute__ ((section(".interrupt_vectors"))) myvectors[76]=
{ 
	(functionPointer_T)STACK_TOP, //0x0000_0000
	Reset_Interrupt,			//0x0000_0004
	NMI_Interrupt,				//0x0000_0008
	HardFault_Interrupt,		//0x0000_000C
	MemManage_Interrupt,		//0x0000_0010
	BusFault_Interrupt,			//0x0000_0014
	UsageFault_Interrupt,		//0x0000_0018
	Reserved_01_Interrupt,		//0x0000_001C
	Reserved_02_Interrupt,		//0x0000_0020
	Reserved_03_Interrupt,		//0x0000_0024
	Reserved_04_Interrupt,		//0x0000_0028
	SVCall_Interrupt,			//0x0000_002C
	DebugMonitor_Interrupt,
	Reserved_05_Interrupt,
	PendSV_Interrupt,
	SysTick_Interrupt,
	WWDG_Interrupt,
	PVD_Interrupt,
	TAMPER_Interrupt,
	RTC_Interrupt,
	FLASH_Interrupt,
	RCC_Interrupt,
	EXTI0_Interrupt,
	EXTI1_Interrupt,
	EXTI2_Interrupt,
	EXTI3_Interrupt,
	EXTI4_Interrupt,
	DMA1_Channel1_Interrupt,
	DMA1_Channel2_Interrupt,
	DMA1_Channel3_Interrupt,
	DMA1_Channel4_Interrupt,
	DMA1_Channel5_Interrupt,
	DMA1_Channel6_Interrupt,
	DMA1_Channel7_Interrupt,
	ADC1_2_Interrupt,
	USB_HP_CAN_TX_Interrupt,
	USB_LP_CAN_RX0_Interrupt,
	CAN_RX1_Interrupt,
	CAN_SCE_Interrupt,
	EXTI9_5_Interrupt,
	TIM1_BRK_Interrupt,
	TIM1_UP_Interrupt,
	TIM1_TRG_COM_Interrupt,
	TIM1_CC_Interrupt,
	TIM2_Interrupt,
	TIM3_Interrupt,
	TIM4_Interrupt,
	I2C1_EV_Interrupt,
	I2C1_ER_Interrupt,
	I2C2_EV_Interrupt,
	I2C2_ER_Interrupt,
	SPI1_Interrupt,
	SPI2_Interrupt,
	USART1_Interrupt,
	USART2_Interrupt,
	USART3_Interrupt,
	EXTI15_10_Interrupt,
	RTC_Alarm_Interrupt,
	USBWakeUp_Interrupt,
	TIM8_BRK_Interrupt,
	TIM8_UP_Interrupt,
	TIM8_TRG_COM_Interrupt,
	TIM8_CC_Interrupt,
	ADC3_Interrupt,
	FSMC_Interrupt,
	SDIO_Interrupt,
	TIM5_Interrupt,
	SPI3_Interrupt,
	UART4_Interrupt,
	UART5_Interrupt,
	TIM6_Interrupt,
	TIM7_Interrupt,
	DMA2_Channel1_Interrupt,
	DMA2_Channel2_Interrupt,
	DMA2_Channel3_Interrupt,
	DMA2_Channel4_5_Interrupt
};

//------------------------------------------------------------------------
void __attribute__((weak)) Reset_Interrupt(void)
{
	//-----------------------------------------
	// copy data from FLASH to RAM - initial values
	//-----------------------------------------
		unsigned int* _ROM_data_start_address = &_ROM_DATA_START;
		unsigned int* _RAM_data_start_address = &_RAM_DATA_START;
		unsigned int* _RAM_data_stop_address = &_RAM_DATA_STOP;

		while(_RAM_data_start_address != _RAM_data_stop_address)
		{
			*_RAM_data_start_address = *_ROM_data_start_address;
			_RAM_data_start_address++;
			_ROM_data_start_address++;
		}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//-----------------------------------------
	// set RAM values to 0
	//-----------------------------------------
		unsigned int * _BSS_data_start_address = &_BSS_DATA_START;
		unsigned int * _BSS_data_stop_address = &_BSS_DATA_STOP;

		while(_BSS_data_start_address != _BSS_data_stop_address)
		{
			*_BSS_data_start_address = 0;
			_BSS_data_start_address++;
		}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//-----------------------------------------
	// run main
	//-----------------------------------------
		main();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};
//------------------------------------------------------------------------
void __attribute__((weak)) NMI_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) HardFault_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) MemManage_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) BusFault_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) UsageFault_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) Reserved_01_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) Reserved_02_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) Reserved_03_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) Reserved_04_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) SVCall_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DebugMonitor_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) Reserved_05_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) PendSV_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) SysTick_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) WWDG_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) PVD_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TAMPER_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) RTC_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) FLASH_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) RCC_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI0_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI1_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI4_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel1_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel4_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel5_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel6_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA1_Channel7_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) ADC1_2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) USB_HP_CAN_TX_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) USB_LP_CAN_RX0_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) CAN_RX1_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) CAN_SCE_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI9_5_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM1_BRK_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM1_UP_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM1_TRG_COM_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM1_CC_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM4_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) I2C1_EV_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) I2C1_ER_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) I2C2_EV_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) I2C2_ER_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) SPI1_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) SPI2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) USART1_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) USART2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) USART3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) EXTI15_10_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) RTC_Alarm_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) USBWakeUp_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM8_BRK_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM8_UP_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM8_TRG_COM_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM8_CC_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) ADC3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) FSMC_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) SDIO_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM5_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) SPI3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) UART4_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) UART5_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM6_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) TIM7_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA2_Channel1_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA2_Channel2_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA2_Channel3_Interrupt(void)
{
};
//------------------------------------------------------------------------
void __attribute__((weak)) DMA2_Channel4_5_Interrupt(void)
{
};
//------------------------------------------------------------------------
