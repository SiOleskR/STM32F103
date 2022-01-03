#include "main.h"

#include "afio.h"
#include "gpio.h"
#include "rcc.h"
#include "systick.h"
#include "STM32.h"
#include "crc.h"
#include "usart.h"
#include "utility.h"
#include "exti.h"
#include "nvic.h"
#include "usb.h"
//----------------------------------------------------------------------------------------------------
gpio LedRedPin;
gpio LedGreenPin;
gpio LedUserPin;
//----------------------------------------------------------------------------------------------------
int main(void) {
	//--------------------
	// First must be configure clock
	//--------------------
	rcc.init(8000000);
	rcc.clockPortA(enable);
	rcc.clockPortC(enable);
	rcc.clockUSART1(enable);
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia systick
	//--------------------
	SysTick.init();
	SysTick.set();
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia nvic
	//--------------------
	nvic.init();
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia crc
	//--------------------
	Crc.init();
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia uart1
	//--------------------
	uart1.init(USART1_Address,USART_9600);
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia GPIO
	//--------------------
	LedGreenPin.init(GPIO_Port_A, GPIO_PIN_8, GPIO_Output_PushPull_2MHz_Mode, true);
	LedRedPin.init(GPIO_Port_C, GPIO_PIN_15, GPIO_Output_PushPull_2MHz_Mode, true);
	LedUserPin.init(GPIO_Port_C, GPIO_PIN_13, GPIO_Output_PushPull_2MHz_Mode, true);
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia USB -> HID
	//--------------------
	usb.init();
	//~~~~~~~~~~~~~~~~~~~~
	
	long mig = 1000000;
	while (true) {
		if ( mig == 10000) {
			LedUserPin.reset();
		}
		if ( --mig == 0) {
			mig = 1000000;
			LedUserPin.set();
		}
	}
}



