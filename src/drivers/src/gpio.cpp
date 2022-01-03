#include "gpio.h"
#include "STM32.h"
//----------------------------------------------------------------------------------------------------
gpio::gpio(GPIO_Port_Address_T Port_Address, GPIO_PIN_T GPIO_Pin, GPIO_MODE_T mode, bool set_active) {
	Port = (GPIO_Port_S*) Port_Address;
	Pin = GPIO_Pin;
	setMode(mode);
	if( set_active ) {
		set();
	} else {
		reset();
	}
}
//----------------------------------------------------------------------------------------------------
void gpio::init(GPIO_Port_Address_T Port_Address, GPIO_PIN_T GPIO_Pin, GPIO_MODE_T mode, bool set_active) {
	Port = (GPIO_Port_S*) Port_Address;
	Pin = GPIO_Pin;
	setMode(mode);
	if( set_active ) {
		set();
	} else {
		reset();
	}
}
//----------------------------------------------------------------------------------------------------
void gpio::toggle() {
	if ( (Port != (GPIO_Port_S*) GPIO_Port_NULL) && (Pin != GPIO_PIN_NULL) ) {
		Port->ODR ^= (1 << Pin);
	}
}
//----------------------------------------------------------------------------------------------------
void gpio::set() {
	if( (Port != (GPIO_Port_S*)GPIO_Port_NULL) && (Pin != GPIO_PIN_NULL) ) {
		Port->BSRR = (1 << Pin);
	}
}
//----------------------------------------------------------------------------------------------------
void gpio::reset() {
	if( (Port != (GPIO_Port_S*)GPIO_Port_NULL) && (Pin != GPIO_PIN_NULL) ) {
		Port->BRR = (1 << Pin);
	}
}
//----------------------------------------------------------------------------------------------------
void gpio::setMode(GPIO_MODE_T mode) {
	// musz� wstawic wartosc mode na odpowiednia pozycje
	// liczba mode to 4 bity
	// pin0 to pierwsze 4 bity 0,1,2,3 w CRL
	// pin1 to 4,5,6,7 bity w CRL
	// ..
	// pin8 to pierwsze 4 bity 0,1,2,3 ale w CRH
	// pin9 to 4,5,6,7 bity w CRH
	// ..
	// czyli mam wartosc MODE i musze przesun�c o 0 dla pin0 o 4 dla pin1 o 8 dla pin2 itd a� do 7 a potem od 0 ale w CRH

	if ( (Port != (GPIO_Port_S*) GPIO_Port_NULL) && (Pin != GPIO_PIN_NULL) ) {
		if ( Pin < 8 ) {
			Port->CRL |= (mode << (Pin << 2)); 				// zmieniam tylko te bity ktore odpowiadaja za dany pin reszta rejestru pozostaje bez zmian dlatego OR
		} else {
			Port->CRH |= (mode << ( (Pin - 8) << 2 )); 	// zmieniam tylko te bity ktore odpowiadaja za dany pin reszta rejestru pozostaje bez zmian dlatego OR
		}
	}
}
//----------------------------------------------------------------------------------------------------

