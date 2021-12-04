#ifndef NVIC_H
	#define NVIC_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	#include "utility.h"
	//----------------------------------------------------------------------------------------------------
	#define NVIC_Address (0xE000E100)
	#define NVIC_STIR_Address (0xE000EF00)
	//----------------------------------------------------------------------------------------------------
	struct NVIC_ISERx_S
	{
		volatile unsigned long
		RS0:1,
		RS1:1,
		RS2:1,
		RS3:1,
		RS4:1,
		RS5:1,
		RS6:1,
		RS7:1,
		RS8:1,
		RS9:1,
		RS10:1,
		RS11:1,
		RS12:1,
		RS13:1,
		RS14:1,
		RS15:1,
		RS16:1,
		RS17:1,
		RS18:1,
		RS19:1,
		RS20:1,
		RS21:1,
		RS22:1,
		RS23:1,
		RS24:1,
		RS25:1,
		RS26:1,
		RS27:1,
		RS28:1,
		RS29:1,
		RS30:1,
		RS31:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_ICERx_S
	{
		volatile unsigned long
		RC_W0:1,
		RC_W1:1,
		RC_W2:1,
		RC_W3:1,
		RC_W4:1,
		RC_W5:1,
		RC_W6:1,
		RC_W7:1,
		RC_W8:1,
		RC_W9:1,
		RC_W10:1,
		RC_W11:1,
		RC_W12:1,
		RC_W13:1,
		RC_W14:1,
		RC_W15:1,
		RC_W16:1,
		RC_W17:1,
		RC_W18:1,
		RC_W19:1,
		RC_W20:1,
		RC_W21:1,
		RC_W22:1,
		RC_W23:1,
		RC_W24:1,
		RC_W25:1,
		RC_W26:1,
		RC_W27:1,
		RC_W28:1,
		RC_W29:1,
		RC_W30:1,
		RC_W31:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_ISPRx_S
	{
		volatile unsigned long
		RS0:1,
		RS1:1,
		RS2:1,
		RS3:1,
		RS4:1,
		RS5:1,
		RS6:1,
		RS7:1,
		RS8:1,
		RS9:1,
		RS10:1,
		RS11:1,
		RS12:1,
		RS13:1,
		RS14:1,
		RS15:1,
		RS16:1,
		RS17:1,
		RS18:1,
		RS19:1,
		RS20:1,
		RS21:1,
		RS22:1,
		RS23:1,
		RS24:1,
		RS25:1,
		RS26:1,
		RS27:1,
		RS28:1,
		RS29:1,
		RS30:1,
		RS31:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_ICPRx_S
	{
		volatile unsigned long
		RC_W0:1,
		RC_W1:1,
		RC_W2:1,
		RC_W3:1,
		RC_W4:1,
		RC_W5:1,
		RC_W6:1,
		RC_W7:1,
		RC_W8:1,
		RC_W9:1,
		RC_W10:1,
		RC_W11:1,
		RC_W12:1,
		RC_W13:1,
		RC_W14:1,
		RC_W15:1,
		RC_W16:1,
		RC_W17:1,
		RC_W18:1,
		RC_W19:1,
		RC_W20:1,
		RC_W21:1,
		RC_W22:1,
		RC_W23:1,
		RC_W24:1,
		RC_W25:1,
		RC_W26:1,
		RC_W27:1,
		RC_W28:1,
		RC_W29:1,
		RC_W30:1,
		RC_W31:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_IABRx_S
	{
		volatile unsigned long
		R0:1,
		R1:1,
		R2:1,
		R3:1,
		R4:1,
		R5:1,
		R6:1,
		R7:1,
		R8:1,
		R9:1,
		R10:1,
		R11:1,
		R12:1,
		R13:1,
		R14:1,
		R15:1,
		R16:1,
		R17:1,
		R18:1,
		R19:1,
		R20:1,
		R21:1,
		R22:1,
		R23:1,
		R24:1,
		R25:1,
		R26:1,
		R27:1,
		R28:1,
		R29:1,
		R30:1,
		R31:1;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_IPRx_S
	{
		volatile unsigned char IP;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_STIR_S
	{
		volatile unsigned long
			INTID:9,
			reserved:23;
	};
	//----------------------------------------------------------------------------------------------------
	struct NVIC_REGS_S
	{
		NVIC_ISERx_S ISER[3];
		NVIC_ICERx_S ICER[3];
		NVIC_ISPRx_S ISPR[3];
		NVIC_ICPRx_S ICPR[3];
		NVIC_IABRx_S IABR[3];
		NVIC_IPRx_S IPR[21 * 4];
	};
	//----------------------------------------------------------------------------------------------------
	class Nvic
	{
		private:
		NVIC_REGS_S* regs;
		NVIC_STIR_S* stir;
		public:
		Nvic();
		void init();

		void set_priority(IRQ_Position_Table interrupt, IRQ_Priority priority);
		void set_enable(IRQ_Position_Table interrupt);
		void clear_enable(IRQ_Position_Table interrupt);
		void set_pending(IRQ_Position_Table interrupt);
		void clear_pending(IRQ_Position_Table interrupt);
		bool is_active(IRQ_Position_Table interrupt);
	};
	//----------------------------------------------------------------------------------------------------
	extern Nvic nvic;
#endif
