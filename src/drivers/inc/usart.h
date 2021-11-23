#ifndef USART_H
	#define USART_H
	//----------------------------------------------------------------------------------------------------
	#include "STM32.h"
	#include "utility.h"
	//----------------------------------------------------------------------------------------------------
	#define BUFFOR_SIZE 10 //max 255 - type unsigned char
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		USART_NULL=0x00000000,
		USART1_Address=0x40013800,
		USART2_Address=0x40004400,
		USART3_Address=0x40004800,
		UART4_Address=0x40004C00,
		UART5_Address=0x40005000
	}USART_Address_T;
	//----------------------------------------------------------------------------------------------------
	typedef enum
	{
		USART_110=110,
		USART_150=150,
		USART_300=300,
		USART_1200=1200,
		USART_2400=2400,
		USART_4800=4800,
		USART_9600=9600,
		USART_19200=19200,
		USART_38400=38400,
		USART_57600=57600,
		USART_115200=115200,
		USART_230400=230400,
		USART_460800=460800,
		USART_921600=921600
	}USART_Speed_T;
	//----------------------------------------------------------------------------------------------------
	struct USART_SR_T
	{
		volatile unsigned long
			PE:1,
			FE:1,
			NE:1,
			ORE:1,
			IDLE:1,
			RXNE:1,
			TC:1,
			TXE:1,
			LBD:1,
			CTS:1,
			reserved:22;
	};
	//----------------------------------------------------------------------------------------------------
	struct USART_DR_T
	{
		volatile unsigned long
			DR:9,
			reserved:23;
	};
	//----------------------------------------------------------------------------------------------------
	struct USART_BRR_T
	{
		volatile unsigned long
			DIV_Fraction:4,
			DIV_Mantissa:12,
			reserved:16;
	};
	//----------------------------------------------------------------------------------------------------
	struct USART_CR1_T
	{
		volatile unsigned long
			SBK:1,
			RWU:1,
			RE:1,
			TE:1,
			IDLEIE:1,
			RXNEIE:1,
			TCIE:1,
			TXEIE:1,
			PEIE:1,
			PS:1,
			PCE:1,
			WAKE:1,
			M:1,
			UE:1,
			reserved:18;
	};
	//----------------------------------------------------------------------------------------------------
	struct USART_CR2_T
	{
		volatile unsigned long
			ADD:4,
			reserved1:1,
			LBDL:1,
			LBDIE:1,
			reserved2:1,
			LBCL:1,
			CPHA:1,
			CPOL:1,
			CLKEN:1,
			STOP:2,
			LINEN:1,
			reserved3:17;
	};
	//----------------------------------------------------------------------------------------------------
	struct USART_CR3_T
	{
		volatile unsigned long
			EIE:1,
			IREN:1,
			IRLP:1,
			HDSEL:1,
			NACK:1,
			SCEN:1,
			DMAR:1,
			DMAT:1,
			RTSE:1,
			CTSE:1,
			CTSIE:1,
			reserved:21;
	};
	//----------------------------------------------------------------------------------------------------
	struct USART_GTPR_T
	{
		volatile unsigned long
			PSC:8,
			GT:8,
			reserved:16;
	};
	//----------------------------------------------------------------------------------------------------
	struct UART_T
	{
		USART_SR_T SR;
		USART_DR_T DR;
		USART_BRR_T BRR;
		USART_CR1_T CR1;
		USART_CR2_T CR2;
		USART_CR3_T CR3;
		USART_GTPR_T GTPR;
	};
	//----------------------------------------------------------------------------------------------------
	class usart
	{
		private:
			UART_T* USART_regs;
			unsigned char RX_Buffor[BUFFOR_SIZE];
			unsigned char RX_len;
			unsigned char TX_Buffor[BUFFOR_SIZE];
			unsigned char TX_len;
			unsigned char TX_index;
			USART_Speed_T Speed;

			void setup(unsigned long fck);
			void start_transmit();
		public:
			usart();
			void init(USART_Address_T device,USART_Speed_T speed);
			void write_char();
			bool get_SR_TXE();

			void write(string napis);
			void write(unsigned char *napis);
			void write(unsigned char napis[],int len);
			unsigned char read();
	};
	//----------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------
		//USART1 remapping - table 54 - AF remap 0: No remap (TX/PA9, RX/PA10) 1: Remap (TX/PB6, RX/PB7)
		//USART1 - interrupt 0x0000_00D4

	extern usart uart1;
#endif
