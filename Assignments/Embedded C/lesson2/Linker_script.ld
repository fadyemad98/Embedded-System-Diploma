ENTRY(reset)

MEMORY 
{
	ROM (rwx) : ORIGIN =0X00000000, LENGTH = 64M 
}

SECTIONS
{	. = 0X10000;
	.startup : 
	{
		startup.o(.text)
	}> ROM
	.text :
	{
		*(.text) *(.rodata)
	}> ROM
	.data :
	{
		*(.data)
	}> ROM
	.bss : 
	{
		*(.bss) *(COMMON)
	}> ROM
	.= . + 0X1000;
	stack_top = . ;
}