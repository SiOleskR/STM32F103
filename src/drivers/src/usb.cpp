#include "usb.h"
#include "STM32.h"
#include "rcc.h"
#include "main.h"
//----------------------------------------------------------------------------------------------------
Usb usb;
//----------------------------------------------------------------------------------------------------
Usb::Usb()
{
	//--------------------
	// Set to memory location
	//--------------------
	USB_regs = (USB_T*) 0x40005C00;
	USB_buffors = (USB_Buffors_T*) 0x40006000;
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
USB_ISTR_T Usb::get_ISTR()
{
	return USB_regs->ISTR;
}
//----------------------------------------------------------------------------------------------------
void Usb::reset_ISTR()
{
	//get pointer to the ISTR and write at this point value 0
	*((unsigned long *)(&(USB_regs->ISTR))) = 0x00000000;
}
//----------------------------------------------------------------------------------------------------
void Usb::init()
{
	//--------------------
	// Set to memory location
	//--------------------
	USB_regs = (USB_T*) 0x40005C00;
	USB_buffors = (USB_Buffors_T*) 0x40006000;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// enable clock for USB
	//--------------------
	rcc.clockUSB(enable);
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Enable USB Interrupts
	//--------------------
	//nvic.set_priority(5, 0x00000010);
//  NVIC->ISER[0] |= (1 << (USB_LP_CAN_RX0_IRQChannel & 0x1F));
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
void Usb::reset()
{
	reset_ISTR(); /* Clear Interrupt Status */


  //CNTR = CNTR_CTRM | CNTR_RESETM |
    //     (USB_SUSPEND_EVENT ? CNTR_SUSPM   : 0) |
      //   (USB_WAKEUP_EVENT  ? CNTR_WKUPM   : 0) |
        // (USB_ERROR_EVENT   ? CNTR_ERRM    : 0) |
         //(USB_ERROR_EVENT   ? CNTR_PMAOVRM : 0) |
//         (USB_SOF_EVENT     ? CNTR_SOFM    : 0) |
  //       (USB_SOF_EVENT     ? CNTR_ESOFM   : 0);

  //FreeBufAddr = EP_BUF_ADDR;

  //BTABLE = 0x00;                            /* set BTABLE Address */

  /* Setup Control Endpoint 0 */

  //pBUF_DSCR->ADDR_TX = FreeBufAddr;
  //FreeBufAddr += USB_MAX_PACKET0;
  //pBUF_DSCR->ADDR_RX = FreeBufAddr;
  //FreeBufAddr += USB_MAX_PACKET0;
  //if (USB_MAX_PACKET0 > 62) {
//    pBUF_DSCR->COUNT_RX = ((USB_MAX_PACKET0 << 5) - 1) | 0x8000;
//  } else {
    //pBUF_DSCR->COUNT_RX =   USB_MAX_PACKET0 << 9;
  //}
  //EPxREG(0) = EP_CONTROL | EP_RX_VALID;
//
//  DADDR = DADDR_EF | 0;                     /* Enable USB Default Address */
}
//----------------------------------------------------------------------------------------------------
// global function
//----------------------------------------------------------------------------------------------------
void USB_LP_CAN_RX0_Interrupt(void)
{
	LedRedPin.toggle();
	if (usb.get_ISTR().RESET)
	{
		usb.reset();
	}
}
//----------------------------------------------------------------------------------------------------

/*
void Usb::open_HID_mode()
{
}
//----------------------------------------------------------------------------------------------------
void Usb::send()
{
}
//----------------------------------------------------------------------------------------------------
void Usb::receive()
{
}
//----------------------------------------------------------------------------------------------------
void Usb::onReceived()
{
}
//----------------------------------------------------------------------------------------------------
void Usb::onSended()
{
}
//----------------------------------------------------------------------------------------------------
void Usb::close()
{
}*/
//----------------------------------------------------------------------------------------------------
