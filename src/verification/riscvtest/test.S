# Add
# Format:
#	ADD RD, RS1, RS2
# Description:
#	The contents of RS1 is added to the contents of RS2 and the result is 
#	placed in RD.

	.text			# Define beginning of text section
	.global	_start		# Define entry _start



_start:
   nop
   nop
   nop
   csrw	mtvec, a5
   nop
   nop
   nop

_ISR:
   addi x2, x0, 1 
   addi x2, x2, 1 
   addi x2, x2, 1 
   addi x2, x2, 1 
   addi x2, x2, 1 
   mret
