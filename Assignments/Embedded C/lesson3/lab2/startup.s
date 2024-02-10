
.section .vectors
.word 	0x20001000 			/*stack top*/
.word 	_reset				/* 1 reset section*/
.word	Vector_handler		/* 2 NMI handler*/
.word	Vector_handler		/* 3 Hard Fault*/
.word	Vector_handler		/* 4 MemMange*/
.word	Vector_handler		/* 5 BusFault*/
.word	Vector_handler		/* 6 UsageFault*/
.word	Vector_handler		/* 7 Reserved*/
.word	Vector_handler		/* 8 Reserved*/
.word	Vector_handler		/* 9 Reserved*/	
.word	Vector_handler		/* 10 Reserved*/
.word	Vector_handler		/* 11 Svcall*/
.word	Vector_handler		/* 12 DebugReserved*/
.word	Vector_handler		/* 13 Reserved*/
.word	Vector_handler		/* 14 PendSv*/
.word	Vector_handler		/* 15 SysTick*/
.word	Vector_handler		/* 16 IRQ0*/
.word	Vector_handler		/* 17 IRQ1*/
.word	Vector_handler		/* 18 IRQ2*/


.section .text				
_reset:
	bl main					/*branch to main*/
	b  .					/*loop on yourself*/

.thumb_func
Vector_handler:
	b  _reset