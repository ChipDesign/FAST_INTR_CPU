80000000:	00200193          	li	gp,2
80000004:	00001097          	auipc	ra,0x1
80000008:	51c08093          	addi	ra,ra,1308 # 80001520 <__DATA_BEGIN__>
8000000c:	0aa00113          	li	sp,170
80000010:	00000797          	auipc	a5,0x0
80000014:	01478793          	addi	a5,a5,20 # 80000024 <test_2+0x24>
80000018:	00209023          	sh	sp,0(ra)
8000001c:	00009703          	lh	a4,0(ra)
80000024:	00010713          	mv	a4,sp
80000028:	0aa00393          	li	t2,170

80000030:	00300193          	li	gp,3
80000034:	00001097          	auipc	ra,0x1
80000038:	4ec08093          	addi	ra,ra,1260 # 80001520 <__DATA_BEGIN__>
8000003c:	ffffb137          	lui	sp,0xffffb
80000040:	a0010113          	addi	sp,sp,-1536 # ffffaa00 <__global_pointer$+0x7fff8ce0>
80000044:	00000797          	auipc	a5,0x0
80000048:	01478793          	addi	a5,a5,20 # 80000058 <test_3+0x28>
8000004c:	00209123          	sh	sp,2(ra)
80000050:	00209703          	lh	a4,2(ra)
80000058:	00010713          	mv	a4,sp
8000005c:	ffffb3b7          	lui	t2,0xffffb
80000060:	a0038393          	addi	t2,t2,-1536 # ffffaa00 <__global_pointer$+0x7fff8ce0>

80000068:	00400193          	li	gp,4
8000006c:	00001097          	auipc	ra,0x1
80000070:	4b408093          	addi	ra,ra,1204 # 80001520 <__DATA_BEGIN__>
80000074:	beef1137          	lui	sp,0xbeef1
80000078:	aa010113          	addi	sp,sp,-1376 # beef0aa0 <__global_pointer$+0x3eeeed80>
8000007c:	00000797          	auipc	a5,0x0
80000080:	01478793          	addi	a5,a5,20 # 80000090 <test_4+0x28>
80000084:	00209223          	sh	sp,4(ra)
80000088:	0040a703          	lw	a4,4(ra)
80000090:	00010713          	mv	a4,sp
80000094:	beef13b7          	lui	t2,0xbeef1
80000098:	aa038393          	addi	t2,t2,-1376 # beef0aa0 <__global_pointer$+0x3eeeed80>

800000a0 <test_5>:
  TEST_ST_OP( 5, lh, sh, 0xffffffffffffa00a, 6, tdat );
800000a0:	00500193          	li	gp,5
800000a4:	00001097          	auipc	ra,0x1
800000a8:	47c08093          	addi	ra,ra,1148 # 80001520 <__DATA_BEGIN__>
800000ac:	ffffa137          	lui	sp,0xffffa
800000b0:	00a10113          	addi	sp,sp,10 # ffffa00a <__global_pointer$+0x7fff82ea>
800000b4:	00000797          	auipc	a5,0x0
800000b8:	01478793          	addi	a5,a5,20 # 800000c8 <test_5+0x28>
800000bc:	00209323          	sh	sp,6(ra)
800000c0:	00609703          	lh	a4,6(ra)
800000c4:	0080006f          	j	800000cc <test_5+0x2c>
800000c8:	00010713          	mv	a4,sp
800000cc:	ffffa3b7          	lui	t2,0xffffa
800000d0:	00a38393          	addi	t2,t2,10 # ffffa00a <__global_pointer$+0x7fff82ea>
800000d4:	42771263          	bne	a4,t2,800004f8 <fail>

800000d8 <test_6>:

  # Test with negative offset

  TEST_ST_OP( 6, lh, sh, 0x00000000000000aa, -6, tdat8 );
