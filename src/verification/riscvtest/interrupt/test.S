# .global _test
# .global _trap_handler
# _test:
#    ecall
#    addi x1, x0, 100
#    addi x2, x0, 0
#    nop
#    nop
#    nop
#    nop
#    nop
#    ebreak # finish _test
#    nop
#    nop
#    nop
#    nop


# _trap_handler:
#    # addi x1, x0, 0 # don't use x1 or ret will not work
#    addi x2, x0, 0 
#    addi x3, x0, 0 
#    addi x4, x0, 0 
#    ret


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
   la a5, _ISR
   csrw	mtvec, a5
   # ecall
   nop
   nop
   nop

_ISR:
#   ebreak
   addi x2, x0, 1 
   addi x2, x2, 1 
   addi x2, x2, 1 
   addi x2, x2, 1 
   addi x2, x2, 1 
   # mret
   # ebreak; 
   nop
   nop
   nop
