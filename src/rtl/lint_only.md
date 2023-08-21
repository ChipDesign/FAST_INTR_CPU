❯ verilator --lint-only -Wall --top-module top top.v | xargs nvim

# top name not match
%Warning-DECLFILENAME: CSA32.v:5:8: Filename 'CSA32' does not match MODULE name: 'CSA35'
    5 | module CSA35(ain,bin,cin,sout,cout);
      |        ^~~~~
                       decoder.v:307:1: ... note: In file included from decoder.v
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
                       ... For warning description see https://verilator.org/warn/DECLFILENAME?v=5.014
                       ... Use "/* verilator lint_off DECLFILENAME */" and lint_on around source to disable this message.
# pin empty 
%Warning-PINCONNECTEMPTY: top.v:358:10: Cell pin connected by name with empty reference: 'mw_st'
  358 |         .mw_st                  (),
      |          ^~~~~

# signals not driven
%Warning-UNDRIVEN: hazard.v:26:26: Signal is not driven: 'mw_st'
                                 : ... In instance top.hu
   26 | output fd_st,de_st,em_st,mw_st;
      |                          ^~~~~
                   pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Error: Exiting due to 26 warning(s)


# signals not used
%Warning-UNUSEDSIGNAL: top.v:28:24: Bits of signal are not used: 'instr'[63:32]
                                  : ... In instance top
   28 |     input  wire [63:0] instr,
      |                        ^~~~~
%Warning-UNUSEDSIGNAL: top.v:87:13: Signal is not used: 'fin_d_o'
                                  : ... In instance top
   87 |     wire    fin_d_o;
      |             ^~~~~~~
%Warning-UNUSEDSIGNAL: top.v:99:11: Signal is not used: 'instrIllegal_e_o'
                                  : ... In instance top
   99 |     wire  instrIllegal_e_o;
      |           ^~~~~~~~~~~~~~~~
%Warning-UNUSEDSIGNAL: pipelineIF_withFIFO.v:32:16: Signal is not used: 'sram_addr'
                                                  : ... In instance top.u_pipeline_withFIFO
   32 |     wire [9:0] sram_addr;
      |                ^~~~~~~~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: pipelineIF_withFIFO.v:33:10: Signal is not used: 'ceb'
                                                  : ... In instance top.u_pipeline_withFIFO
   33 |     wire ceb, web;
      |          ^~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: pipelineIF_withFIFO.v:33:15: Signal is not used: 'web'
                                                  : ... In instance top.u_pipeline_withFIFO
   33 |     wire ceb, web;
      |               ^~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: pipelineIF_withFIFO.v:44:17: Signal is not used: 'flush_delay'
                                                  : ... In instance top.u_pipeline_withFIFO
   44 |     reg         flush_delay;
      |                 ^~~~~~~~~~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: pipelineMEM_withloadstore.v:20:23: Bits of signal are not used: 'alu_calculation_e_i'[31:12]
                                                        : ... In instance top.u_pipelineMEM_withloadstore
   20 |     input wire [31:0] alu_calculation_e_i,
      |                       ^~~~~~~~~~~~~~~~~~~
%Warning-UNUSEDSIGNAL: pipelineWB.v:14:23: Signal is not used: 'clk'
                                         : ... In instance top.u_pipelineWB
   14 |     input wire        clk,
      |                       ^~~
%Warning-UNUSEDSIGNAL: pipelineWB.v:15:23: Signal is not used: 'resetn'
                                         : ... In instance top.u_pipelineWB
   15 |     input wire        resetn,
      |                       ^~~~~~
%Warning-UNUSEDSIGNAL: hazard.v:33:13: Signal is not used: 'ld_dst2'
                                     : ... In instance top.hu
   33 | reg ld_dst1,ld_dst2;
      |             ^~~~~~~
                       pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Warning-UNUSEDSIGNAL: hazard.v:38:9: Signal is not used: 'jd2'
                                    : ... In instance top.hu
   38 | reg jd1,jd2,jd_b1,jd_b2,jd_b3;
      |         ^~~
                       pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Warning-UNUSEDSIGNAL: hazard.v:38:25: Signal is not used: 'jd_b3'
                                     : ... In instance top.hu
   38 | reg jd1,jd2,jd_b1,jd_b2,jd_b3;
      |                         ^~~~~
                       pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Warning-UNUSEDSIGNAL: hazard.v:39:9: Signal is not used: 'bptrt'
                                    : ... In instance top.hu
   39 | reg bpt,bptrt,bptnt,bptnt1;
      |         ^~~~~
                       pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Warning-UNUSEDSIGNAL: hazard.v:39:21: Signal is not used: 'bptnt1'
                                     : ... In instance top.hu
   39 | reg bpt,bptrt,bptnt,bptnt1;
      |                     ^~~~~~
                       pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Warning-UNUSEDSIGNAL: hazard.v:40:14: Signal is not used: 'bnt2'
                                     : ... In instance top.hu
   40 | reg bnt,bnt1,bnt2;
      |              ^~~~
                       pipelineWB.v:40:1: ... note: In file included from pipelineWB.v
%Warning-UNUSEDSIGNAL: extendingUnit.v:27:23: Bits of signal are not used: 'instr_i'[6:0]
                                            : ... In instance top.u_pipelineID.u_extendingUnit
   27 |     input wire [31:0] instr_i,
      |                       ^~~~~~~
                       decoder.v:307:1: ... note: In file included from decoder.v
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: alu.v:14:11: Signal is not used: 'resetn'
                                  : ... In instance top.u_pipelineEXE.u_alu
   14 | input clk,resetn;
      |           ^~~~~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: memory_block.v:9:16: Signal is not used: 'resetn'
                                          : ... In instance top.u_pipelineMEM_withloadstore.u_dmemory.u_memory_block3
    9 |     input wire resetn,
      |                ^~~~~~
                       imemory.v:4:1: ... note: In file included from imemory.v
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: long_div.v:14:26: Signal is not used: 'e_last'
                                       : ... In instance top.u_pipelineEXE.u_alu.div
   14 | input d_init, e_advance, e_last;
      |                          ^~~~~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: long_div.v:24:22: Bits of signal are not used: 'sub3_pc'[34]
                                       : ... In instance top.u_pipelineEXE.u_alu.div
   24 | wire [34:0] sub3_ps, sub3_pc, rem_sub3;
      |                      ^~~~~~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: long_div.v:27:12: Bits of signal are not used: 'rem'[34:33]
                                       : ... In instance top.u_pipelineEXE.u_alu.div
   27 | reg [34:0] rem;
      |            ^~~
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
%Warning-UNUSEDSIGNAL: multi16.v:15:69: Bits of signal are not used: 'adder8'[16]
                                      : ... In instance top.u_pipelineEXE.u_alu.mul.m16
   15 | wire [16:0] adder0,adder1,adder2,adder3,adder4,adder5,adder6,adder7,adder8;
      |                                                                     ^~~~~~
                       long_div.v:92:1: ... note: In file included from long_div.v
                       pipelineIF_withFIFO.v:4:1: ... note: In file included from pipelineIF_withFIFO.v
                       top.v:12:1: ... note: In file included from top.v
