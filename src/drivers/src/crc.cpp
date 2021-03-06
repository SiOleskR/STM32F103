#include "STM32.h"
#include "crc.h"
//----------------------------------------------------------------------------------------------------
crc Crc;
//----------------------------------------------------------------------------------------------------
crc::crc()
{
	crc_regs=(crc_regs_S*) CRC_Address;
}
//----------------------------------------------------------------------------------------------------
void crc::init()
{
	crc_regs=(crc_regs_S*) CRC_Address;
}
//----------------------------------------------------------------------------------------------------
void crc::reset()
{
	crc_regs->CR.reset=1;
}
//----------------------------------------------------------------------------------------------------
void crc::add(unsigned long data)
{
	crc_regs->DR=data;
}
//----------------------------------------------------------------------------------------------------
unsigned long crc::get()
{
	return crc_regs->DR;
}
//----------------------------------------------------------------------------------------------------
