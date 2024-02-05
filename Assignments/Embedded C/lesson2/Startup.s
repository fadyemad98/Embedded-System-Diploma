@@ Eng.Fady Emad <Learn-in-depth>
.globl reset
reset:
		ldr sp, =stack_top
		bl main
stop:   b stop