800000d8:	00600193          	li	gp,6
800000dc:	00001097          	auipc	ra,0x1
800000e0:	45208093          	addi	ra,ra,1106 # 8000152e <tdat8>
800000e4:	0aa00113          	li	sp,170
800000e8:	00000797          	auipc	a5,0x0
800000ec:	01478793          	addi	a5,a5,20 # 800000fc <test_6+0x24>
800000f0:	fe209d23          	sh	sp,-6(ra)
800000f4:	ffa09703          	lh	a4,-6(ra)
800000f8:	0080006f          	j	80000100 <test_6+0x28>
800000fc:	00010713          	mv	a4,sp
80000100:	0aa00393          	li	t2,170
80000104:	3e771a63          	bne	a4,t2,800004f8 <fail>

80000108 <test_7>:
  TEST_ST_OP( 7, lh, sh, 0xffffffffffffaa00, -4, tdat8 );
80000108:	00700193          	li	gp,7
8000010c:	00001097          	auipc	ra,0x1
80000110:	42208093          	addi	ra,ra,1058 # 8000152e <tdat8>
80000114:	ffffb137          	lui	sp,0xffffb
80000118:	a0010113          	addi	sp,sp,-1536 # ffffaa00 <__global_pointer$+0x7fff8ce0>
8000011c:	00000797          	auipc	a5,0x0
80000120:	01478793          	addi	a5,a5,20 # 80000130 <test_7+0x28>
80000124:	fe209e23          	sh	sp,-4(ra)
80000128:	ffc09703          	lh	a4,-4(ra)
8000012c:	0080006f          	j	80000134 <test_7+0x2c>
80000130:	00010713          	mv	a4,sp
80000134:	ffffb3b7          	lui	t2,0xffffb
80000138:	a0038393          	addi	t2,t2,-1536 # ffffaa00 <__global_pointer$+0x7fff8ce0>
8000013c:	3a771e63          	bne	a4,t2,800004f8 <fail>

80000140 <test_8>:
  TEST_ST_OP( 8, lh, sh, 0x0000000000000aa0, -2, tdat8 );
80000140:	00800193          	li	gp,8
80000144:	00001097          	auipc	ra,0x1
80000148:	3ea08093          	addi	ra,ra,1002 # 8000152e <tdat8>
8000014c:	00001137          	lui	sp,0x1
80000150:	aa010113          	addi	sp,sp,-1376 # aa0 <test_2-0x7ffff560>
80000154:	00000797          	auipc	a5,0x0
80000158:	01478793          	addi	a5,a5,20 # 80000168 <test_8+0x28>
8000015c:	fe209f23          	sh	sp,-2(ra)
80000160:	ffe09703          	lh	a4,-2(ra)
80000164:	0080006f          	j	8000016c <test_8+0x2c>
80000168:	00010713          	mv	a4,sp
8000016c:	000013b7          	lui	t2,0x1
80000170:	aa038393          	addi	t2,t2,-1376 # aa0 <test_2-0x7ffff560>
80000174:	38771263          	bne	a4,t2,800004f8 <fail>

80000178 <test_9>:
  TEST_ST_OP( 9, lh, sh, 0xffffffffffffa00a, 0,  tdat8 );
80000178:	00900193          	li	gp,9
8000017c:	00001097          	auipc	ra,0x1
80000180:	3b208093          	addi	ra,ra,946 # 8000152e <tdat8>
80000184:	ffffa137          	lui	sp,0xffffa
80000188:	00a10113          	addi	sp,sp,10 # ffffa00a <__global_pointer$+0x7fff82ea>
8000018c:	00000797          	auipc	a5,0x0
80000190:	01478793          	addi	a5,a5,20 # 800001a0 <test_9+0x28>
80000194:	00209023          	sh	sp,0(ra)
80000198:	00009703          	lh	a4,0(ra)
8000019c:	0080006f          	j	800001a4 <test_9+0x2c>
800001a0:	00010713          	mv	a4,sp
800001a4:	ffffa3b7          	lui	t2,0xffffa
800001a8:	00a38393          	addi	t2,t2,10 # ffffa00a <__global_pointer$+0x7fff82ea>
800001ac:	34771663          	bne	a4,t2,800004f8 <fail>

