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
gpio LedRedPin(GPIO_Port_A,GPIO_PIN_11,GPIO_Output_PushPull_2MHz_Mode);
//----------------------------------------------------------------------------------------------------
int main(void)
{
	//--------------------
	// First must be configure clock
	//--------------------
	rcc.init(8000000);
	rcc.clockPortA(enable);
	rcc.clockUSART1(enable);
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
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// inicjalizacjia USB -> HID
	//--------------------
	usb.init();
	//~~~~~~~~~~~~~~~~~~~~

	LedGreenPin.set();
	LedRedPin.set();
	long speed = 1000;

	while(1)
	{
		if(speed-- <= 0)
		{
			speed = 1000000;
			LedGreenPin.toggle();
		}
		
		//string napis={"rafal"};
		//unsigned char napis2[]={'R','A','F','A','L',0x00};
		//SysTick.delay(speed);
		//LedGreenPin.reset();
		//LedRedPin.set();
		
		//uart1.write(napis,sizeof(napis));
		//uart1.write(napis2);
	}
}



