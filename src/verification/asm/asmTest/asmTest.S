# See LICENSE for license details.

#include "riscv_test.h"
	.text			# Define beginning of text section
	.global	_boot		# Define entry _boot

_boot:
    addi x3, x0, 1   
	.end			# End of file

#undef RVTEST_RV64U
