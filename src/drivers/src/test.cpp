#include "test.h"
test klasa_test;

test::test()
{
	//--------------------
	// Set SysTick_Regs to memory location
	//--------------------
		systick_regs=(test_TypeDef*)test_Address;
	//~~~~~~~~~~~~~~~~~~~~
}

void test::init()
{
	//--------------------
	// Set SysTick_Regs to memory location
	//--------------------
		systick_regs=(test_TypeDef*)test_Address;
	//~~~~~~~~~~~~~~~~~~~~
}

