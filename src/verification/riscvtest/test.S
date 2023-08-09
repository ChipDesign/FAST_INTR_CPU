# Add
# Format:
#	ADD RD, RS1, RS2
# Description:
#	The contents of RS1 is added to the contents of RS2 and the result is 
#	placed in RD.

	.text			# Define beginning of text section
	.global	_start		# Define entry _start



_start:
   li x1, 1 
   li x2, 2 
   beq x1, x0, _end
   bne x1, x0, _end
   bne x1, x0, _one # should be flushed

_end:
   beq x1, x0, _start # sbp taken, alu not 
   li x3, 3 
   nop
   nop
   nop
   ecall

_one:
   li x4, 4 
   nop
   nop
   nop

    .end
