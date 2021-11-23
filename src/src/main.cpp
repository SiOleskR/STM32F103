#include "main.h"

#include "afio.h"
#include "gpio.h"
#include "rcc.h"
#include "systick.h"
#include "STM32.h"
#include "crc.h"
#include "usart.h"
#include "utility.h"
#include "interrupt.h"
//----------------------------------------------------------------------------------------------------
int main(void)
{
	//--------------------
	// First must be configure clock
	//--------------------
		Rcc.init(8000000);
		Rcc.clockPortA(enable);
		Rcc.clockUSART1(enable);
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia systick
	//--------------------
		SysTick.init();
		SysTick.set();
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
		gpio LedGreenPin(GPIO_Port_A,GPIO_PIN_8,GPIO_Output_PushPull_2MHz_Mode);
		gpio LedRedPin(GPIO_Port_A,GPIO_PIN_11,GPIO_Output_PushPull_2MHz_Mode);
	//~~~~~~~~~~~~~~~~~~~~

	LedGreenPin.set();
	LedRedPin.set();

	while(1)
	{
		int speed=500;
		string napis={"rafal"};
		unsigned char napis2[]={'R','A','F','A','L',0x00};

		SysTick.delay(speed);
		LedGreenPin.reset();
		LedRedPin.set();
		SysTick.delay(speed);
		LedGreenPin.set();
		LedRedPin.reset();
		SysTick.delay(speed);
		LedGreenPin.reset();
		LedRedPin.reset();
		SysTick.delay(speed);
		LedGreenPin.set();
		LedRedPin.set();
		//uart1.write(napis,sizeof(napis));
		uart1.write(napis2);
	}
}



