#ifndef GPIO_H
	#define GPIO_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		GPIO_Port_NULL = 0x00000000UL,
		GPIO_Port_A = (DEVICES_Address + 0x00010800),
		GPIO_Port_B = (DEVICES_Address + 0x00010C00),
		GPIO_Port_C = (DEVICES_Address + 0x00011000),
		GPIO_Port_D = (DEVICES_Address + 0x00011400),
		GPIO_Port_E = (DEVICES_Address + 0x00011800),
		GPIO_Port_F = (DEVICES_Address + 0x00011C00),
		GPIO_Port_G = (DEVICES_Address + 0x00012000)
	}GPIO_Port_Address_T;
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		GPIO_PIN_NULL = 32,
		GPIO_PIN_0 = 0,
		GPIO_PIN_1 = 1,
		GPIO_PIN_2 = 2,
		GPIO_PIN_3 = 3,
		GPIO_PIN_4 = 4,
		GPIO_PIN_5 = 5,
		GPIO_PIN_6 = 6,
		GPIO_PIN_7 = 7,
		GPIO_PIN_8 = 8,
		GPIO_PIN_9 = 9,
		GPIO_PIN_10 = 10,
		GPIO_PIN_11 = 11,
		GPIO_PIN_12 = 12,
		GPIO_PIN_13 = 13,
		GPIO_PIN_14 = 14,
		GPIO_PIN_15 = 15
	}GPIO_PIN_T;
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		GPIO_Input_Analog_Mode = 0x00,
		GPIO_Input_Floating_Input_Mode = 0x04,
		GPIO_Input_Pull_Mode = 0x08,

		GPIO_Output_PushPull_10MHz_Mode = 0x01,
		GPIO_Output_PushPull_2MHz_Mode = 0x02,
		GPIO_Output_PushPull_50MHz_Mode = 0x03,

		GPIO_Output_OpenDrain_10MHz_Mode = 0x05,
		GPIO_Output_OpenDrain_2MHz_Mode = 0x06,
		GPIO_Output_OpenDrain_50MHz_Mode = 0x07,

		GPIO_Output_Alternate_10MHz_PushPull_Mode = 0x09,
		GPIO_Output_Alternate_2MHz_PushPull_Mode = 0x0A,
		GPIO_Output_Alternate_50MHz_PushPull_Mode = 0x0B,

		GPIO_Output_Alternate_10MHz_OpenDrain_Mode = 0x0D,
		GPIO_Output_Alternate_2MHz_OpenDrain_Mode = 0x0E,
		GPIO_Output_Alternate_50MHz_OpenDrain_Mode = 0x0F

		//wartosc 0x0C - zarezerwowana
	}GPIO_MODE_T;
	//----------------------------------------------------------------------------------------------------
	struct GPIO_Port_S
	{
		volatile unsigned long CRL;	//Offset 0x00 mode config
		volatile unsigned long CRH; 	//Offset 0x04 mode config
		volatile unsigned long IDR; 	//Offset 0x08 Input Data Register
		volatile unsigned long ODR; 	//Offset 0x0C Output Data Register
		volatile unsigned long BSRR;	//Offset 0x10 bit set/reset register 0-15 bit set, 16-31 bit reset, set 1 in bit will be set/reset gpio pin
		volatile unsigned long BRR; 	//Offset 0x14 bit reset register 0-15 bit reset set 1 in bit will be reset gpio pin
		volatile unsigned long LCKR;	//Offset 0x18 configuration lock register 0-15 bit lock config for CRL/CRH 16 bit sequence to lock
	};
	
	//----------------------------------------------------------------------------------------------------
	class gpio
	{
		private:
			GPIO_Port_S* Port;
			GPIO_PIN_T Pin;
		public:
			gpio(GPIO_Port_Address_T Port_Address=GPIO_Port_NULL, GPIO_PIN_T GPIO_Pin=GPIO_PIN_NULL, GPIO_MODE_T mode=GPIO_Input_Floating_Input_Mode, bool set_active = false);
			void init(GPIO_Port_Address_T Port_Address=GPIO_Port_NULL, GPIO_PIN_T GPIO_Pin=GPIO_PIN_NULL, GPIO_MODE_T mode=GPIO_Input_Floating_Input_Mode, bool set_active = false);
			void setMode(GPIO_MODE_T mode);
			void toggle();
			void set();
			void reset();
	};
	//----------------------------------------------------------------------------------------------------
#endif
