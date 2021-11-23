#ifndef USB_H
	#define USB_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"	
	//----------------------------------------------------------------------------------------------------
	#define USB_Address (DEVICES_Address+0x00005C00)
	//----------------------------------------------------------------------------------------------------
	struct USB_EPXR_T
	{
		volatile unsigned long
			EA:4,
			STAT_TX:2,
			DTOG_TX:1,
			CTR_TX:1,
			EP_KIND:1,
			EPTYPE:2,
			SETUP:1,
			STAT_RX:2,
			DTOG_RX:1,
			CTR_RX:1,
			reserved1:16;
	};	
	//----------------------------------------------------------------------------------------------------
	struct USB_RESERVED_T
	{
		volatile unsigned long reserved;
	};
	//----------------------------------------------------------------------------------------------------
	struct USB_CNTR_T
	{
		volatile unsigned long
			FRES:1,
			PDWN:1,
			LP_MODE:1,
			FSUSP:1,
			RESUME:1,
			reserved1:3,
			ESOFM:1,
			SOFM:1,
			RESETM:1,
			SUSPM:1,
			WKUPM:1,
			ERRM:1,
			PMAOVRM:1,
			CTRM:1,
			reserved2:16;
	};
	//----------------------------------------------------------------------------------------------------
	struct USB_ISTR_T
	{
		volatile unsigned long
			EP_ID:4,
			DIR:1,
			reserved1:3,
			ESOF:1,
			SOF:1,
			RESET:1,
			SUSP:1,
			WKUP:1,
			ERR:1,
			PMAOVR:1,
			CTR:1,
			reserved2:16;
	};
	//----------------------------------------------------------------------------------------------------
	struct USB_FNR_T	
	{
		volatile unsigned long
			FN:11,
			LSOF:2,
			LCK:1,
			RXDM:1,
			RXDP:1,
			reserved1:16;
	};
	//----------------------------------------------------------------------------------------------------
	struct USB_DADDR_T
	{
		volatile unsigned long
			ADD:7,
			EF:1,
			reserved1:24;
	};
	//----------------------------------------------------------------------------------------------------
	struct USB_BTABLE_T
	{
		volatile unsigned long
			reserved1:3,
			BTABLE:13,
			reserved2:16;
	};
	//----------------------------------------------------------------------------------------------------
	struct USB_EPnR_T
	{
		//unsigned short int??
		volatile unsigned long
		EA:4,
		STAT_TX:2,
		DTOG_TX:1,
		CTR_TX:1,
		EP_KIND:1,
		EP_TYPE:2,
		SETUP:1,
		STAT_RX:2,
		DTOG_RX:1,
		CTR_RX:1;
	};
	//----------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------
	struct USB_T
	{
		USB_EPXR_T EP0R;//0x00
		USB_EPXR_T EP1R;//0x04
		USB_EPXR_T EP2R;//0x08
		USB_EPXR_T EP3R;//0x0C
		USB_EPXR_T EP4R;//0x10
		USB_EPXR_T EP5R;//0x14
		USB_EPXR_T EP6R;//0x18
		USB_EPXR_T EP7R;//0x1C
		USB_RESERVED_T USB_RESERVED_1;//0x20
		USB_RESERVED_T USB_RESERVED_2;//0x24
		USB_RESERVED_T USB_RESERVED_3;//0x28
		USB_RESERVED_T USB_RESERVED_4;//0x2C
		USB_RESERVED_T USB_RESERVED_5;//0x30
		USB_RESERVED_T USB_RESERVED_6;//0x34
		USB_RESERVED_T USB_RESERVED_7;//0x38
		USB_RESERVED_T USB_RESERVED_8;//0x3C
		USB_CNTR_T CNTR;//0x40
		USB_ISTR_T ISTR;//0x44
		USB_FNR_T FNR;//0x48
		USB_DADDR_T DADDR;//0x4C
		USB_BTABLE_T BTABLE;//0x50				
	};	
	//----------------------------------------------------------------------------------------------------
	struct USB_Buffors_T
	{
		/*USB_EPnR
		USB_ADDRn_TX
		USB_COUNTn_TX
		USB_ADDRn_RX
		USB_COUNTn_RX*/
	};
	//----------------------------------------------------------------------------------------------------
	class usb
	{
		private:
			USB_T* USB_regs;			
			USB_Buffors_T* USB_buffors;
		public:
			usb();
			void init();
			void open_HID_mode();
			void send();
			void receive();
			void onReceived();
			void onSended();
			void close();
	};
	//----------------------------------------------------------------------------------------------------
#endif
