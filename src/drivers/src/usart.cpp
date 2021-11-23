#include "usart.h"

#include "../inc/interrupt_vectors.h"
#include "STM32.h"
#include "gpio.h"
#include "utility.h"
#include "rcc.h"
//----------------------------------------------------------------------------------------------------
usart uart1;
//----------------------------------------------------------------------------------------------------
usart::usart()
{
}
//----------------------------------------------------------------------------------------------------
void usart::init(USART_Address_T device,USART_Speed_T speed)
{
	//--------------------
	// Set to memory location
	//--------------------
		USART_regs=(UART_T*)device;
	//~~~~~~~~~~~~~~~~~~~~

	RX_len=0;
	TX_len=0;
	Speed=speed;
	setup(Rcc.Get_Sys_Clk());
}
//----------------------------------------------------------------------------------------------------
void usart::setup(unsigned long fck)
{
	//--------------------
	// wyliczam wartosc rejestru BRR (speed) 12-bit mantissa and 4-bit fraction.
	//--------------------
		//                fck
		// Tx_Rx_baud=-----------
		//             16*BRRDIV

		//             fck
		// BRRDIV=---------------
		//         16*Tx_Rx_baud


		// fck - Input clock to the peripheral (PCLK1 for USART2, 3, 4, 5 or PCLK2 for USART1)

		//Fpclk = 12 MHz, Baud = 460800 Bps : OVER8 = 0
		//DIV = 12000000 / ( 16 * 460800 ) = 1.6276
		//DIV_Mantissa = 1
		//DIV_Fraction = 0.6276 * 16 = 10
		//USARTDIV = ( 1 << 4 ) | 10 = 0x001 A = 1.625
		//12000000 / ( 16 * 1.625 ) = 12000000 / 26 = 461538.5 Bps

		//div=9000000/(16*9600)=58,59375
		//mant=58
		//frac=0.59375*16=9.5=10 (albo 9 albo 10)
		//USARTDIV=(0x3A<<4)|0x0A=0x03AA => (58+(10/16))=58.625,(58+(9/16))=58,5625
		//9000000/(16*58.6250) = 9594,8827 (5,1173)
		//9000000/(16*58,5625) = 9605,1227 (5,1227)

		//div=8000000/(16*9600)=52,08333
		//mant=52
		//frac=0.0833*16=1,3328=1
		//USARTDIV=(0x34<<4)|0x01=0x0341 => (52+(1/16))=52,0625
		//8000000/(16*52,0625) = 9603,84 (3,84)
		// inaczej int(8 000 000/9600)/16 (8) = 833/16 = 52,0625

		USART_regs->BRR.DIV_Mantissa = int(int(fck/Speed)/16);
		USART_regs->BRR.DIV_Fraction = int(((fck/Speed/16)%USART_regs->BRR.DIV_Mantissa)*16);

		//fck=9500000;
		//speed=9600;
		//sample=16;

		//print (fck/speed/sample);
		//mantissa=int(fck/speed/sample);
		//print mantissa;
		//fraction=(fck/speed/sample) mod mantissa;
		//print fraction;
		//fraction=fraction*16;
		//print fraction;
		//fraction=int(fraction);
		//print fraction;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// ustawiam piny na alternative function
	//--------------------
		//PA9 - TX - Alternate function Push Pull
		//PA10 - RX - Input mode - No pull-up, no pull-down
		gpio Usart1_TX(GPIO_Port_A,GPIO_PIN_9,GPIO_Output_Alternate_50MHz_PushPull_Mode);
		gpio Usart1_RX(GPIO_Port_A,GPIO_PIN_10,GPIO_Input_Analog_Mode);
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// ustawiam mapowanie pinow
	//--------------------

	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Enable the USART by writing the UE bit in USART_CR1 register to 1.
	//--------------------
		USART_regs->CR1.UE=1;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Program the M bit in USART_CR1 to define the word length.
	//--------------------
		USART_regs->CR1.M=0;
		USART_regs->CR1.PCE=0;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Program the number of stop bits in USART_CR2.
	//--------------------
		USART_regs->CR2.STOP=0;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Set the TE (transmit enable) bit in USART_CR1
	//--------------------
		USART_regs->CR1.TE=1;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Set the RE (receive enable) bit in USART_CR1
	//--------------------
		USART_regs->CR1.RE=1;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// set interrupt for transmit
	//--------------------
		USART_regs->CR1.TXEIE=1;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// set interrupt for recieve
	//--------------------
		USART_regs->CR1.RXNEIE=1;
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this for each data to be transmitted in case of single buffer.
	//--------------------
		USART_regs->DR.DR=82; //'R'
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// After writing the last data into the USART_DR register, wait until TC=1. This indicates
	//	that the transmission of the last frame is complete. This is required for instance when
	//	the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.
	//--------------------

	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	//
	//--------------------

	//~~~~~~~~~~~~~~~~~~~~


}
//----------------------------------------------------------------------------------------------------
// to jest funkcja globalna
//----------------------------------------------------------------------------------------------------
void USART1_Interrupt()
{

	if(uart1.get_SR_TXE())
	{
		uart1.write_char();
	}

}
//----------------------------------------------------------------------------------------------------
bool usart::get_SR_TXE()
{
	return USART_regs->SR.TXE==1?true:false;
}
//----------------------------------------------------------------------------------------------------
void usart::write_char()
{
	if(USART_regs!=(UART_T*)USART_NULL)
	{
		if(uart1.TX_index<uart1.TX_len)
			USART_regs->DR.DR=TX_Buffor[TX_index++];
		else
			uart1.TX_len=0;
	}
}
//----------------------------------------------------------------------------------------------------
void usart::write(string napis)
{
	//--------------------
	// przepisuje do bufora transmisji tyle znaków ile siê zmieœci
	//--------------------
	while(*napis!=0x00)
	{
		if(TX_len<BUFFOR_SIZE)
			TX_Buffor[TX_len++]=*napis;
		napis++;
	}
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// wywo³uje pirwsz¹ transmisjê potem ju¿ poleci przez przerwanie.
	//--------------------
	start_transmit();
	//~~~~~~~~~~~~~~~~~~~~
}
//----------------------------------------------------------------------------------------------------
void usart::write(unsigned char *napis)
{
	write((string) napis);
}
//----------------------------------------------------------------------------------------------------
void usart::write(unsigned char napis[],int len)
{
	//--------------------
	// przepisuje do bufora transmisji tyle znaków ile siê zmieœci
	//--------------------
	for(int i=0;i<len;i++)
		if(TX_len<BUFFOR_SIZE)
			TX_Buffor[TX_len++]=napis[i];
	//~~~~~~~~~~~~~~~~~~~~

	//--------------------
	// wywo³uje pirwsz¹ transmisjê potem ju¿ poleci przez przerwanie.
	//--------------------
	start_transmit();
	//~~~~~~~~~~~~~~~~~~~~

}
//----------------------------------------------------------------------------------------------------
unsigned char usart::read()
{
	if(USART_regs!=(UART_T*)USART_NULL)
		return USART_regs->DR.DR & 0xFF;
	else
		return 0x00;
}
//----------------------------------------------------------------------------------------------------
void usart::start_transmit()
{
	//--------------------
	// wywo³uje pirwsz¹ transmisjê potem ju¿ poleci przez przerwanie.
	//--------------------
	if(TX_len>0)
	{
		TX_index=0;
		write_char();
	}
	//~~~~~~~~~~~~~~~~~~~~
}
