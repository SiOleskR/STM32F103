/* maksymalny adres stosu */
_estack = 0x20005000;    /* end of RAM */

/* linkier error jezeli sterta (heap) i stos (stack) nie mieszczą się w RAMie */
_Min_Heap_Size = 0x200;     /* required amount of heap  */
_Min_Stack_Size = 0x400;	/* required amount of stack */


/*----------------------*/
/* Memory organization */
/*----------------------*/
MEMORY
{
	RAM (xrw)	: ORIGIN = 0x20000000,	LENGTH = 20K
	FLASH (rx)	: ORIGIN = 0x08000000,	LENGTH = 64K
}


/*----------------------*/
/* Section organization */
/*----------------------*/
SECTIONS
{
	/*----------------------*/
	/* FLASH */
	/*----------------------*/
	
		/*----------------------*/
		/* Interrupt table go to FLASH from 0x8000000 */
		/*----------------------*/
			.interrupt_vectors :
			{
				. = ALIGN(4);
				KEEP(*(.interrupt_vectors))
			}>FLASH
		/*~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*----------------------*/
		/* Program code go to FLASH after interrupt table */
		/*----------------------*/
			.text :
			{
				. = ALIGN(4);
				*(.text)
				*(.text*)
				*(.glue_7*)
				*(.glue_7t*)
				*(.vfp11_veneer*)
				*(.v4_bx*)
				*(.iplt*)
				*(.rel*)
			}>FLASH
		/*~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*----------------------*/
		/* Constant variables go to FLASH */
		/*----------------------*/
			.rodata :
			{
				. = ALIGN(4);
				*(.rodata)
				*(.rodata*)
				_ROM_DATA_START = .;
			}>FLASH
		/*~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*----------------------*/
		/* Variables from gcc libs go to FLASH */
		/*----------------------*/			
			.ARM.extab :
			{
				*(.ARM.extab* .gnu.linkonce.armextab.*)
			}>FLASH
			
  			.ARM :
  			{
    			__exidx_start = .;
    			*(.ARM.exidx*)
    			__exidx_end = .;
  			}>FLASH
		/*~~~~~~~~~~~~~~~~~~~~~~*/
	/*~~~~~~~~~~~~~~~~~~~~~~*/
				
	/*----------------------*/	
	/* RAM */
	/*----------------------*/
		/*----------------------*/		
		/* Initialized variables go to RAM but initial values are stored in FLASH */
		/*----------------------*/	
			.data : 
			{
				. = ALIGN(4);
				_RAM_DATA_START = .;
				*(.data)
				*(.data*)
				_RAM_DATA_STOP = .;   			
			}>RAM AT >FLASH
		/*~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*----------------------*/
		/* Not initialized variables go to RAM */
		/*----------------------*/
			.bss :
			{
				. = ALIGN(4);
				_BSS_DATA_START = .;
				*(.bss)
				*(.bss*)
				_BSS_DATA_STOP = .;
			}>RAM
		/*~~~~~~~~~~~~~~~~~~~~~~*/

		/*----------------------*/
		/* User_heap_stack, uzyte do sprawdzenia czy jest wystarczajaco duzo pamieci RAM */
		/*----------------------*/
		/* Stack goes to end of RAM */
		/*----------------------*/
			._user_heap_stack :
			{
				. = ALIGN(8);
				PROVIDE ( end = . );
				PROVIDE ( _end = . );
				. = . + _Min_Heap_Size;
				. = . + _Min_Stack_Size;
			} >RAM
		/*~~~~~~~~~~~~~~~~~~~~~~*/
	/*~~~~~~~~~~~~~~~~~~~~~~*/
		
	/*----------------------*/
	/*  Remove C++ section  */
	/*----------------------*/	
		/DISCARD/ :
		{
			*(.ARM.exidx*)
			*(.ARM.extab*)
		}
	/*~~~~~~~~~~~~~~~~~~~~~~*/
}
