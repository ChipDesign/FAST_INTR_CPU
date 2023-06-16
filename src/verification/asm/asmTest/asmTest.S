# See LICENSE for license details.

#include "riscv_test.h"
	.text			# Define beginning of text section
	.global	_boot		# Define entry _boot

_boot:
    addi x5, x0, 4
    addi x1, x0, 1
    addi x2, x0, 1
    j stop
    j _boot
    addi x4, x0, 2
    addi x5, x0, 4 
    
stop:
    addi x6, x0, 8
    addi x7, x0, 9
	j stop			# Infinite loop to stop execution

	.end			# End of file

#undef RVTEST_RV64U