800001b0 <test_10>:

  # Test with a negative base

  TEST_CASE( 10, x5, 0x5678, \
800001b0:	00a00193          	li	gp,10
800001b4:	00001097          	auipc	ra,0x1
800001b8:	37c08093          	addi	ra,ra,892 # 80001530 <tdat9>
800001bc:	12345137          	lui	sp,0x12345
800001c0:	67810113          	addi	sp,sp,1656 # 12345678 <test_2-0x6dcba988>
800001c4:	fe008213          	addi	tp,ra,-32
800001c8:	02221023          	sh	sp,32(tp) # 20 <test_2-0x7fffffe0>
800001cc:	00009283          	lh	t0,0(ra)
800001d0:	000053b7          	lui	t2,0x5
800001d4:	67838393          	addi	t2,t2,1656 # 5678 <test_2-0x7fffa988>
800001d8:	32729063          	bne	t0,t2,800004f8 <fail>

800001dc <test_11>:
    lh x5, 0(x1); \
  )

  # Test with unaligned base

  TEST_CASE( 11, x5, 0x3098, \
800001dc:	00b00193          	li	gp,11
800001e0:	00001097          	auipc	ra,0x1
800001e4:	35008093          	addi	ra,ra,848 # 80001530 <tdat9>
800001e8:	00003137          	lui	sp,0x3
800001ec:	09810113          	addi	sp,sp,152 # 3098 <test_2-0x7fffcf68>
800001f0:	ffb08093          	addi	ra,ra,-5
800001f4:	002093a3          	sh	sp,7(ra)
800001f8:	00001217          	auipc	tp,0x1
800001fc:	33a20213          	addi	tp,tp,826 # 80001532 <tdat10>
80000200:	00021283          	lh	t0,0(tp) # 0 <test_2-0x80000000>
80000204:	000033b7          	lui	t2,0x3
80000208:	09838393          	addi	t2,t2,152 # 3098 <test_2-0x7fffcf68>
8000020c:	2e729663          	bne	t0,t2,800004f8 <fail>

80000210 <test_12>:

  #-------------------------------------------------------------
  # Bypassing tests
  #-------------------------------------------------------------

  TEST_ST_SRC12_BYPASS( 12, 0, 0, lh, sh, 0xffffffffffffccdd, 0,  tdat );
80000210:	00c00193          	li	gp,12
80000214:	00000213          	li	tp,0
80000218:	ffffd0b7          	lui	ra,0xffffd
8000021c:	cdd08093          	addi	ra,ra,-803 # ffffccdd <__global_pointer$+0x7fffafbd>
80000220:	00001117          	auipc	sp,0x1
80000224:	30010113          	addi	sp,sp,768 # 80001520 <__DATA_BEGIN__>
80000228:	00111023          	sh	ra,0(sp)
8000022c:	00011703          	lh	a4,0(sp)
80000230:	ffffd3b7          	lui	t2,0xffffd
80000234:	cdd38393          	addi	t2,t2,-803 # ffffccdd <__global_pointer$+0x7fffafbd>
80000238:	2c771063          	bne	a4,t2,800004f8 <fail>
8000023c:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
80000240:	00200293          	li	t0,2
80000244:	fc521ae3          	bne	tp,t0,80000218 <test_12+0x8>

80000248 <test_13>:
  TEST_ST_SRC12_BYPASS( 13, 0, 1, lh, sh, 0xffffffffffffbccd, 2,  tdat );
80000248:	00d00193          	li	gp,13
8000024c:	00000213          	li	tp,0
80000250:	ffffc0b7          	lui	ra,0xffffc
80000254:	ccd08093          	addi	ra,ra,-819 # ffffbccd <__global_pointer$+0x7fff9fad>
80000258:	00001117          	auipc	sp,0x1
8000025c:	2c810113          	addi	sp,sp,712 # 80001520 <__DATA_BEGIN__>
80000260:	00000013          	nop
80000264:	00111123          	sh	ra,2(sp)
80000268:	00211703          	lh	a4,2(sp)
8000026c:	ffffc3b7          	lui	t2,0xffffc
80000270:	ccd38393          	addi	t2,t2,-819 # ffffbccd <__global_pointer$+0x7fff9fad>
80000274:	28771263          	bne	a4,t2,800004f8 <fail>
80000278:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
8000027c:	00200293          	li	t0,2
80000280:	fc5218e3          	bne	tp,t0,80000250 <test_13+0x8>

80000284 <test_14>:
  TEST_ST_SRC12_BYPASS( 14, 0, 2, lh, sh, 0xffffffffffffbbcc, 4,  tdat );
80000284:	00e00193          	li	gp,14
80000288:	00000213          	li	tp,0
8000028c:	ffffc0b7          	lui	ra,0xffffc
80000290:	bcc08093          	addi	ra,ra,-1076 # ffffbbcc <__global_pointer$+0x7fff9eac>
80000294:	00001117          	auipc	sp,0x1
80000298:	28c10113          	addi	sp,sp,652 # 80001520 <__DATA_BEGIN__>
8000029c:	00000013          	nop
800002a0:	00000013          	nop
800002a4:	00111223          	sh	ra,4(sp)
800002a8:	00411703          	lh	a4,4(sp)
800002ac:	ffffc3b7          	lui	t2,0xffffc
800002b0:	bcc38393          	addi	t2,t2,-1076 # ffffbbcc <__global_pointer$+0x7fff9eac>
800002b4:	24771263          	bne	a4,t2,800004f8 <fail>
800002b8:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
800002bc:	00200293          	li	t0,2
800002c0:	fc5216e3          	bne	tp,t0,8000028c <test_14+0x8>

800002c4 <test_15>:
  TEST_ST_SRC12_BYPASS( 15, 1, 0, lh, sh, 0xffffffffffffabbc, 6, tdat );
800002c4:	00f00193          	li	gp,15
800002c8:	00000213          	li	tp,0
800002cc:	ffffb0b7          	lui	ra,0xffffb
800002d0:	bbc08093          	addi	ra,ra,-1092 # ffffabbc <__global_pointer$+0x7fff8e9c>
800002d4:	00000013          	nop
800002d8:	00001117          	auipc	sp,0x1
800002dc:	24810113          	addi	sp,sp,584 # 80001520 <__DATA_BEGIN__>
800002e0:	00111323          	sh	ra,6(sp)
800002e4:	00611703          	lh	a4,6(sp)
800002e8:	ffffb3b7          	lui	t2,0xffffb
800002ec:	bbc38393          	addi	t2,t2,-1092 # ffffabbc <__global_pointer$+0x7fff8e9c>
800002f0:	20771463          	bne	a4,t2,800004f8 <fail>
800002f4:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
800002f8:	00200293          	li	t0,2
800002fc:	fc5218e3          	bne	tp,t0,800002cc <test_15+0x8>

80000300 <test_16>:
  TEST_ST_SRC12_BYPASS( 16, 1, 1, lh, sh, 0xffffffffffffaabb, 8, tdat );
80000300:	01000193          	li	gp,16
80000304:	00000213          	li	tp,0
80000308:	ffffb0b7          	lui	ra,0xffffb
8000030c:	abb08093          	addi	ra,ra,-1349 # ffffaabb <__global_pointer$+0x7fff8d9b>
80000310:	00000013          	nop
80000314:	00001117          	auipc	sp,0x1
80000318:	20c10113          	addi	sp,sp,524 # 80001520 <__DATA_BEGIN__>
8000031c:	00000013          	nop
80000320:	00111423          	sh	ra,8(sp)
80000324:	00811703          	lh	a4,8(sp)
80000328:	ffffb3b7          	lui	t2,0xffffb
8000032c:	abb38393          	addi	t2,t2,-1349 # ffffaabb <__global_pointer$+0x7fff8d9b>
80000330:	1c771463          	bne	a4,t2,800004f8 <fail>
80000334:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
80000338:	00200293          	li	t0,2
8000033c:	fc5216e3          	bne	tp,t0,80000308 <test_16+0x8>

80000340 <test_17>:
  TEST_ST_SRC12_BYPASS( 17, 2, 0, lh, sh, 0xffffffffffffdaab, 10, tdat );
80000340:	01100193          	li	gp,17
80000344:	00000213          	li	tp,0
80000348:	ffffe0b7          	lui	ra,0xffffe
8000034c:	aab08093          	addi	ra,ra,-1365 # ffffdaab <__global_pointer$+0x7fffbd8b>
80000350:	00000013          	nop
80000354:	00000013          	nop
80000358:	00001117          	auipc	sp,0x1
8000035c:	1c810113          	addi	sp,sp,456 # 80001520 <__DATA_BEGIN__>
80000360:	00111523          	sh	ra,10(sp)
80000364:	00a11703          	lh	a4,10(sp)
80000368:	ffffe3b7          	lui	t2,0xffffe
8000036c:	aab38393          	addi	t2,t2,-1365 # ffffdaab <__global_pointer$+0x7fffbd8b>
80000370:	18771463          	bne	a4,t2,800004f8 <fail>
80000374:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
80000378:	00200293          	li	t0,2
8000037c:	fc5216e3          	bne	tp,t0,80000348 <test_17+0x8>

80000380 <test_18>:

  TEST_ST_SRC21_BYPASS( 18, 0, 0, lh, sh, 0x2233, 0,  tdat );
80000380:	01200193          	li	gp,18
80000384:	00000213          	li	tp,0
80000388:	00001117          	auipc	sp,0x1
8000038c:	19810113          	addi	sp,sp,408 # 80001520 <__DATA_BEGIN__>
80000390:	000020b7          	lui	ra,0x2
80000394:	23308093          	addi	ra,ra,563 # 2233 <test_2-0x7fffddcd>
80000398:	00111023          	sh	ra,0(sp)
8000039c:	00011703          	lh	a4,0(sp)
800003a0:	000023b7          	lui	t2,0x2
800003a4:	23338393          	addi	t2,t2,563 # 2233 <test_2-0x7fffddcd>
800003a8:	14771863          	bne	a4,t2,800004f8 <fail>
800003ac:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
800003b0:	00200293          	li	t0,2
800003b4:	fc521ae3          	bne	tp,t0,80000388 <test_18+0x8>

800003b8 <test_19>:
  TEST_ST_SRC21_BYPASS( 19, 0, 1, lh, sh, 0x1223, 2,  tdat );
800003b8:	01300193          	li	gp,19
800003bc:	00000213          	li	tp,0
800003c0:	00001117          	auipc	sp,0x1
800003c4:	16010113          	addi	sp,sp,352 # 80001520 <__DATA_BEGIN__>
800003c8:	000010b7          	lui	ra,0x1
800003cc:	22308093          	addi	ra,ra,547 # 1223 <test_2-0x7fffeddd>
800003d0:	00000013          	nop
800003d4:	00111123          	sh	ra,2(sp)
800003d8:	00211703          	lh	a4,2(sp)
800003dc:	000013b7          	lui	t2,0x1
800003e0:	22338393          	addi	t2,t2,547 # 1223 <test_2-0x7fffeddd>
800003e4:	10771a63          	bne	a4,t2,800004f8 <fail>
800003e8:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
800003ec:	00200293          	li	t0,2
800003f0:	fc5218e3          	bne	tp,t0,800003c0 <test_19+0x8>

800003f4 <test_20>:
  TEST_ST_SRC21_BYPASS( 20, 0, 2, lh, sh, 0x1122, 4,  tdat );
800003f4:	01400193          	li	gp,20
800003f8:	00000213          	li	tp,0
800003fc:	00001117          	auipc	sp,0x1
80000400:	12410113          	addi	sp,sp,292 # 80001520 <__DATA_BEGIN__>
80000404:	000010b7          	lui	ra,0x1
80000408:	12208093          	addi	ra,ra,290 # 1122 <test_2-0x7fffeede>
8000040c:	00000013          	nop
80000410:	00000013          	nop
80000414:	00111223          	sh	ra,4(sp)
80000418:	00411703          	lh	a4,4(sp)
8000041c:	000013b7          	lui	t2,0x1
80000420:	12238393          	addi	t2,t2,290 # 1122 <test_2-0x7fffeede>
80000424:	0c771a63          	bne	a4,t2,800004f8 <fail>
80000428:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
8000042c:	00200293          	li	t0,2
80000430:	fc5216e3          	bne	tp,t0,800003fc <test_20+0x8>

80000434 <test_21>:
  TEST_ST_SRC21_BYPASS( 21, 1, 0, lh, sh, 0x0112, 6, tdat );
80000434:	01500193          	li	gp,21
80000438:	00000213          	li	tp,0
8000043c:	00001117          	auipc	sp,0x1
80000440:	0e410113          	addi	sp,sp,228 # 80001520 <__DATA_BEGIN__>
80000444:	00000013          	nop
80000448:	11200093          	li	ra,274
8000044c:	00111323          	sh	ra,6(sp)
80000450:	00611703          	lh	a4,6(sp)
80000454:	11200393          	li	t2,274
80000458:	0a771063          	bne	a4,t2,800004f8 <fail>
8000045c:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
80000460:	00200293          	li	t0,2
80000464:	fc521ce3          	bne	tp,t0,8000043c <test_21+0x8>

80000468 <test_22>:
  TEST_ST_SRC21_BYPASS( 22, 1, 1, lh, sh, 0x0011, 8, tdat );
80000468:	01600193          	li	gp,22
8000046c:	00000213          	li	tp,0
80000470:	00001117          	auipc	sp,0x1
80000474:	0b010113          	addi	sp,sp,176 # 80001520 <__DATA_BEGIN__>
80000478:	00000013          	nop
8000047c:	01100093          	li	ra,17
80000480:	00000013          	nop
80000484:	00111423          	sh	ra,8(sp)
80000488:	00811703          	lh	a4,8(sp)
8000048c:	01100393          	li	t2,17
80000490:	06771463          	bne	a4,t2,800004f8 <fail>
80000494:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
80000498:	00200293          	li	t0,2
8000049c:	fc521ae3          	bne	tp,t0,80000470 <test_22+0x8>

800004a0 <test_23>:
  TEST_ST_SRC21_BYPASS( 23, 2, 0, lh, sh, 0x3001, 10, tdat );
800004a0:	01700193          	li	gp,23
800004a4:	00000213          	li	tp,0
800004a8:	00001117          	auipc	sp,0x1
800004ac:	07810113          	addi	sp,sp,120 # 80001520 <__DATA_BEGIN__>
800004b0:	00000013          	nop
800004b4:	00000013          	nop
800004b8:	000030b7          	lui	ra,0x3
800004bc:	00108093          	addi	ra,ra,1 # 3001 <test_2-0x7fffcfff>
800004c0:	00111523          	sh	ra,10(sp)
800004c4:	00a11703          	lh	a4,10(sp)
800004c8:	000033b7          	lui	t2,0x3
800004cc:	00138393          	addi	t2,t2,1 # 3001 <test_2-0x7fffcfff>
800004d0:	02771463          	bne	a4,t2,800004f8 <fail>
800004d4:	00120213          	addi	tp,tp,1 # 1 <test_2-0x7fffffff>
800004d8:	00200293          	li	t0,2
800004dc:	fc5216e3          	bne	tp,t0,800004a8 <test_23+0x8>

  li a0, 0xbeef
800004e0:	0000c537          	lui	a0,0xc
800004e4:	eef50513          	addi	a0,a0,-273 # beef <test_2-0x7fff4111>
  la a1, tdat
800004e8:	00001597          	auipc	a1,0x1
800004ec:	03858593          	addi	a1,a1,56 # 80001520 <__DATA_BEGIN__>
  sh a0, 6(a1)
800004f0:	00a59323          	sh	a0,6(a1)

  TEST_PASSFAIL
800004f4:	00301c63          	bne	zero,gp,8000050c <pass>

800004f8 <fail>:
800004f8:	0ff0000f          	fence
800004fc:	00018063          	beqz	gp,800004fc <fail+0x4>
80000500:	00119193          	slli	gp,gp,0x1
80000504:	0011e193          	ori	gp,gp,1
80000508:	00000073          	ecall

8000050c <pass>:
8000050c:	0ff0000f          	fence
80000510:	00100193          	li	gp,1
80000514:	00000073          	ecall

RVTEST_CODE_END
80000518:	c0001073          	unimp
