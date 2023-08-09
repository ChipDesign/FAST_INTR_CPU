// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgBit(oldp+0,(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay));
        tracep->chgBit(oldp+1,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__resetn_delay2));
        tracep->chgBit(oldp+2,(vlSelf->top__DOT__commit_en_exe));
        tracep->chgBit(oldp+3,(vlSelf->top__DOT__commit_en_mem));
        tracep->chgBit(oldp+4,(vlSelf->top__DOT__commit_en_wb));
        tracep->chgBit(oldp+5,(vlSelf->top__DOT__commit_en_delay));
        tracep->chgIData(oldp+6,(vlSelf->top__DOT__u_pipelineID__DOT__pc_instr),32);
        tracep->chgIData(oldp+7,(vlSelf->top__DOT__pc_instr_e_o),32);
        tracep->chgIData(oldp+8,(vlSelf->top__DOT__pc_instr_m_o),32);
        tracep->chgIData(oldp+9,(vlSelf->top__DOT__pc_instr_w_o),32);
        tracep->chgIData(oldp+10,(vlSelf->top__DOT__pc_instr_delay),32);
        tracep->chgBit(oldp+11,(vlSelf->top__DOT__u_pipelineID__DOT__fin));
        tracep->chgBit(oldp+12,(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken));
        tracep->chgBit(oldp+13,(vlSelf->top__DOT__hu__DOT__Dcmiss_st_keep));
        tracep->chgIData(oldp+14,(vlSelf->top__DOT__redirection_pc_e_o),32);
        tracep->chgBit(oldp+15,(vlSelf->top__DOT__redirection_e_o));
        tracep->chgBit(oldp+16,(vlSelf->top__DOT__ptnt_e_i));
        tracep->chgIData(oldp+17,(vlSelf->top__DOT__prediction_pc_d_o),32);
        tracep->chgIData(oldp+18,(vlSelf->top__DOT__alu_op_d_o),21);
        tracep->chgIData(oldp+19,(vlSelf->top__DOT__rs1_d_o),32);
        tracep->chgIData(oldp+20,(vlSelf->top__DOT__rs2_d_o),32);
        tracep->chgIData(oldp+21,(vlSelf->top__DOT__rs2_reg_d_o),32);
        tracep->chgCData(oldp+22,(vlSelf->top__DOT__dmem_type_d_o),4);
        tracep->chgIData(oldp+23,(vlSelf->top__DOT__extended_imm_d_o),32);
        tracep->chgIData(oldp+24,(vlSelf->top__DOT__pc_plus4_d_o),32);
        tracep->chgBit(oldp+25,(vlSelf->top__DOT__reg_write_en_d_o));
        tracep->chgCData(oldp+26,(vlSelf->top__DOT__rd_idx_d_o),5);
        tracep->chgCData(oldp+27,(vlSelf->top__DOT__resultSrc_d_o),4);
        tracep->chgBit(oldp+28,(vlSelf->top__DOT__instrIllegal_d_o));
        tracep->chgBit(oldp+29,(vlSelf->top__DOT__jalr_d_o));
        tracep->chgBit(oldp+30,(vlSelf->top__DOT__btype_d_o));
        tracep->chgBit(oldp+31,(vlSelf->top__DOT__flush_jal_d_o));
        tracep->chgCData(oldp+32,(vlSelf->top__DOT__mul_state_d_o),2);
        tracep->chgBit(oldp+33,(vlSelf->top__DOT__d_advance_d_o));
        tracep->chgBit(oldp+34,(vlSelf->top__DOT__d_init_d_o));
        tracep->chgBit(oldp+35,(vlSelf->top__DOT__div_last_d_o));
        tracep->chgBit(oldp+36,(vlSelf->top__DOT__hu__DOT__flush));
        tracep->chgBit(oldp+37,(vlSelf->top__DOT__fin_d_o));
        tracep->chgBit(oldp+38,(vlSelf->top__DOT__sbp_taken_d_o));
        tracep->chgIData(oldp+39,(vlSelf->top__DOT__aluResult_e_o),32);
        tracep->chgIData(oldp+40,(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation),32);
        tracep->chgIData(oldp+41,(vlSelf->top__DOT__extendedImm_e_o),32);
        tracep->chgIData(oldp+42,(vlSelf->top__DOT__pcPlus4_e_o),32);
        tracep->chgBit(oldp+43,(vlSelf->top__DOT__reg_write_en_e_o));
        tracep->chgCData(oldp+44,(vlSelf->top__DOT__rdIdx_e_o),5);
        tracep->chgCData(oldp+45,(vlSelf->top__DOT__resultSrc_e_o),4);
        tracep->chgBit(oldp+46,(vlSelf->top__DOT__instrIllegal_e_o));
        tracep->chgIData(oldp+47,(vlSelf->top__DOT__bypass_e_o),32);
        tracep->chgIData(oldp+48,(vlSelf->top__DOT__mem_read_data_m_o),32);
        tracep->chgIData(oldp+49,(vlSelf->top__DOT__alu_result_m_o),32);
        tracep->chgIData(oldp+50,(vlSelf->top__DOT__extended_imm_m_o),32);
        tracep->chgIData(oldp+51,(vlSelf->top__DOT__pc_plus4_m_o),32);
        tracep->chgBit(oldp+52,(vlSelf->top__DOT__reg_write_en_m_o));
        tracep->chgCData(oldp+53,(vlSelf->top__DOT__rd_idx_m_o),5);
        tracep->chgCData(oldp+54,(vlSelf->top__DOT__result_src_m_o),4);
        tracep->chgIData(oldp+55,(vlSelf->top__DOT__bypass_m_o),32);
        tracep->chgIData(oldp+56,(vlSelf->top__DOT__write_back_data_w_o),32);
        tracep->chgCData(oldp+57,(vlSelf->top__DOT__hu__DOT__dst_1),5);
        tracep->chgCData(oldp+58,(vlSelf->top__DOT__hu__DOT__dst_2),5);
        tracep->chgBit(oldp+59,(vlSelf->top__DOT__hu__DOT__ld_dst1));
        tracep->chgBit(oldp+60,(vlSelf->top__DOT__hu__DOT__ld_dst2));
        tracep->chgBit(oldp+61,(vlSelf->top__DOT__hu__DOT__Icmiss_st_keep));
        tracep->chgBit(oldp+62,(vlSelf->top__DOT__hu__DOT__Linst_st_keep));
        tracep->chgBit(oldp+63,(vlSelf->top__DOT__hu__DOT__jd1));
        tracep->chgBit(oldp+64,(vlSelf->top__DOT__hu__DOT__jd2));
        tracep->chgBit(oldp+65,(vlSelf->top__DOT__hu__DOT__jd_b1));
        tracep->chgBit(oldp+66,(vlSelf->top__DOT__hu__DOT__jd_b2));
        tracep->chgBit(oldp+67,(vlSelf->top__DOT__hu__DOT__jd_b3));
        tracep->chgBit(oldp+68,(vlSelf->top__DOT__hu__DOT__bpt));
        tracep->chgBit(oldp+69,(vlSelf->top__DOT__hu__DOT__bptrt));
        tracep->chgBit(oldp+70,(vlSelf->top__DOT__hu__DOT__bptnt));
        tracep->chgBit(oldp+71,(vlSelf->top__DOT__hu__DOT__bptnt1));
        tracep->chgBit(oldp+72,(vlSelf->top__DOT__hu__DOT__bnt));
        tracep->chgBit(oldp+73,(vlSelf->top__DOT__hu__DOT__bnt1));
        tracep->chgBit(oldp+74,(vlSelf->top__DOT__hu__DOT__bnt2));
        tracep->chgBit(oldp+75,(vlSelf->top__DOT__u_pipelineEXE__DOT__redirection_r));
        tracep->chgIData(oldp+76,(vlSelf->top__DOT__u_pipelineEXE__DOT__redirection_pc_r),32);
        tracep->chgBit(oldp+77,((1U & vlSelf->top__DOT__alu_op_d_o)));
        tracep->chgBit(oldp+78,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 1U))));
        tracep->chgBit(oldp+79,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 2U))));
        tracep->chgBit(oldp+80,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 3U))));
        tracep->chgBit(oldp+81,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 4U))));
        tracep->chgBit(oldp+82,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 5U))));
        tracep->chgBit(oldp+83,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 6U))));
        tracep->chgBit(oldp+84,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 7U))));
        tracep->chgBit(oldp+85,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 8U))));
        tracep->chgBit(oldp+86,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 9U))));
        tracep->chgBit(oldp+87,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0xaU))));
        tracep->chgBit(oldp+88,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0xbU))));
        tracep->chgBit(oldp+89,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0xdU))));
        tracep->chgBit(oldp+90,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0xcU))));
        tracep->chgBit(oldp+91,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0xeU))));
        tracep->chgBit(oldp+92,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0xfU))));
        tracep->chgBit(oldp+93,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0x10U))));
        tracep->chgBit(oldp+94,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0x11U))));
        tracep->chgBit(oldp+95,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0x12U))));
        tracep->chgBit(oldp+96,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0x13U))));
        tracep->chgBit(oldp+97,((1U & (vlSelf->top__DOT__alu_op_d_o 
                                       >> 0x14U))));
        tracep->chgIData(oldp+98,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft_ans),32);
        tracep->chgIData(oldp+99,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvd),32);
        tracep->chgIData(oldp+100,((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem)),32);
        tracep->chgIData(oldp+101,((((vlSelf->top__DOT__rs1_d_o 
                                      ^ vlSelf->top__DOT__rs2_d_o) 
                                     & (- (IData)((IData)(
                                                          (0U 
                                                           != 
                                                           (0xa0U 
                                                            & vlSelf->top__DOT__alu_op_d_o)))))) 
                                    | ((vlSelf->top__DOT__rs1_d_o 
                                        & vlSelf->top__DOT__rs2_d_o) 
                                       & (- (IData)((IData)(
                                                            (0U 
                                                             != 
                                                             (0x60U 
                                                              & vlSelf->top__DOT__alu_op_d_o)))))))),32);
        tracep->chgIData(oldp+102,((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans_temp)),32);
        tracep->chgIData(oldp+103,((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans_temp 
                                            >> 0x20U))),32);
        tracep->chgQData(oldp+104,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__add_ans),33);
        tracep->chgBit(oldp+106,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__div__unsign));
        tracep->chgBit(oldp+107,(((vlSelf->top__DOT__rs2_d_o 
                                   >> 0x1fU) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__div__unsign)))));
        tracep->chgBit(oldp+108,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dividend));
        tracep->chgIData(oldp+109,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs),32);
        tracep->chgBit(oldp+110,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dvs));
        tracep->chgBit(oldp+111,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dvd));
        tracep->chgBit(oldp+112,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot));
        tracep->chgQData(oldp+113,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt),35);
        tracep->chgQData(oldp+115,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub1),35);
        tracep->chgQData(oldp+117,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub2),35);
        tracep->chgQData(oldp+119,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps),35);
        tracep->chgQData(oldp+121,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc),35);
        tracep->chgQData(oldp+123,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub3),35);
        tracep->chgBit(oldp+125,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem1));
        tracep->chgBit(oldp+126,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem2));
        tracep->chgBit(oldp+127,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem3));
        tracep->chgBit(oldp+128,((1U ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem2) 
                                        ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))));
        tracep->chgBit(oldp+129,((1U & ((((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem1)) 
                                          & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem2)) 
                                         | (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem3))) 
                                        ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))));
        tracep->chgQData(oldp+130,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem),35);
        tracep->chgQData(oldp+132,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain),35);
        tracep->chgQData(oldp+134,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin),35);
        tracep->chgBit(oldp+136,((1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain))));
        tracep->chgBit(oldp+137,((1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin))));
        tracep->chgBit(oldp+138,((1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt))));
        tracep->chgBit(oldp+139,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa0__DOT__axorb) 
                                        ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt)))));
        tracep->chgBit(oldp+140,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa0__DOT__axorb)) 
                                        | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain) 
                                           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin))))));
        tracep->chgBit(oldp+141,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa0__DOT__axorb));
        tracep->chgBit(oldp+142,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 1U)))));
        tracep->chgBit(oldp+143,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 1U)))));
        tracep->chgBit(oldp+144,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 1U)))));
        tracep->chgBit(oldp+145,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa1__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 1U))))));
        tracep->chgBit(oldp+146,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 1U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa1__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 1U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 1U)))))));
        tracep->chgBit(oldp+147,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa1__DOT__axorb));
        tracep->chgBit(oldp+148,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0xaU)))));
        tracep->chgBit(oldp+149,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0xaU)))));
        tracep->chgBit(oldp+150,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xaU)))));
        tracep->chgBit(oldp+151,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa10__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0xaU))))));
        tracep->chgBit(oldp+152,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0xaU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa10__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0xaU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0xaU)))))));
        tracep->chgBit(oldp+153,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa10__DOT__axorb));
        tracep->chgBit(oldp+154,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0xbU)))));
        tracep->chgBit(oldp+155,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0xbU)))));
        tracep->chgBit(oldp+156,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xbU)))));
        tracep->chgBit(oldp+157,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa11__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0xbU))))));
        tracep->chgBit(oldp+158,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0xbU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa11__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0xbU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0xbU)))))));
        tracep->chgBit(oldp+159,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa11__DOT__axorb));
        tracep->chgBit(oldp+160,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0xcU)))));
        tracep->chgBit(oldp+161,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0xcU)))));
        tracep->chgBit(oldp+162,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xcU)))));
        tracep->chgBit(oldp+163,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa12__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0xcU))))));
        tracep->chgBit(oldp+164,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0xcU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa12__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0xcU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0xcU)))))));
        tracep->chgBit(oldp+165,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa12__DOT__axorb));
        tracep->chgBit(oldp+166,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0xdU)))));
        tracep->chgBit(oldp+167,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0xdU)))));
        tracep->chgBit(oldp+168,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xdU)))));
        tracep->chgBit(oldp+169,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa13__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0xdU))))));
        tracep->chgBit(oldp+170,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0xdU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa13__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0xdU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0xdU)))))));
        tracep->chgBit(oldp+171,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa13__DOT__axorb));
        tracep->chgBit(oldp+172,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0xeU)))));
        tracep->chgBit(oldp+173,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0xeU)))));
        tracep->chgBit(oldp+174,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xeU)))));
        tracep->chgBit(oldp+175,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa14__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0xeU))))));
        tracep->chgBit(oldp+176,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0xeU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa14__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0xeU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0xeU)))))));
        tracep->chgBit(oldp+177,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa14__DOT__axorb));
        tracep->chgBit(oldp+178,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0xfU)))));
        tracep->chgBit(oldp+179,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0xfU)))));
        tracep->chgBit(oldp+180,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xfU)))));
        tracep->chgBit(oldp+181,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa15__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0xfU))))));
        tracep->chgBit(oldp+182,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0xfU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa15__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0xfU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0xfU)))))));
        tracep->chgBit(oldp+183,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa15__DOT__axorb));
        tracep->chgBit(oldp+184,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x10U)))));
        tracep->chgBit(oldp+185,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x10U)))));
        tracep->chgBit(oldp+186,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x10U)))));
        tracep->chgBit(oldp+187,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa16__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x10U))))));
        tracep->chgBit(oldp+188,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x10U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa16__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x10U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x10U)))))));
        tracep->chgBit(oldp+189,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa16__DOT__axorb));
        tracep->chgBit(oldp+190,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x11U)))));
        tracep->chgBit(oldp+191,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x11U)))));
        tracep->chgBit(oldp+192,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x11U)))));
        tracep->chgBit(oldp+193,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa17__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x11U))))));
        tracep->chgBit(oldp+194,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x11U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa17__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x11U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x11U)))))));
        tracep->chgBit(oldp+195,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa17__DOT__axorb));
        tracep->chgBit(oldp+196,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x12U)))));
        tracep->chgBit(oldp+197,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x12U)))));
        tracep->chgBit(oldp+198,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x12U)))));
        tracep->chgBit(oldp+199,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa18__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x12U))))));
        tracep->chgBit(oldp+200,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x12U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa18__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x12U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x12U)))))));
        tracep->chgBit(oldp+201,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa18__DOT__axorb));
        tracep->chgBit(oldp+202,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x13U)))));
        tracep->chgBit(oldp+203,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x13U)))));
        tracep->chgBit(oldp+204,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x13U)))));
        tracep->chgBit(oldp+205,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa19__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x13U))))));
        tracep->chgBit(oldp+206,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x13U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa19__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x13U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x13U)))))));
        tracep->chgBit(oldp+207,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa19__DOT__axorb));
        tracep->chgBit(oldp+208,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 2U)))));
        tracep->chgBit(oldp+209,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 2U)))));
        tracep->chgBit(oldp+210,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 2U)))));
        tracep->chgBit(oldp+211,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa2__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 2U))))));
        tracep->chgBit(oldp+212,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 2U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa2__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 2U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 2U)))))));
        tracep->chgBit(oldp+213,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa2__DOT__axorb));
        tracep->chgBit(oldp+214,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x14U)))));
        tracep->chgBit(oldp+215,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x14U)))));
        tracep->chgBit(oldp+216,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x14U)))));
        tracep->chgBit(oldp+217,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa20__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x14U))))));
        tracep->chgBit(oldp+218,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x14U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa20__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x14U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x14U)))))));
        tracep->chgBit(oldp+219,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa20__DOT__axorb));
        tracep->chgBit(oldp+220,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x15U)))));
        tracep->chgBit(oldp+221,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x15U)))));
        tracep->chgBit(oldp+222,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x15U)))));
        tracep->chgBit(oldp+223,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa21__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x15U))))));
        tracep->chgBit(oldp+224,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x15U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa21__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x15U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x15U)))))));
        tracep->chgBit(oldp+225,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa21__DOT__axorb));
        tracep->chgBit(oldp+226,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x16U)))));
        tracep->chgBit(oldp+227,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x16U)))));
        tracep->chgBit(oldp+228,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x16U)))));
        tracep->chgBit(oldp+229,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa22__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x16U))))));
        tracep->chgBit(oldp+230,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x16U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa22__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x16U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x16U)))))));
        tracep->chgBit(oldp+231,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa22__DOT__axorb));
        tracep->chgBit(oldp+232,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x17U)))));
        tracep->chgBit(oldp+233,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x17U)))));
        tracep->chgBit(oldp+234,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x17U)))));
        tracep->chgBit(oldp+235,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa23__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x17U))))));
        tracep->chgBit(oldp+236,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x17U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa23__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x17U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x17U)))))));
        tracep->chgBit(oldp+237,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa23__DOT__axorb));
        tracep->chgBit(oldp+238,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x18U)))));
        tracep->chgBit(oldp+239,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x18U)))));
        tracep->chgBit(oldp+240,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x18U)))));
        tracep->chgBit(oldp+241,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa24__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x18U))))));
        tracep->chgBit(oldp+242,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x18U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa24__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x18U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x18U)))))));
        tracep->chgBit(oldp+243,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa24__DOT__axorb));
        tracep->chgBit(oldp+244,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x19U)))));
        tracep->chgBit(oldp+245,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x19U)))));
        tracep->chgBit(oldp+246,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x19U)))));
        tracep->chgBit(oldp+247,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa25__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x19U))))));
        tracep->chgBit(oldp+248,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x19U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa25__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x19U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x19U)))))));
        tracep->chgBit(oldp+249,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa25__DOT__axorb));
        tracep->chgBit(oldp+250,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x1aU)))));
        tracep->chgBit(oldp+251,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1aU)))));
        tracep->chgBit(oldp+252,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1aU)))));
        tracep->chgBit(oldp+253,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa26__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x1aU))))));
        tracep->chgBit(oldp+254,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x1aU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa26__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x1aU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x1aU)))))));
        tracep->chgBit(oldp+255,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa26__DOT__axorb));
        tracep->chgBit(oldp+256,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x1bU)))));
        tracep->chgBit(oldp+257,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1bU)))));
        tracep->chgBit(oldp+258,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1bU)))));
        tracep->chgBit(oldp+259,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa27__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x1bU))))));
        tracep->chgBit(oldp+260,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x1bU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa27__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x1bU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x1bU)))))));
        tracep->chgBit(oldp+261,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa27__DOT__axorb));
        tracep->chgBit(oldp+262,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x1cU)))));
        tracep->chgBit(oldp+263,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1cU)))));
        tracep->chgBit(oldp+264,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1cU)))));
        tracep->chgBit(oldp+265,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa28__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x1cU))))));
        tracep->chgBit(oldp+266,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x1cU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa28__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x1cU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x1cU)))))));
        tracep->chgBit(oldp+267,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa28__DOT__axorb));
        tracep->chgBit(oldp+268,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x1dU)))));
        tracep->chgBit(oldp+269,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1dU)))));
        tracep->chgBit(oldp+270,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1dU)))));
        tracep->chgBit(oldp+271,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa29__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x1dU))))));
        tracep->chgBit(oldp+272,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x1dU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa29__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x1dU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x1dU)))))));
        tracep->chgBit(oldp+273,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa29__DOT__axorb));
        tracep->chgBit(oldp+274,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 3U)))));
        tracep->chgBit(oldp+275,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 3U)))));
        tracep->chgBit(oldp+276,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 3U)))));
        tracep->chgBit(oldp+277,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa3__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 3U))))));
        tracep->chgBit(oldp+278,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 3U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa3__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 3U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 3U)))))));
        tracep->chgBit(oldp+279,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa3__DOT__axorb));
        tracep->chgBit(oldp+280,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x1eU)))));
        tracep->chgBit(oldp+281,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1eU)))));
        tracep->chgBit(oldp+282,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1eU)))));
        tracep->chgBit(oldp+283,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa30__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x1eU))))));
        tracep->chgBit(oldp+284,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x1eU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa30__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x1eU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x1eU)))))));
        tracep->chgBit(oldp+285,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa30__DOT__axorb));
        tracep->chgBit(oldp+286,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x1fU)))));
        tracep->chgBit(oldp+287,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1fU)))));
        tracep->chgBit(oldp+288,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1fU)))));
        tracep->chgBit(oldp+289,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa31__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x1fU))))));
        tracep->chgBit(oldp+290,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x1fU)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa31__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x1fU)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x1fU)))))));
        tracep->chgBit(oldp+291,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa31__DOT__axorb));
        tracep->chgBit(oldp+292,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x20U)))));
        tracep->chgBit(oldp+293,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x20U)))));
        tracep->chgBit(oldp+294,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x20U)))));
        tracep->chgBit(oldp+295,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa32__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x20U))))));
        tracep->chgBit(oldp+296,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x20U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa32__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x20U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x20U)))))));
        tracep->chgBit(oldp+297,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa32__DOT__axorb));
        tracep->chgBit(oldp+298,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x21U)))));
        tracep->chgBit(oldp+299,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x21U)))));
        tracep->chgBit(oldp+300,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x21U)))));
        tracep->chgBit(oldp+301,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa33__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 0x21U))))));
        tracep->chgBit(oldp+302,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x21U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa33__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x21U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x21U)))))));
        tracep->chgBit(oldp+303,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa33__DOT__axorb));
        tracep->chgBit(oldp+304,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 0x22U)))));
        tracep->chgBit(oldp+305,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x22U)))));
        tracep->chgBit(oldp+306,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x22U)))));
        tracep->chgBit(oldp+307,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa34__DOT__axorb) 
                                  ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                     >> 0x22U))));
        tracep->chgBit(oldp+308,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 0x22U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa34__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 0x22U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 0x22U)))))));
        tracep->chgBit(oldp+309,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa34__DOT__axorb));
        tracep->chgBit(oldp+310,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 4U)))));
        tracep->chgBit(oldp+311,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 4U)))));
        tracep->chgBit(oldp+312,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 4U)))));
        tracep->chgBit(oldp+313,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa4__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 4U))))));
        tracep->chgBit(oldp+314,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 4U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa4__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 4U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 4U)))))));
        tracep->chgBit(oldp+315,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa4__DOT__axorb));
        tracep->chgBit(oldp+316,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 5U)))));
        tracep->chgBit(oldp+317,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 5U)))));
        tracep->chgBit(oldp+318,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 5U)))));
        tracep->chgBit(oldp+319,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa5__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 5U))))));
        tracep->chgBit(oldp+320,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 5U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa5__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 5U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 5U)))))));
        tracep->chgBit(oldp+321,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa5__DOT__axorb));
        tracep->chgBit(oldp+322,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 6U)))));
        tracep->chgBit(oldp+323,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 6U)))));
        tracep->chgBit(oldp+324,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 6U)))));
        tracep->chgBit(oldp+325,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa6__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 6U))))));
        tracep->chgBit(oldp+326,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 6U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa6__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 6U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 6U)))))));
        tracep->chgBit(oldp+327,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa6__DOT__axorb));
        tracep->chgBit(oldp+328,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 7U)))));
        tracep->chgBit(oldp+329,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 7U)))));
        tracep->chgBit(oldp+330,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 7U)))));
        tracep->chgBit(oldp+331,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa7__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 7U))))));
        tracep->chgBit(oldp+332,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 7U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa7__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 7U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 7U)))))));
        tracep->chgBit(oldp+333,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa7__DOT__axorb));
        tracep->chgBit(oldp+334,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 8U)))));
        tracep->chgBit(oldp+335,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 8U)))));
        tracep->chgBit(oldp+336,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 8U)))));
        tracep->chgBit(oldp+337,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa8__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 8U))))));
        tracep->chgBit(oldp+338,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 8U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa8__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 8U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 8U)))))));
        tracep->chgBit(oldp+339,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa8__DOT__axorb));
        tracep->chgBit(oldp+340,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                >> 9U)))));
        tracep->chgBit(oldp+341,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 9U)))));
        tracep->chgBit(oldp+342,((1U & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 9U)))));
        tracep->chgBit(oldp+343,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa9__DOT__axorb) 
                                        ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                   >> 9U))))));
        tracep->chgBit(oldp+344,((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                  >> 9U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa9__DOT__axorb)) 
                                        | ((IData)(
                                                   (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                    >> 9U)) 
                                           & (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                      >> 9U)))))));
        tracep->chgBit(oldp+345,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa9__DOT__axorb));
        tracep->chgBit(oldp+346,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss));
        tracep->chgQData(oldp+347,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans_temp),64);
        tracep->chgBit(oldp+349,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__sign));
        tracep->chgBit(oldp+350,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu));
        tracep->chgBit(oldp+351,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us));
        tracep->chgBit(oldp+352,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16su));
        tracep->chgBit(oldp+353,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss) 
                                  & (3U == (IData)(vlSelf->top__DOT__mul_state_d_o)))));
        tracep->chgSData(oldp+354,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain),16);
        tracep->chgSData(oldp+355,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin),16);
        tracep->chgIData(oldp+356,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ans),32);
        tracep->chgIData(oldp+357,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0),17);
        tracep->chgIData(oldp+358,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1),17);
        tracep->chgIData(oldp+359,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2),17);
        tracep->chgIData(oldp+360,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3),17);
        tracep->chgIData(oldp+361,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4),17);
        tracep->chgIData(oldp+362,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5),17);
        tracep->chgIData(oldp+363,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6),17);
        tracep->chgIData(oldp+364,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7),17);
        tracep->chgIData(oldp+365,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8),17);
        tracep->chgCData(oldp+366,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg),8);
        tracep->chgCData(oldp+367,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign),8);
        tracep->chgIData(oldp+368,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1),31);
        tracep->chgIData(oldp+369,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2),31);
        tracep->chgIData(oldp+370,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans),32);
        tracep->chgBit(oldp+371,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s5_0_0));
        tracep->chgBit(oldp+372,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w3));
        tracep->chgBit(oldp+373,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s7_0_0));
        tracep->chgBit(oldp+374,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_0));
        tracep->chgBit(oldp+375,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_1));
        tracep->chgBit(oldp+376,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s9_0_0));
        tracep->chgBit(oldp+377,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w3) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_0_0))));
        tracep->chgBit(oldp+378,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s10_0_1));
        tracep->chgBit(oldp+379,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s11_0_0));
        tracep->chgBit(oldp+380,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                         >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                                   >> 1U)))));
        tracep->chgBit(oldp+381,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s12_0_0));
        tracep->chgBit(oldp+382,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w3));
        tracep->chgBit(oldp+383,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_0));
        tracep->chgBit(oldp+384,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_1));
        tracep->chgBit(oldp+385,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w3) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_0_0))));
        tracep->chgBit(oldp+386,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3));
        tracep->chgBit(oldp+387,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_0));
        tracep->chgBit(oldp+388,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_1));
        tracep->chgBit(oldp+389,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_0));
        tracep->chgBit(oldp+390,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_1));
        tracep->chgBit(oldp+391,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_0));
        tracep->chgBit(oldp+392,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_1));
        tracep->chgBit(oldp+393,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_2));
        tracep->chgBit(oldp+394,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_0));
        tracep->chgBit(oldp+395,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_1));
        tracep->chgBit(oldp+396,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_0));
        tracep->chgBit(oldp+397,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_1));
        tracep->chgBit(oldp+398,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_0));
        tracep->chgBit(oldp+399,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_1));
        tracep->chgBit(oldp+400,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_0));
        tracep->chgBit(oldp+401,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_1));
        tracep->chgBit(oldp+402,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_0_0));
        tracep->chgBit(oldp+403,((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb)))));
        tracep->chgBit(oldp+404,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_0));
        tracep->chgBit(oldp+405,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_1));
        tracep->chgBit(oldp+406,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_0_0));
        tracep->chgBit(oldp+407,((1U & (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                           >> 8U)))));
        tracep->chgBit(oldp+408,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_0_0));
        tracep->chgBit(oldp+409,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_0_0));
        tracep->chgBit(oldp+410,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_0_0));
        tracep->chgBit(oldp+411,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_0_0));
        tracep->chgBit(oldp+412,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_0_0));
        tracep->chgBit(oldp+413,((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb)))));
        tracep->chgBit(oldp+414,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_0));
        tracep->chgBit(oldp+415,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_1));
        tracep->chgBit(oldp+416,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c5_0_0));
        tracep->chgBit(oldp+417,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c6_0_0));
        tracep->chgBit(oldp+418,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c7_0_0));
        tracep->chgBit(oldp+419,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w3)
                                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct7_0_0)
                                         : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                            >> 2U)))));
        tracep->chgBit(oldp+420,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c8_0_1));
        tracep->chgBit(oldp+421,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c9_0_0));
        tracep->chgBit(oldp+422,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_0));
        tracep->chgBit(oldp+423,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_1));
        tracep->chgBit(oldp+424,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c11_0_0));
        tracep->chgBit(oldp+425,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                         >> 3U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                                   >> 1U)))));
        tracep->chgBit(oldp+426,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_0));
        tracep->chgBit(oldp+427,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w1)
                                         ? vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6
                                         : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                            >> 4U)))));
        tracep->chgBit(oldp+428,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_2));
        tracep->chgBit(oldp+429,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_0));
        tracep->chgBit(oldp+430,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_1));
        tracep->chgBit(oldp+431,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_0_0));
        tracep->chgBit(oldp+432,((1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3)) 
                                        & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7))));
        tracep->chgBit(oldp+433,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w3)
                                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_0)
                                         : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                            >> 9U)))));
        tracep->chgBit(oldp+434,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_0_1));
        tracep->chgBit(oldp+435,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_0_0));
        tracep->chgBit(oldp+436,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w3)
                                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_1)
                                         : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                            >> 2U)))));
        tracep->chgBit(oldp+437,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_0));
        tracep->chgBit(oldp+438,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_1));
        tracep->chgBit(oldp+439,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_2));
        tracep->chgBit(oldp+440,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_0_0));
        tracep->chgBit(oldp+441,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w3)
                                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_1)
                                         : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                            >> 2U)))));
        tracep->chgBit(oldp+442,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_0_0));
        tracep->chgBit(oldp+443,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w3)
                                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_1)
                                         : (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                               >> 1U))))));
        tracep->chgBit(oldp+444,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_0));
        tracep->chgBit(oldp+445,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w1)
                                         ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                            >> 4U) : 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 8U)))));
        tracep->chgBit(oldp+446,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_2));
        tracep->chgBit(oldp+447,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_0_0));
        tracep->chgBit(oldp+448,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                             >> 2U)) 
                                         & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_0_1__DOT__axorb)) 
                                        | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                            >> 7U) 
                                           & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                              >> 5U))))));
        tracep->chgBit(oldp+449,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_0_0));
        tracep->chgBit(oldp+450,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb) 
                                        | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                            >> 8U) 
                                           & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                              >> 6U))))));
        tracep->chgBit(oldp+451,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_0_0));
        tracep->chgBit(oldp+452,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                         >> 7U) & (~ 
                                                   ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                                    >> 3U))))));
        tracep->chgBit(oldp+453,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w3)
                                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_0_0)
                                         : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                            >> 0xaU)))));
        tracep->chgBit(oldp+454,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 8U))));
        tracep->chgBit(oldp+455,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_0_0));
        tracep->chgBit(oldp+456,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_0_0));
        tracep->chgBit(oldp+457,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_0_0));
        tracep->chgBit(oldp+458,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_0));
        tracep->chgBit(oldp+459,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_1));
        tracep->chgBit(oldp+460,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_0_0));
        tracep->chgBit(oldp+461,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb) 
                                        | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                            >> 0x10U) 
                                           & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                              >> 0xeU))))));
        tracep->chgBit(oldp+462,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_1_0));
        tracep->chgBit(oldp+463,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s14_1_0));
        tracep->chgBit(oldp+464,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_1_0));
        tracep->chgBit(oldp+465,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_1_0));
        tracep->chgBit(oldp+466,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_1_0));
        tracep->chgBit(oldp+467,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_0));
        tracep->chgBit(oldp+468,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_1));
        tracep->chgBit(oldp+469,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_1_0));
        tracep->chgBit(oldp+470,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_1_0));
        tracep->chgBit(oldp+471,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_1_0));
        tracep->chgBit(oldp+472,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_1_0));
        tracep->chgBit(oldp+473,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_1_0));
        tracep->chgBit(oldp+474,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_1_0));
        tracep->chgBit(oldp+475,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_1_0));
        tracep->chgBit(oldp+476,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_1_0));
        tracep->chgBit(oldp+477,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_1_0));
        tracep->chgBit(oldp+478,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_1_0));
        tracep->chgBit(oldp+479,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_1_0));
        tracep->chgBit(oldp+480,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s30_1_0));
        tracep->chgBit(oldp+481,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_1_0));
        tracep->chgBit(oldp+482,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_1_0));
        tracep->chgBit(oldp+483,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_1_0));
        tracep->chgBit(oldp+484,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_1_0));
        tracep->chgBit(oldp+485,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_1_0));
        tracep->chgBit(oldp+486,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_1_0));
        tracep->chgBit(oldp+487,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_0));
        tracep->chgBit(oldp+488,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_1));
        tracep->chgBit(oldp+489,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_1_0));
        tracep->chgBit(oldp+490,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_1_0));
        tracep->chgBit(oldp+491,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_1_0));
        tracep->chgBit(oldp+492,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_1_0));
        tracep->chgBit(oldp+493,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_1_0));
        tracep->chgBit(oldp+494,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c24_1_0));
        tracep->chgBit(oldp+495,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_0));
        tracep->chgBit(oldp+496,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_1));
        tracep->chgBit(oldp+497,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_1_0));
        tracep->chgBit(oldp+498,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_1_0));
        tracep->chgBit(oldp+499,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_1_0));
        tracep->chgBit(oldp+500,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_1_0));
        tracep->chgBit(oldp+501,(((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb)) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_0_0))));
        tracep->chgBit(oldp+502,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s30_1_0))));
        tracep->chgBit(oldp+503,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct6_0_0));
        tracep->chgBit(oldp+504,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct7_0_0));
        tracep->chgBit(oldp+505,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct8_0_0));
        tracep->chgBit(oldp+506,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_0_0));
        tracep->chgBit(oldp+507,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_0_0));
        tracep->chgBit(oldp+508,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_0_0));
        tracep->chgBit(oldp+509,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_0_0));
        tracep->chgBit(oldp+510,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_0_0));
        tracep->chgBit(oldp+511,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_0));
        tracep->chgBit(oldp+512,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_0));
        tracep->chgBit(oldp+513,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_0));
        tracep->chgBit(oldp+514,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_0));
        tracep->chgBit(oldp+515,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_0));
        tracep->chgBit(oldp+516,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_0));
        tracep->chgBit(oldp+517,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_0_0));
        tracep->chgBit(oldp+518,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_0_0));
        tracep->chgBit(oldp+519,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_0_0));
        tracep->chgBit(oldp+520,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_0_0));
        tracep->chgBit(oldp+521,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_0_0));
        tracep->chgBit(oldp+522,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct25_0_0));
        tracep->chgBit(oldp+523,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct26_0_0));
        tracep->chgBit(oldp+524,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct27_0_0));
        tracep->chgBit(oldp+525,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_1));
        tracep->chgBit(oldp+526,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_1));
        tracep->chgBit(oldp+527,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_1));
        tracep->chgBit(oldp+528,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_1));
        tracep->chgBit(oldp+529,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_1));
        tracep->chgBit(oldp+530,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_1));
        tracep->chgBit(oldp+531,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_1_0));
        tracep->chgBit(oldp+532,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_1_0));
        tracep->chgBit(oldp+533,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_1_0));
        tracep->chgBit(oldp+534,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_1_0));
        tracep->chgBit(oldp+535,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_1_0));
        tracep->chgBit(oldp+536,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_1_0));
        tracep->chgBit(oldp+537,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_1_0));
        tracep->chgBit(oldp+538,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_1_0));
        tracep->chgBit(oldp+539,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_1_0));
        tracep->chgBit(oldp+540,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_1_0));
        tracep->chgBit(oldp+541,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_1_0));
        tracep->chgBit(oldp+542,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_1_0));
        tracep->chgBit(oldp+543,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_1_0));
        tracep->chgBit(oldp+544,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_1_0));
        tracep->chgBit(oldp+545,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_1_0));
        tracep->chgBit(oldp+546,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_1_0));
        tracep->chgCData(oldp+547,((6U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          << 1U))),3);
        tracep->chgBit(oldp+548,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                  | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))));
        tracep->chgBit(oldp+549,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__s));
        tracep->chgBit(oldp+550,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 1U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__zero))))));
        tracep->chgSData(oldp+551,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__mcand_comp),16);
        tracep->chgBit(oldp+552,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__zero));
        tracep->chgBit(oldp+553,((1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))));
        tracep->chgBit(oldp+554,((IData)((2U == (3U 
                                                 & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+555,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 1U))));
        tracep->chgCData(oldp+556,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 1U))),3);
        tracep->chgBit(oldp+557,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__s));
        tracep->chgBit(oldp+558,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 3U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__zero))))));
        tracep->chgSData(oldp+559,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__mcand_comp),16);
        tracep->chgBit(oldp+560,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__zero));
        tracep->chgBit(oldp+561,((1U & VL_REDXOR_4(
                                                   (6U 
                                                    & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+562,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 2U)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 1U)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 3U) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 1U))))));
        tracep->chgBit(oldp+563,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 3U))));
        tracep->chgCData(oldp+564,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 3U))),3);
        tracep->chgBit(oldp+565,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__s));
        tracep->chgBit(oldp+566,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 5U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__zero))))));
        tracep->chgSData(oldp+567,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__mcand_comp),16);
        tracep->chgBit(oldp+568,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__zero));
        tracep->chgBit(oldp+569,((1U & VL_REDXOR_8(
                                                   (0x18U 
                                                    & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+570,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 4U)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 3U)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 5U) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 3U))))));
        tracep->chgBit(oldp+571,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 5U))));
        tracep->chgCData(oldp+572,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 5U))),3);
        tracep->chgBit(oldp+573,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__s));
        tracep->chgBit(oldp+574,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 7U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__zero))))));
        tracep->chgSData(oldp+575,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__mcand_comp),16);
        tracep->chgBit(oldp+576,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__zero));
        tracep->chgBit(oldp+577,((1U & VL_REDXOR_8(
                                                   (0x60U 
                                                    & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+578,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 6U)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 5U)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 7U) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 5U))))));
        tracep->chgBit(oldp+579,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 7U))));
        tracep->chgCData(oldp+580,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 7U))),3);
        tracep->chgBit(oldp+581,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__s));
        tracep->chgBit(oldp+582,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 9U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__zero))))));
        tracep->chgSData(oldp+583,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__mcand_comp),16);
        tracep->chgBit(oldp+584,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__zero));
        tracep->chgBit(oldp+585,((1U & VL_REDXOR_16(
                                                    (0x180U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+586,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 8U)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 7U)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 9U) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 7U))))));
        tracep->chgBit(oldp+587,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 9U))));
        tracep->chgCData(oldp+588,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 9U))),3);
        tracep->chgBit(oldp+589,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__s));
        tracep->chgBit(oldp+590,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 0xbU) & 
                                        (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__zero))))));
        tracep->chgSData(oldp+591,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__mcand_comp),16);
        tracep->chgBit(oldp+592,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__zero));
        tracep->chgBit(oldp+593,((1U & VL_REDXOR_16(
                                                    (0x600U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+594,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 0xaU)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 9U)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 0xbU) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 9U))))));
        tracep->chgBit(oldp+595,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 0xbU))));
        tracep->chgCData(oldp+596,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 0xbU))),3);
        tracep->chgBit(oldp+597,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__s));
        tracep->chgBit(oldp+598,((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                         >> 0xdU) & 
                                        (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__zero))))));
        tracep->chgSData(oldp+599,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__mcand_comp),16);
        tracep->chgBit(oldp+600,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__zero));
        tracep->chgBit(oldp+601,((1U & VL_REDXOR_16(
                                                    (0x1800U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+602,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 0xcU)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 0xbU)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 0xdU) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 0xbU))))));
        tracep->chgBit(oldp+603,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 0xdU))));
        tracep->chgCData(oldp+604,((7U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                          >> 0xdU))),3);
        tracep->chgBit(oldp+605,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__s));
        tracep->chgBit(oldp+606,((IData)((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                           >> 0xfU) 
                                          & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__zero))))));
        tracep->chgSData(oldp+607,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__mcand_comp),16);
        tracep->chgBit(oldp+608,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__zero));
        tracep->chgBit(oldp+609,((1U & VL_REDXOR_16(
                                                    (0x6000U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))))));
        tracep->chgBit(oldp+610,((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                             >> 0xeU)) 
                                         ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 0xdU)) 
                                        & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                            >> 0xfU) 
                                           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 0xdU))))));
        tracep->chgBit(oldp+611,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 0xfU))));
        tracep->chgBit(oldp+612,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0xaU))));
        tracep->chgBit(oldp+613,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 8U))));
        tracep->chgBit(oldp+614,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 6U))));
        tracep->chgBit(oldp+615,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 4U))));
        tracep->chgBit(oldp+616,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w1));
        tracep->chgBit(oldp+617,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 6U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 4U)))));
        tracep->chgBit(oldp+618,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w3));
        tracep->chgBit(oldp+619,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w3) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_1_0))));
        tracep->chgBit(oldp+620,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w3) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_1_0))));
        tracep->chgBit(oldp+621,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w1));
        tracep->chgBit(oldp+622,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w3));
        tracep->chgBit(oldp+623,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0xbU))));
        tracep->chgBit(oldp+624,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 9U))));
        tracep->chgBit(oldp+625,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 7U))));
        tracep->chgBit(oldp+626,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 5U))));
        tracep->chgBit(oldp+627,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w1));
        tracep->chgBit(oldp+628,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 7U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 5U)))));
        tracep->chgBit(oldp+629,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w3));
        tracep->chgBit(oldp+630,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w3) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_1_0))));
        tracep->chgBit(oldp+631,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w3)
                                   ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_1_0)
                                   : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_1))));
        tracep->chgBit(oldp+632,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w1));
        tracep->chgBit(oldp+633,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_1))));
        tracep->chgBit(oldp+634,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w3));
        tracep->chgBit(oldp+635,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0xcU))));
        tracep->chgBit(oldp+636,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0xaU))));
        tracep->chgBit(oldp+637,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 8U))));
        tracep->chgBit(oldp+638,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 6U))));
        tracep->chgBit(oldp+639,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w1));
        tracep->chgBit(oldp+640,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 6U)))));
        tracep->chgBit(oldp+641,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w3));
        tracep->chgBit(oldp+642,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 4U))));
        tracep->chgBit(oldp+643,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 2U))));
        tracep->chgBit(oldp+644,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6)));
        tracep->chgBit(oldp+645,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 6U))));
        tracep->chgBit(oldp+646,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w1));
        tracep->chgBit(oldp+647,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                           >> 6U)))));
        tracep->chgBit(oldp+648,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w3) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_1_0))));
        tracep->chgBit(oldp+649,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w1));
        tracep->chgBit(oldp+650,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s12_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w3))));
        tracep->chgBit(oldp+651,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w3));
        tracep->chgBit(oldp+652,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0xdU))));
        tracep->chgBit(oldp+653,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0xbU))));
        tracep->chgBit(oldp+654,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 9U))));
        tracep->chgBit(oldp+655,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 7U))));
        tracep->chgBit(oldp+656,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w1));
        tracep->chgBit(oldp+657,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 9U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 7U)))));
        tracep->chgBit(oldp+658,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w3));
        tracep->chgBit(oldp+659,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w1));
        tracep->chgBit(oldp+660,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_2) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_0))));
        tracep->chgBit(oldp+661,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w3));
        tracep->chgBit(oldp+662,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0xeU))));
        tracep->chgBit(oldp+663,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0xcU))));
        tracep->chgBit(oldp+664,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0xaU))));
        tracep->chgBit(oldp+665,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 8U))));
        tracep->chgBit(oldp+666,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w1));
        tracep->chgBit(oldp+667,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 0xaU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                         >> 8U)))));
        tracep->chgBit(oldp+668,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w3));
        tracep->chgBit(oldp+669,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 6U))));
        tracep->chgBit(oldp+670,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 4U))));
        tracep->chgBit(oldp+671,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 2U))));
        tracep->chgBit(oldp+672,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7)));
        tracep->chgBit(oldp+673,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w1));
        tracep->chgBit(oldp+674,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 2U) ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7))));
        tracep->chgBit(oldp+675,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 7U))));
        tracep->chgBit(oldp+676,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w1));
        tracep->chgBit(oldp+677,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_0))));
        tracep->chgBit(oldp+678,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w3));
        tracep->chgBit(oldp+679,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0xfU))));
        tracep->chgBit(oldp+680,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0xdU))));
        tracep->chgBit(oldp+681,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0xbU))));
        tracep->chgBit(oldp+682,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 9U))));
        tracep->chgBit(oldp+683,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w1));
        tracep->chgBit(oldp+684,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 0xbU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                         >> 9U)))));
        tracep->chgBit(oldp+685,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w3));
        tracep->chgBit(oldp+686,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 7U))));
        tracep->chgBit(oldp+687,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 5U))));
        tracep->chgBit(oldp+688,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 3U))));
        tracep->chgBit(oldp+689,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 1U))));
        tracep->chgBit(oldp+690,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w1));
        tracep->chgBit(oldp+691,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                                   >> 1U)))));
        tracep->chgBit(oldp+692,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w3));
        tracep->chgBit(oldp+693,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w1));
        tracep->chgBit(oldp+694,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_1))));
        tracep->chgBit(oldp+695,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w3));
        tracep->chgBit(oldp+696,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 0x10U))));
        tracep->chgBit(oldp+697,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0xeU))));
        tracep->chgBit(oldp+698,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0xcU))));
        tracep->chgBit(oldp+699,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0xaU))));
        tracep->chgBit(oldp+700,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w1));
        tracep->chgBit(oldp+701,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 0xcU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                         >> 0xaU)))));
        tracep->chgBit(oldp+702,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w3));
        tracep->chgBit(oldp+703,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 8U))));
        tracep->chgBit(oldp+704,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 6U))));
        tracep->chgBit(oldp+705,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 4U))));
        tracep->chgBit(oldp+706,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 2U))));
        tracep->chgBit(oldp+707,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w1));
        tracep->chgBit(oldp+708,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                                   >> 2U)))));
        tracep->chgBit(oldp+709,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w3));
        tracep->chgBit(oldp+710,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8)));
        tracep->chgBit(oldp+711,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w1));
        tracep->chgBit(oldp+712,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_0_1) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_0))));
        tracep->chgBit(oldp+713,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w3));
        tracep->chgBit(oldp+714,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0xfU))));
        tracep->chgBit(oldp+715,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0xdU))));
        tracep->chgBit(oldp+716,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0xbU))));
        tracep->chgBit(oldp+717,((1U & (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                           >> 0xfU)))));
        tracep->chgBit(oldp+718,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 0xdU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                         >> 0xbU)))));
        tracep->chgBit(oldp+719,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_0__DOT__w3));
        tracep->chgBit(oldp+720,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 9U))));
        tracep->chgBit(oldp+721,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 7U))));
        tracep->chgBit(oldp+722,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 5U))));
        tracep->chgBit(oldp+723,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 3U))));
        tracep->chgBit(oldp+724,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w1));
        tracep->chgBit(oldp+725,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 5U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                                   >> 3U)))));
        tracep->chgBit(oldp+726,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w3));
        tracep->chgBit(oldp+727,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w1));
        tracep->chgBit(oldp+728,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_1))));
        tracep->chgBit(oldp+729,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w3));
        tracep->chgBit(oldp+730,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 0x10U))));
        tracep->chgBit(oldp+731,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0xeU))));
        tracep->chgBit(oldp+732,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0xcU))));
        tracep->chgBit(oldp+733,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0xaU))));
        tracep->chgBit(oldp+734,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w1));
        tracep->chgBit(oldp+735,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                         >> 0xcU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                         >> 0xaU)))));
        tracep->chgBit(oldp+736,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w3));
        tracep->chgBit(oldp+737,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 8U))));
        tracep->chgBit(oldp+738,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 6U))));
        tracep->chgBit(oldp+739,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 4U))));
        tracep->chgBit(oldp+740,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 2U))));
        tracep->chgBit(oldp+741,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w1));
        tracep->chgBit(oldp+742,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                         >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                                   >> 2U)))));
        tracep->chgBit(oldp+743,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w3));
        tracep->chgBit(oldp+744,((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_0)))));
        tracep->chgBit(oldp+745,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_1) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_2))));
        tracep->chgBit(oldp+746,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_1_0__DOT__w3));
        tracep->chgBit(oldp+747,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0xfU))));
        tracep->chgBit(oldp+748,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0xdU))));
        tracep->chgBit(oldp+749,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0xbU))));
        tracep->chgBit(oldp+750,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 9U))));
        tracep->chgBit(oldp+751,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w1));
        tracep->chgBit(oldp+752,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                         >> 0xbU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                         >> 9U)))));
        tracep->chgBit(oldp+753,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w3));
        tracep->chgBit(oldp+754,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 7U))));
        tracep->chgBit(oldp+755,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 5U))));
        tracep->chgBit(oldp+756,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 3U))));
        tracep->chgBit(oldp+757,((1U & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                           >> 1U)))));
        tracep->chgBit(oldp+758,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w1));
        tracep->chgBit(oldp+759,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                         >> 3U) ^ (~ 
                                                   ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                                    >> 1U))))));
        tracep->chgBit(oldp+760,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w3));
        tracep->chgBit(oldp+761,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w1));
        tracep->chgBit(oldp+762,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_1))));
        tracep->chgBit(oldp+763,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w3));
        tracep->chgBit(oldp+764,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 0x10U))));
        tracep->chgBit(oldp+765,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0xeU))));
        tracep->chgBit(oldp+766,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0xcU))));
        tracep->chgBit(oldp+767,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0xaU))));
        tracep->chgBit(oldp+768,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w1));
        tracep->chgBit(oldp+769,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                         >> 0xcU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                         >> 0xaU)))));
        tracep->chgBit(oldp+770,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w3));
        tracep->chgBit(oldp+771,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 8U))));
        tracep->chgBit(oldp+772,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 6U))));
        tracep->chgBit(oldp+773,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 4U))));
        tracep->chgBit(oldp+774,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w1));
        tracep->chgBit(oldp+775,((1U & (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                           >> 4U)))));
        tracep->chgBit(oldp+776,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w3));
        tracep->chgBit(oldp+777,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w1));
        tracep->chgBit(oldp+778,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_1))));
        tracep->chgBit(oldp+779,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w3));
        tracep->chgBit(oldp+780,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0xfU))));
        tracep->chgBit(oldp+781,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0xdU))));
        tracep->chgBit(oldp+782,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0xbU))));
        tracep->chgBit(oldp+783,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 9U))));
        tracep->chgBit(oldp+784,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w1));
        tracep->chgBit(oldp+785,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                         >> 0xbU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 9U)))));
        tracep->chgBit(oldp+786,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w3));
        tracep->chgBit(oldp+787,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w1));
        tracep->chgBit(oldp+788,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_2) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_0))));
        tracep->chgBit(oldp+789,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w3));
        tracep->chgBit(oldp+790,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 0x10U))));
        tracep->chgBit(oldp+791,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0xeU))));
        tracep->chgBit(oldp+792,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0xcU))));
        tracep->chgBit(oldp+793,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0xaU))));
        tracep->chgBit(oldp+794,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w1));
        tracep->chgBit(oldp+795,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                         >> 0xcU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 0xaU)))));
        tracep->chgBit(oldp+796,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w3));
        tracep->chgBit(oldp+797,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w1));
        tracep->chgBit(oldp+798,((1U ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_0_0) 
                                        ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb)))));
        tracep->chgBit(oldp+799,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w3));
        tracep->chgBit(oldp+800,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0xfU))));
        tracep->chgBit(oldp+801,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0xdU))));
        tracep->chgBit(oldp+802,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0xbU))));
        tracep->chgBit(oldp+803,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 9U))));
        tracep->chgBit(oldp+804,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w1));
        tracep->chgBit(oldp+805,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 0xbU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                         >> 9U)))));
        tracep->chgBit(oldp+806,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w3));
        tracep->chgBit(oldp+807,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w1));
        tracep->chgBit(oldp+808,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_1))));
        tracep->chgBit(oldp+809,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w3));
        tracep->chgBit(oldp+810,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 0x10U))));
        tracep->chgBit(oldp+811,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0xeU))));
        tracep->chgBit(oldp+812,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0xcU))));
        tracep->chgBit(oldp+813,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0xaU))));
        tracep->chgBit(oldp+814,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w1));
        tracep->chgBit(oldp+815,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                         >> 0xcU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                         >> 0xaU)))));
        tracep->chgBit(oldp+816,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w3));
        tracep->chgBit(oldp+817,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w1));
        tracep->chgBit(oldp+818,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_0_0) 
                                        ^ (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                              >> 8U))))));
        tracep->chgBit(oldp+819,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w3));
        tracep->chgBit(oldp+820,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0xfU))));
        tracep->chgBit(oldp+821,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0xdU))));
        tracep->chgBit(oldp+822,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0xbU))));
        tracep->chgBit(oldp+823,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 9U))));
        tracep->chgBit(oldp+824,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w1));
        tracep->chgBit(oldp+825,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                         >> 0xbU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                         >> 9U)))));
        tracep->chgBit(oldp+826,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w3));
        tracep->chgBit(oldp+827,((1U & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                           >> 4U)))));
        tracep->chgBit(oldp+828,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w1));
        tracep->chgBit(oldp+829,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                         >> 8U) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_0_0)))));
        tracep->chgBit(oldp+830,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w3));
        tracep->chgBit(oldp+831,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 0x10U))));
        tracep->chgBit(oldp+832,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0xeU))));
        tracep->chgBit(oldp+833,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0xcU))));
        tracep->chgBit(oldp+834,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 0xaU))));
        tracep->chgBit(oldp+835,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w1));
        tracep->chgBit(oldp+836,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                         >> 0xcU) ^ 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                         >> 0xaU)))));
        tracep->chgBit(oldp+837,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w3));
        tracep->chgBit(oldp+838,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0xfU))));
        tracep->chgBit(oldp+839,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0xdU))));
        tracep->chgBit(oldp+840,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 0xbU))));
        tracep->chgBit(oldp+841,((1U & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                           >> 5U)))));
        tracep->chgBit(oldp+842,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w1));
        tracep->chgBit(oldp+843,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                         >> 0xbU) ^ 
                                        (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                            >> 5U))))));
        tracep->chgBit(oldp+844,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w3));
        tracep->chgBit(oldp+845,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 0x10U))));
        tracep->chgBit(oldp+846,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0xeU))));
        tracep->chgBit(oldp+847,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 0xcU))));
        tracep->chgBit(oldp+848,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w1));
        tracep->chgBit(oldp+849,((1U & (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                           >> 0xcU)))));
        tracep->chgBit(oldp+850,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w3));
        tracep->chgBit(oldp+851,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 4U))));
        tracep->chgBit(oldp+852,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 2U))));
        tracep->chgBit(oldp+853,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2)));
        tracep->chgBit(oldp+854,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 2U))));
        tracep->chgBit(oldp+855,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w3));
        tracep->chgBit(oldp+856,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w1));
        tracep->chgBit(oldp+857,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                           >> 2U)))));
        tracep->chgBit(oldp+858,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 6U))));
        tracep->chgBit(oldp+859,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 4U))));
        tracep->chgBit(oldp+860,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 2U))));
        tracep->chgBit(oldp+861,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3)));
        tracep->chgBit(oldp+862,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w1));
        tracep->chgBit(oldp+863,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 2U) ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3))));
        tracep->chgBit(oldp+864,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 7U))));
        tracep->chgBit(oldp+865,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 5U))));
        tracep->chgBit(oldp+866,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 3U))));
        tracep->chgBit(oldp+867,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 1U))));
        tracep->chgBit(oldp+868,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w1));
        tracep->chgBit(oldp+869,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 1U)))));
        tracep->chgBit(oldp+870,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w3));
        tracep->chgBit(oldp+871,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 8U))));
        tracep->chgBit(oldp+872,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 6U))));
        tracep->chgBit(oldp+873,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 4U))));
        tracep->chgBit(oldp+874,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 2U))));
        tracep->chgBit(oldp+875,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w1));
        tracep->chgBit(oldp+876,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 2U)))));
        tracep->chgBit(oldp+877,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w3));
        tracep->chgBit(oldp+878,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 9U))));
        tracep->chgBit(oldp+879,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 7U))));
        tracep->chgBit(oldp+880,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 5U))));
        tracep->chgBit(oldp+881,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                        >> 3U))));
        tracep->chgBit(oldp+882,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w1));
        tracep->chgBit(oldp+883,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                         >> 5U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                                   >> 3U)))));
        tracep->chgBit(oldp+884,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w3));
        tracep->chgBit(oldp+885,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 1U))));
        tracep->chgBit(oldp+886,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w3));
        tracep->chgBit(oldp+887,(((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w3)) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s9_0_0))));
        tracep->chgBit(oldp+888,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w1));
        tracep->chgBit(oldp+889,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c8_0_1) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s9_0_0))));
        tracep->chgBit(oldp+890,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 2U))));
        tracep->chgBit(oldp+891,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5)));
        tracep->chgBit(oldp+892,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 5U))));
        tracep->chgBit(oldp+893,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa10_0_1__DOT__axorb));
        tracep->chgBit(oldp+894,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 5U))));
        tracep->chgBit(oldp+895,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 3U))));
        tracep->chgBit(oldp+896,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                        >> 1U))));
        tracep->chgBit(oldp+897,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_0_1__DOT__axorb));
        tracep->chgBit(oldp+898,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_1_0))));
        tracep->chgBit(oldp+899,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_1_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_1) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_1_0)))));
        tracep->chgBit(oldp+900,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_2_0__DOT__axorb));
        tracep->chgBit(oldp+901,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa14_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s14_1_0))));
        tracep->chgBit(oldp+902,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s14_1_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa14_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_1) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_1_0)))));
        tracep->chgBit(oldp+903,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa14_2_0__DOT__axorb));
        tracep->chgBit(oldp+904,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa16_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_1_0))));
        tracep->chgBit(oldp+905,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_1_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa16_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_1) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_1_0)))));
        tracep->chgBit(oldp+906,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa16_2_0__DOT__axorb));
        tracep->chgBit(oldp+907,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa17_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_1_0))));
        tracep->chgBit(oldp+908,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_1_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa17_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_2) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_1_0)))));
        tracep->chgBit(oldp+909,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa17_2_0__DOT__axorb));
        tracep->chgBit(oldp+910,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa18_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_1))));
        tracep->chgBit(oldp+911,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_1) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa18_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_0) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_1_0)))));
        tracep->chgBit(oldp+912,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa18_2_0__DOT__axorb));
        tracep->chgBit(oldp+913,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa19_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_1))));
        tracep->chgBit(oldp+914,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_1) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa19_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_1_0) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_0)))));
        tracep->chgBit(oldp+915,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa19_2_0__DOT__axorb));
        tracep->chgBit(oldp+916,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 7U))));
        tracep->chgBit(oldp+917,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 5U))));
        tracep->chgBit(oldp+918,((1U & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                           >> 2U)))));
        tracep->chgBit(oldp+919,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_0_1__DOT__axorb));
        tracep->chgBit(oldp+920,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_1_0))));
        tracep->chgBit(oldp+921,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_1_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_1) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_1_0)))));
        tracep->chgBit(oldp+922,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_2_0__DOT__axorb));
        tracep->chgBit(oldp+923,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 8U))));
        tracep->chgBit(oldp+924,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 6U))));
        tracep->chgBit(oldp+925,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb));
        tracep->chgBit(oldp+926,((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_0_0)))));
        tracep->chgBit(oldp+927,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa26_2_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_1_0))));
        tracep->chgBit(oldp+928,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_1_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa26_2_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_0) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_1)))));
        tracep->chgBit(oldp+929,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa26_2_0__DOT__axorb));
        tracep->chgBit(oldp+930,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0xfU))));
        tracep->chgBit(oldp+931,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 0xdU))));
        tracep->chgBit(oldp+932,((1U & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                           >> 6U)))));
        tracep->chgBit(oldp+933,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_0_0__DOT__axorb));
        tracep->chgBit(oldp+934,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_1_0__DOT__axorb));
        tracep->chgBit(oldp+935,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 2U))));
        tracep->chgBit(oldp+936,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1)));
        tracep->chgBit(oldp+937,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 1U))));
        tracep->chgBit(oldp+938,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa2_0_0__DOT__axorb) 
                                        ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                           >> 1U)))));
        tracep->chgBit(oldp+939,((1U & ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                          >> 1U) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa2_0_0__DOT__axorb)) 
                                        | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                            >> 2U) 
                                           & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1)))));
        tracep->chgBit(oldp+940,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa2_0_0__DOT__axorb));
        tracep->chgBit(oldp+941,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                        >> 0x10U))));
        tracep->chgBit(oldp+942,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 0xeU))));
        tracep->chgBit(oldp+943,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb));
        tracep->chgBit(oldp+944,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 5U))));
        tracep->chgBit(oldp+945,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 3U))));
        tracep->chgBit(oldp+946,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                        >> 1U))));
        tracep->chgBit(oldp+947,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_0_0__DOT__axorb));
        tracep->chgBit(oldp+948,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_1_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_1))));
        tracep->chgBit(oldp+949,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_1) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_1_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s5_0_0) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_0)))));
        tracep->chgBit(oldp+950,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_1_0__DOT__axorb));
        tracep->chgBit(oldp+951,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 3U))));
        tracep->chgBit(oldp+952,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa6_1_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c5_0_0))));
        tracep->chgBit(oldp+953,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c5_0_0) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa6_1_0__DOT__axorb)) 
                                  | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                      >> 3U) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w3)))));
        tracep->chgBit(oldp+954,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa6_1_0__DOT__axorb));
        tracep->chgBit(oldp+955,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa8_1_0__DOT__axorb) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_1))));
        tracep->chgBit(oldp+956,((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_1) 
                                   & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa8_1_0__DOT__axorb)) 
                                  | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_0) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c7_0_0)))));
        tracep->chgBit(oldp+957,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa8_1_0__DOT__axorb));
        tracep->chgBit(oldp+958,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                        >> 3U))));
        tracep->chgBit(oldp+959,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                        >> 1U))));
        tracep->chgBit(oldp+960,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_1_0))));
        tracep->chgBit(oldp+961,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_1_0))));
        tracep->chgBit(oldp+962,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 1U))));
        tracep->chgBit(oldp+963,((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)))));
        tracep->chgBit(oldp+964,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_1_0))));
        tracep->chgBit(oldp+965,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_1_0))));
        tracep->chgBit(oldp+966,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_1_0))));
        tracep->chgBit(oldp+967,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_1_0))));
        tracep->chgBit(oldp+968,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                        >> 7U))));
        tracep->chgBit(oldp+969,((1U & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                           >> 3U)))));
        tracep->chgBit(oldp+970,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_1_0))));
        tracep->chgBit(oldp+971,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_1_0))));
        tracep->chgBit(oldp+972,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_1_0))));
        tracep->chgBit(oldp+973,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_1_0))));
        tracep->chgBit(oldp+974,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c24_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_1_0))));
        tracep->chgBit(oldp+975,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c24_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_1_0))));
        tracep->chgBit(oldp+976,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_1_0))));
        tracep->chgBit(oldp+977,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_1_0))));
        tracep->chgBit(oldp+978,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_1_0))));
        tracep->chgBit(oldp+979,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_1_0))));
        tracep->chgBit(oldp+980,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_1_0))));
        tracep->chgBit(oldp+981,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_1_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_1_0))));
        tracep->chgBit(oldp+982,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_1_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s30_1_0))));
        tracep->chgBit(oldp+983,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                        >> 3U))));
        tracep->chgBit(oldp+984,((1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                        >> 1U))));
        tracep->chgBit(oldp+985,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                         >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                                   >> 1U)))));
        tracep->chgBit(oldp+986,((1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                         >> 3U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                                   >> 1U)))));
        tracep->chgBit(oldp+987,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c6_0_0) 
                                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s7_0_0))));
        tracep->chgBit(oldp+988,(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c6_0_0) 
                                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s7_0_0))));
        tracep->chgBit(oldp+989,((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4)));
        tracep->chgBit(oldp+990,((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                        >> 4U))));
        tracep->chgCData(oldp+991,((0x1fU & vlSelf->top__DOT__rs2_d_o)),5);
        tracep->chgBit(oldp+992,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__sft__leftOrRight));
        tracep->chgBit(oldp+993,((1U & ((1U & vlSelf->top__DOT__rs2_d_o)
                                         ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                            >> 1U) : vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in))));
        tracep->chgBit(oldp+994,((1U & ((1U & vlSelf->top__DOT__rs2_d_o)
                                         ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                            >> 2U) : 
                                        (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                         >> 1U)))));
        tracep->chgBit(oldp+995,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02));
        tracep->chgBit(oldp+996,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03));
        tracep->chgBit(oldp+997,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04));
        tracep->chgBit(oldp+998,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05));
        tracep->chgBit(oldp+999,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_06));
        tracep->chgBit(oldp+1000,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_07));
        tracep->chgBit(oldp+1001,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_08));
        tracep->chgBit(oldp+1002,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_09));
        tracep->chgBit(oldp+1003,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_10));
        tracep->chgBit(oldp+1004,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_11));
        tracep->chgBit(oldp+1005,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_12));
        tracep->chgBit(oldp+1006,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_13));
        tracep->chgBit(oldp+1007,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_14));
        tracep->chgBit(oldp+1008,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_15));
        tracep->chgBit(oldp+1009,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_16));
        tracep->chgBit(oldp+1010,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_17));
        tracep->chgBit(oldp+1011,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_18));
        tracep->chgBit(oldp+1012,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_19));
        tracep->chgBit(oldp+1013,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_20));
        tracep->chgBit(oldp+1014,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_21));
        tracep->chgBit(oldp+1015,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_22));
        tracep->chgBit(oldp+1016,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_23));
        tracep->chgBit(oldp+1017,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_24));
        tracep->chgBit(oldp+1018,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_25));
        tracep->chgBit(oldp+1019,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_26));
        tracep->chgBit(oldp+1020,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_27));
        tracep->chgBit(oldp+1021,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_28));
        tracep->chgBit(oldp+1022,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_29));
        tracep->chgBit(oldp+1023,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_30));
        tracep->chgBit(oldp+1024,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_31));
        tracep->chgBit(oldp+1025,((1U & ((2U & vlSelf->top__DOT__rs2_d_o)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02)
                                          : ((1U & vlSelf->top__DOT__rs2_d_o)
                                              ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                 >> 1U)
                                              : vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in)))));
        tracep->chgBit(oldp+1026,((1U & ((2U & vlSelf->top__DOT__rs2_d_o)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03)
                                          : ((1U & vlSelf->top__DOT__rs2_d_o)
                                              ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                 >> 2U)
                                              : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                 >> 1U))))));
        tracep->chgBit(oldp+1027,(((2U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02))));
        tracep->chgBit(oldp+1028,(((2U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03))));
        tracep->chgBit(oldp+1029,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04));
        tracep->chgBit(oldp+1030,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05));
        tracep->chgBit(oldp+1031,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06));
        tracep->chgBit(oldp+1032,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07));
        tracep->chgBit(oldp+1033,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08));
        tracep->chgBit(oldp+1034,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09));
        tracep->chgBit(oldp+1035,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10));
        tracep->chgBit(oldp+1036,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11));
        tracep->chgBit(oldp+1037,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_12));
        tracep->chgBit(oldp+1038,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_13));
        tracep->chgBit(oldp+1039,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_14));
        tracep->chgBit(oldp+1040,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_15));
        tracep->chgBit(oldp+1041,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_16));
        tracep->chgBit(oldp+1042,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_17));
        tracep->chgBit(oldp+1043,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_18));
        tracep->chgBit(oldp+1044,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_19));
        tracep->chgBit(oldp+1045,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_20));
        tracep->chgBit(oldp+1046,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_21));
        tracep->chgBit(oldp+1047,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_22));
        tracep->chgBit(oldp+1048,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_23));
        tracep->chgBit(oldp+1049,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_24));
        tracep->chgBit(oldp+1050,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_25));
        tracep->chgBit(oldp+1051,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_26));
        tracep->chgBit(oldp+1052,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_27));
        tracep->chgBit(oldp+1053,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_28));
        tracep->chgBit(oldp+1054,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_29));
        tracep->chgBit(oldp+1055,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_30));
        tracep->chgBit(oldp+1056,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_31));
        tracep->chgBit(oldp+1057,((1U & ((4U & vlSelf->top__DOT__rs2_d_o)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04)
                                          : ((2U & vlSelf->top__DOT__rs2_d_o)
                                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02)
                                              : ((1U 
                                                  & vlSelf->top__DOT__rs2_d_o)
                                                  ? 
                                                 (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                  >> 1U)
                                                  : vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in))))));
        tracep->chgBit(oldp+1058,((1U & ((4U & vlSelf->top__DOT__rs2_d_o)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05)
                                          : ((2U & vlSelf->top__DOT__rs2_d_o)
                                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03)
                                              : ((1U 
                                                  & vlSelf->top__DOT__rs2_d_o)
                                                  ? 
                                                 (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                  >> 2U)
                                                  : 
                                                 (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                  >> 1U)))))));
        tracep->chgBit(oldp+1059,(((4U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06)
                                    : ((2U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04)
                                        : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02)))));
        tracep->chgBit(oldp+1060,(((4U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07)
                                    : ((2U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05)
                                        : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03)))));
        tracep->chgBit(oldp+1061,(((4U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04))));
        tracep->chgBit(oldp+1062,(((4U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05))));
        tracep->chgBit(oldp+1063,(((4U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06))));
        tracep->chgBit(oldp+1064,(((4U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07))));
        tracep->chgBit(oldp+1065,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_08));
        tracep->chgBit(oldp+1066,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09));
        tracep->chgBit(oldp+1067,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10));
        tracep->chgBit(oldp+1068,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11));
        tracep->chgBit(oldp+1069,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12));
        tracep->chgBit(oldp+1070,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13));
        tracep->chgBit(oldp+1071,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14));
        tracep->chgBit(oldp+1072,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15));
        tracep->chgBit(oldp+1073,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_16));
        tracep->chgBit(oldp+1074,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_17));
        tracep->chgBit(oldp+1075,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_18));
        tracep->chgBit(oldp+1076,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_19));
        tracep->chgBit(oldp+1077,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_20));
        tracep->chgBit(oldp+1078,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_21));
        tracep->chgBit(oldp+1079,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_22));
        tracep->chgBit(oldp+1080,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_23));
        tracep->chgBit(oldp+1081,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_24));
        tracep->chgBit(oldp+1082,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_25));
        tracep->chgBit(oldp+1083,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_26));
        tracep->chgBit(oldp+1084,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_27));
        tracep->chgBit(oldp+1085,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_28));
        tracep->chgBit(oldp+1086,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_29));
        tracep->chgBit(oldp+1087,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_30));
        tracep->chgBit(oldp+1088,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_31));
        tracep->chgBit(oldp+1089,((1U & ((8U & vlSelf->top__DOT__rs2_d_o)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_08)
                                          : ((4U & vlSelf->top__DOT__rs2_d_o)
                                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04)
                                              : ((2U 
                                                  & vlSelf->top__DOT__rs2_d_o)
                                                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02)
                                                  : 
                                                 ((1U 
                                                   & vlSelf->top__DOT__rs2_d_o)
                                                   ? 
                                                  (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                   >> 1U)
                                                   : vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in)))))));
        tracep->chgBit(oldp+1090,((1U & ((8U & vlSelf->top__DOT__rs2_d_o)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09)
                                          : ((4U & vlSelf->top__DOT__rs2_d_o)
                                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05)
                                              : ((2U 
                                                  & vlSelf->top__DOT__rs2_d_o)
                                                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03)
                                                  : 
                                                 ((1U 
                                                   & vlSelf->top__DOT__rs2_d_o)
                                                   ? 
                                                  (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                   >> 2U)
                                                   : 
                                                  (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                                   >> 1U))))))));
        tracep->chgBit(oldp+1091,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10)
                                    : ((4U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06)
                                        : ((2U & vlSelf->top__DOT__rs2_d_o)
                                            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04)
                                            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02))))));
        tracep->chgBit(oldp+1092,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11)
                                    : ((4U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07)
                                        : ((2U & vlSelf->top__DOT__rs2_d_o)
                                            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05)
                                            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03))))));
        tracep->chgBit(oldp+1093,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12)
                                    : ((4U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08)
                                        : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04)))));
        tracep->chgBit(oldp+1094,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13)
                                    : ((4U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09)
                                        : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05)))));
        tracep->chgBit(oldp+1095,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14)
                                    : ((4U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10)
                                        : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06)))));
        tracep->chgBit(oldp+1096,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15)
                                    : ((4U & vlSelf->top__DOT__rs2_d_o)
                                        ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11)
                                        : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07)))));
        tracep->chgBit(oldp+1097,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_16)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_08))));
        tracep->chgBit(oldp+1098,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_17)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09))));
        tracep->chgBit(oldp+1099,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_18)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10))));
        tracep->chgBit(oldp+1100,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_19)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11))));
        tracep->chgBit(oldp+1101,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_20)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12))));
        tracep->chgBit(oldp+1102,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_21)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13))));
        tracep->chgBit(oldp+1103,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_22)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14))));
        tracep->chgBit(oldp+1104,(((8U & vlSelf->top__DOT__rs2_d_o)
                                    ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_23)
                                    : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15))));
        tracep->chgBit(oldp+1105,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_16));
        tracep->chgBit(oldp+1106,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_17));
        tracep->chgBit(oldp+1107,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_18));
        tracep->chgBit(oldp+1108,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_19));
        tracep->chgBit(oldp+1109,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_20));
        tracep->chgBit(oldp+1110,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_21));
        tracep->chgBit(oldp+1111,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_22));
        tracep->chgBit(oldp+1112,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_23));
        tracep->chgBit(oldp+1113,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_24));
        tracep->chgBit(oldp+1114,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_25));
        tracep->chgBit(oldp+1115,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_26));
        tracep->chgBit(oldp+1116,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_27));
        tracep->chgBit(oldp+1117,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_28));
        tracep->chgBit(oldp+1118,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_29));
        tracep->chgBit(oldp+1119,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_30));
        tracep->chgBit(oldp+1120,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_31));
        tracep->chgBit(oldp+1121,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill));
        tracep->chgIData(oldp+1122,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in),32);
        tracep->chgIData(oldp+1123,(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out),32);
        tracep->chgBit(oldp+1124,(vlSelf->top__DOT__u_pipelineID__DOT__taken_reg));
        tracep->chgIData(oldp+1125,(vlSelf->top__DOT__u_pipelineID__DOT__pc_taken),32);
        tracep->chgCData(oldp+1126,((3U & ((IData)(1U) 
                                           + (IData)(vlSelf->top__DOT__u_pipelineID__DOT__mul_state)))),2);
        tracep->chgCData(oldp+1127,((0xfU & ((IData)(1U) 
                                             + (IData)(vlSelf->top__DOT__u_pipelineID__DOT__div_state)))),4);
        tracep->chgCData(oldp+1128,(vlSelf->top__DOT__u_pipelineID__DOT__mul_state),2);
        tracep->chgCData(oldp+1129,(vlSelf->top__DOT__u_pipelineID__DOT__div_state),4);
        tracep->chgBit(oldp+1130,(vlSelf->top__DOT__u_pipelineID__DOT__div_last));
        tracep->chgIData(oldp+1131,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[0]),32);
        tracep->chgIData(oldp+1132,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[1]),32);
        tracep->chgIData(oldp+1133,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[2]),32);
        tracep->chgIData(oldp+1134,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[3]),32);
        tracep->chgIData(oldp+1135,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[4]),32);
        tracep->chgIData(oldp+1136,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[5]),32);
        tracep->chgIData(oldp+1137,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[6]),32);
        tracep->chgIData(oldp+1138,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[7]),32);
        tracep->chgIData(oldp+1139,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[8]),32);
        tracep->chgIData(oldp+1140,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[9]),32);
        tracep->chgIData(oldp+1141,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[10]),32);
        tracep->chgIData(oldp+1142,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[11]),32);
        tracep->chgIData(oldp+1143,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[12]),32);
        tracep->chgIData(oldp+1144,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[13]),32);
        tracep->chgIData(oldp+1145,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[14]),32);
        tracep->chgIData(oldp+1146,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[15]),32);
        tracep->chgIData(oldp+1147,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[16]),32);
        tracep->chgIData(oldp+1148,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[17]),32);
        tracep->chgIData(oldp+1149,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[18]),32);
        tracep->chgIData(oldp+1150,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[19]),32);
        tracep->chgIData(oldp+1151,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[20]),32);
        tracep->chgIData(oldp+1152,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[21]),32);
        tracep->chgIData(oldp+1153,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[22]),32);
        tracep->chgIData(oldp+1154,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[23]),32);
        tracep->chgIData(oldp+1155,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[24]),32);
        tracep->chgIData(oldp+1156,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[25]),32);
        tracep->chgIData(oldp+1157,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[26]),32);
        tracep->chgIData(oldp+1158,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[27]),32);
        tracep->chgIData(oldp+1159,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[28]),32);
        tracep->chgIData(oldp+1160,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[29]),32);
        tracep->chgIData(oldp+1161,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[30]),32);
        tracep->chgIData(oldp+1162,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data[31]),32);
        tracep->chgIData(oldp+1163,(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__i),32);
        tracep->chgCData(oldp+1164,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en),4);
        tracep->chgIData(oldp+1165,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data),32);
        tracep->chgCData(oldp+1166,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op),4);
        tracep->chgCData(oldp+1167,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr),2);
        tracep->chgIData(oldp+1168,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data),32);
        tracep->chgIData(oldp+1169,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data),32);
        tracep->chgSData(oldp+1170,((0x3ffU & (vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation 
                                               >> 2U))),10);
        tracep->chgBit(oldp+1171,((0U == (IData)(vlSelf->top__DOT__dmem_type_d_o))));
        tracep->chgBit(oldp+1172,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__web));
        tracep->chgCData(oldp+1173,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read0),8);
        tracep->chgCData(oldp+1174,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read1),8);
        tracep->chgCData(oldp+1175,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read2),8);
        tracep->chgCData(oldp+1176,(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read3),8);
        tracep->chgCData(oldp+1177,((0xffU & vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data)),8);
        tracep->chgCData(oldp+1178,((0xffU & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                                              >> 8U))),8);
        tracep->chgCData(oldp+1179,((0xffU & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                                              >> 0x10U))),8);
        tracep->chgCData(oldp+1180,((vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                                     >> 0x18U)),8);
        tracep->chgBit(oldp+1181,((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en))));
        tracep->chgBit(oldp+1182,((1U & ((IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en) 
                                         >> 1U))));
        tracep->chgBit(oldp+1183,((1U & ((IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en) 
                                         >> 2U))));
        tracep->chgBit(oldp+1184,((1U & ((IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en) 
                                         >> 3U))));
        tracep->chgIData(oldp+1185,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output),32);
        tracep->chgIData(oldp+1186,((((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir1) 
                                      << 0x10U) | (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir0))),32);
        tracep->chgBit(oldp+1187,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__taken_d_delay1));
        tracep->chgBit(oldp+1188,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__flush_delay));
        tracep->chgIData(oldp+1189,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output_reg),32);
        tracep->chgSData(oldp+1190,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pir2),16);
        tracep->chgSData(oldp+1191,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pir1),16);
        tracep->chgSData(oldp+1192,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pir0),16);
        tracep->chgSData(oldp+1193,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir1),16);
        tracep->chgSData(oldp+1194,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir0),16);
        tracep->chgIData(oldp+1195,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__linear_addr),32);
        tracep->chgSData(oldp+1196,((vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output 
                                     >> 0x10U)),16);
        tracep->chgSData(oldp+1197,((0xffffU & vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output)),16);
        tracep->chgCData(oldp+1198,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt),3);
        tracep->chgBit(oldp+1199,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__fill));
        tracep->chgBit(oldp+1200,((2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt))));
        tracep->chgBit(oldp+1201,((3U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt))));
        tracep->chgBit(oldp+1202,((4U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt))));
        tracep->chgBit(oldp+1203,((5U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgBit(oldp+1204,(vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o));
        tracep->chgBit(oldp+1205,(vlSelf->top__DOT__is_j_d_o));
        tracep->chgBit(oldp+1206,(vlSelf->top__DOT__is_load_d_o));
        tracep->chgBit(oldp+1207,(vlSelf->top__DOT__is_m_d_o));
        tracep->chgBit(oldp+1208,(vlSelf->top__DOT__is_d_d_o));
        tracep->chgBit(oldp+1209,(vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o));
        tracep->chgBit(oldp+1210,(vlSelf->top__DOT__u_pipelineID__DOT__taken));
        tracep->chgCData(oldp+1211,((0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 7U))),5);
        tracep->chgCData(oldp+1212,((0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 0xfU))),5);
        tracep->chgCData(oldp+1213,((0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 0x14U))),5);
        tracep->chgCData(oldp+1214,(vlSelf->top__DOT__src1_sel_d_i),2);
        tracep->chgCData(oldp+1215,(vlSelf->top__DOT__src2_sel_d_i),2);
        tracep->chgBit(oldp+1216,(vlSelf->top__DOT__fd_st_f_i));
        tracep->chgBit(oldp+1217,(vlSelf->top__DOT__de_st_d_i));
        tracep->chgIData(oldp+1218,(vlSelf->top__DOT__instruction_f_o),32);
        tracep->chgBit(oldp+1219,(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o));
        tracep->chgIData(oldp+1220,(vlSelf->top__DOT__redirection_d_o),32);
        tracep->chgBit(oldp+1221,(vlSelf->top__DOT__taken_d_o));
        tracep->chgBit(oldp+1222,((0U != (IData)(vlSelf->top__DOT__src1_sel_d_i))));
        tracep->chgBit(oldp+1223,(vlSelf->top__DOT__hu__DOT__Ldhaz_st));
        tracep->chgBit(oldp+1224,((1U & (~ (IData)(vlSelf->top__DOT__de_st_d_i)))));
        tracep->chgBit(oldp+1225,(((IData)(vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal) 
                                   | (IData)(vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal))));
        tracep->chgIData(oldp+1226,(vlSelf->top__DOT__u_pipelineID__DOT__aluOperation_o),21);
        tracep->chgBit(oldp+1227,(vlSelf->top__DOT__u_pipelineID__DOT__rs1_sel_o));
        tracep->chgBit(oldp+1228,(vlSelf->top__DOT__u_pipelineID__DOT__rs2_sel_o));
        tracep->chgCData(oldp+1229,(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o),3);
        tracep->chgBit(oldp+1230,(vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o));
        tracep->chgBit(oldp+1231,(vlSelf->top__DOT__u_pipelineID__DOT__branchJALR_o));
        tracep->chgCData(oldp+1232,(vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o),4);
        tracep->chgCData(oldp+1233,(vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o),4);
        tracep->chgBit(oldp+1234,(vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal));
        tracep->chgIData(oldp+1235,(vlSelf->top__DOT__u_pipelineID__DOT__instr_o),32);
        tracep->chgBit(oldp+1236,(vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal));
        tracep->chgIData(oldp+1237,(vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits),32);
        tracep->chgIData(oldp+1238,(vlSelf->top__DOT__u_pipelineID__DOT__imm_o),32);
        tracep->chgIData(oldp+1239,(vlSelf->top__DOT__u_pipelineID__DOT__rs1_data_o),32);
        tracep->chgIData(oldp+1240,(vlSelf->top__DOT__u_pipelineID__DOT__rs2_data_o),32);
        tracep->chgIData(oldp+1241,(vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc),32);
        tracep->chgIData(oldp+1242,(vlSelf->top__DOT__u_pipelineID__DOT__pc_next),32);
        tracep->chgSData(oldp+1243,((0xffffU & vlSelf->top__DOT__instruction_f_o)),16);
        tracep->chgCData(oldp+1244,((0x7fU & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)),7);
        tracep->chgCData(oldp+1245,((7U & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                           >> 0xcU))),3);
        tracep->chgBit(oldp+1246,((1U & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                         >> 0x1eU))));
        tracep->chgBit(oldp+1247,(vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq));
        tracep->chgBit(oldp+1248,(vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt));
        tracep->chgIData(oldp+1249,(vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation),18);
        tracep->chgBit(oldp+1250,((0x73U == vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)));
        tracep->chgBit(oldp+1251,((1U & (~ (IData)(vlSelf->top__DOT__fd_st_f_i)))));
        tracep->chgSData(oldp+1252,((0x3ffU & (vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__cur_addr 
                                               >> 1U))),10);
        tracep->chgBit(oldp+1253,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__ceb));
        tracep->chgIData(oldp+1254,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__cur_addr),32);
        tracep->chgCData(oldp+1255,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt),2);
        tracep->chgBit(oldp+1256,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid));
        tracep->chgCData(oldp+1257,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt),3);
        tracep->chgBit(oldp+1258,(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__drain));
        tracep->chgBit(oldp+1259,((1U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt))));
        tracep->chgBit(oldp+1260,((2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt))));
        tracep->chgBit(oldp+1261,((2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt))));
        tracep->chgBit(oldp+1262,((3U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt))));
        tracep->chgBit(oldp+1263,((4U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt))));
        tracep->chgBit(oldp+1264,((5U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt))));
    }
    tracep->chgBit(oldp+1265,(vlSelf->clk));
    tracep->chgBit(oldp+1266,(vlSelf->resetn));
    tracep->chgIData(oldp+1267,(vlSelf->pc),32);
    tracep->chgQData(oldp+1268,(vlSelf->instr),64);
    tracep->chgIData(oldp+1270,(vlSelf->id_instr),32);
    tracep->chgIData(oldp+1271,(vlSelf->imem_addr),32);
    tracep->chgBit(oldp+1272,(vlSelf->commit_en));
    tracep->chgBit(oldp+1273,((((~ (IData)(vlSelf->top__DOT__hu__DOT__flush)) 
                                & (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__resetn_delay2)) 
                               & (~ (IData)(vlSelf->top__DOT__fd_st_f_i)))));
    tracep->chgBit(oldp+1274,(((~ ((IData)(vlSelf->top__DOT__u_pipelineID__DOT__fin) 
                                   | (IData)(vlSelf->top__DOT__hu__DOT__flush))) 
                               & (((IData)(vlSelf->top__DOT__is_d_d_o) 
                                   | (IData)(vlSelf->top__DOT__is_m_d_o)) 
                                  | (IData)(vlSelf->top__DOT__hu__DOT__Linst_st_keep)))));
    tracep->chgBit(oldp+1275,((((IData)((0U != (0x3c000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__aluOperation_o))) 
                                & (0U == (IData)(vlSelf->top__DOT__u_pipelineID__DOT__div_state))) 
                               & (~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__div_last)))));
    tracep->chgBit(oldp+1276,(((IData)((0U != (0x3c000U 
                                               & vlSelf->top__DOT__u_pipelineID__DOT__aluOperation_o))) 
                               & (0U != (IData)(vlSelf->top__DOT__u_pipelineID__DOT__div_state)))));
    tracep->chgIData(oldp+1277,((IData)(vlSelf->instr)),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
