#include "nvic.h"
//----------------------------------------------------------------------------------------------------
Nvic nvic;
//----------------------------------------------------------------------------------------------------
Nvic::Nvic() {
	regs = (NVIC_REGS_S*) NVIC_Address;
	stir = (NVIC_STIR_S*) NVIC_STIR_Address;
}
//----------------------------------------------------------------------------------------------------
void Nvic::init() {
	regs = (NVIC_REGS_S*) NVIC_Address;
	stir = (NVIC_STIR_S*) NVIC_STIR_Address;
}
//----------------------------------------------------------------------------------------------------
void Nvic::set_priority(IRQ_Position_Table interrupt, IRQ_Priority priority) {
	//regs->IPR[position] = priority;
}
//----------------------------------------------------------------------------------------------------
void Nvic::set_enable(IRQ_Position_Table interrupt) {
	//regs->ISER[ (interrupt / 32) ].r = (1 << (interrupt % 32));
	//regs->ISER[(((unsigned long)interrupt) >> 5UL)].r = (unsigned long)(1UL << (((unsigned long)interrupt) & 0x1FUL));
	regs->ISER[0].r = 0xFFFFFFFF;
	//regs->ISER[1].r = 0xFFFFFFFF;
	//regs->ISER[2].r = 0xFFFFFFFF;
}
//----------------------------------------------------------------------------------------------------
void Nvic::clear_enable(IRQ_Position_Table interrupt) {
	//regs->ICER[ (interrupt / 32) ] |= (1 << (interrupt % 32));
}
//----------------------------------------------------------------------------------------------------
void Nvic::set_pending(IRQ_Position_Table interrupt) {
	//regs->ISPR[ (interrupt / 32) ] |= (1 << (interrupt % 32));
}
//----------------------------------------------------------------------------------------------------
void Nvic::clear_pending(IRQ_Position_Table interrupt) {
	//regs->ICPR[ (interrupt / 32) ] |= (1 << (interrupt % 32));
}
//----------------------------------------------------------------------------------------------------
bool is_active(IRQ_Position_Table interrupt) {
	//return ( regs->IABR[(interrupt / 32)] & (1 << (interrupt % 32)) ) == (1 << (interrupt % 32));
	return false;
}
//----------------------------------------------------------------------------------------------------