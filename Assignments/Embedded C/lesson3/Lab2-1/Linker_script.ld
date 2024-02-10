/*learn-in-depth
Unit2_lesson3_lab_2
Mastering Embedded System Online Diploma
Eng. Fady Emad*/


MEMORY
{
	FLASH(rx) : ORIGIN = 0X08000000, LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		E_text = . ;
	} > FLASH
	.data :
	{	
		S_data = . ;
		*(.data)
		E_data = . ;
	} > SRAM AT> FLASH
	.bss :
	{	
		S_bss = . ;
		*(.bss)
		E_bss = . ;
		. = . + 0X1000;
		stack_top = . ;
	} > SRAM

}	
