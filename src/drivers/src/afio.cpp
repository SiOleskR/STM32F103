#include "../inc/afio.h"

#include "STM32.h"
//----------------------------------------------------------------------------------------------------
afio::afio()
{
	//--------------------
	// Set AFIO_regs to memory AFIO location
	//--------------------
		AFIO_regs=(T_GPIO_AFIO*)AFIO_Address;
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
void afio::setEVCR(bool enabled,T_AFIO_PORT port,T_AFIO_PIN pin)
{
	AFIO_regs->EVCR.EVOE=enabled;
	AFIO_regs->EVCR.PORT=port;
	AFIO_regs->EVCR.PIN=pin;
}
//----------------------------------------------------------------------------------------------------
