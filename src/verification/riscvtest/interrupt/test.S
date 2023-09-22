.global _test
.global _trap_handler
_test:
   ecall
   addi x1, x0, 100
   addi x2, x0, 0
   nop
   nop
   nop
   nop
   nop
   ebreak # finish _test
   nop
   nop
   nop
   nop


_trap_handler:
   # addi x1, x0, 0 # don't use x1 or ret will not work
   addi x2, x0, 0 
   addi x3, x0, 0 
   addi x4, x0, 0 
   ret
