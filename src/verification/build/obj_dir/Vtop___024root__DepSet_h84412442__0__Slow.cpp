// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

void Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();

VL_ATTR_COLD void Vtop___024root___settle__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = (0x7ffffffdU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1);
    vlSelf->commit_en = vlSelf->top__DOT__commit_en_delay;
    vlSelf->pc = vlSelf->top__DOT__pc_instr_delay;
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans 
        = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans_temp;
    vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
        = (((IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read3) 
            << 0x18U) | (((IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read2) 
                          << 0x10U) | (((IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read1) 
                                        << 8U) | (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__u_dmemory__DOT__read0))));
    vlSelf->top__DOT__write_back_data_w_o = (((((- (IData)(
                                                           (1U 
                                                            & (IData)(vlSelf->top__DOT__result_src_m_o)))) 
                                                & vlSelf->top__DOT__alu_result_m_o) 
                                               | ((- (IData)(
                                                             (1U 
                                                              & ((IData)(vlSelf->top__DOT__result_src_m_o) 
                                                                 >> 1U)))) 
                                                  & vlSelf->top__DOT__extended_imm_m_o)) 
                                              | ((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->top__DOT__result_src_m_o) 
                                                                >> 2U)))) 
                                                 & vlSelf->top__DOT__mem_read_data_m_o)) 
                                             | ((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->top__DOT__result_src_m_o) 
                                                               >> 3U)))) 
                                                & vlSelf->top__DOT__pc_plus4_m_o));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
        = ((0x7fffffffcULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem) 
           | (QData)((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvd 
                              >> 0x1eU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__sft__leftOrRight 
        = (IData)((0U != (0x18U & vlSelf->top__DOT__alu_op_d_o)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss 
        = (IData)((0U != (0xc00U & vlSelf->top__DOT__alu_op_d_o)));
    vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__web 
        = (((((4U == (IData)(vlSelf->top__DOT__dmem_type_d_o)) 
              | (5U == (IData)(vlSelf->top__DOT__dmem_type_d_o))) 
             | (7U == (IData)(vlSelf->top__DOT__dmem_type_d_o))) 
            | (8U == (IData)(vlSelf->top__DOT__dmem_type_d_o))) 
           | (6U == (IData)(vlSelf->top__DOT__dmem_type_d_o)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain 
        = (0xffffU & (((- (IData)((1U & (~ (IData)(vlSelf->top__DOT__mul_state_d_o))))) 
                       & vlSelf->top__DOT__rs1_d_o) 
                      | ((- (IData)((1U & (IData)(vlSelf->top__DOT__mul_state_d_o)))) 
                         & (vlSelf->top__DOT__rs1_d_o 
                            >> 0x10U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__div__unsign 
        = (IData)((0U != (0x28000U & vlSelf->top__DOT__alu_op_d_o)));
    vlSelf->top__DOT__u_pipelineID__DOT__mul_next_state 
        = (3U & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_pipelineID__DOT__mul_state)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
        = (0x7ffffffffULL & ((- (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot))) 
                             ^ (((QData)((IData)((7U 
                                                  & (- (IData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dvs)))))) 
                                 << 0x20U) | (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs)))));
    vlSelf->top__DOT__u_pipelineID__DOT__div_next_state 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_pipelineID__DOT__div_state)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__add_ans 
        = (0x1ffffffffULL & (((((QData)((IData)(((~ 
                                                  (vlSelf->top__DOT__alu_op_d_o 
                                                   >> 9U)) 
                                                 & (vlSelf->top__DOT__rs1_d_o 
                                                    >> 0x1fU)))) 
                                << 0x20U) | (QData)((IData)(vlSelf->top__DOT__rs1_d_o))) 
                              + ((- (QData)((IData)(
                                                    (0U 
                                                     != 
                                                     (0x302U 
                                                      & vlSelf->top__DOT__alu_op_d_o))))) 
                                 ^ (((QData)((IData)(
                                                     ((vlSelf->top__DOT__rs2_d_o 
                                                       >> 0x1fU) 
                                                      & (~ 
                                                         (vlSelf->top__DOT__alu_op_d_o 
                                                          >> 9U))))) 
                                     << 0x20U) | (QData)((IData)(vlSelf->top__DOT__rs2_d_o))))) 
                             + (QData)((IData)((0U 
                                                != 
                                                (0x302U 
                                                 & vlSelf->top__DOT__alu_op_d_o))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin 
        = (0xffffU & (((- (IData)((1U & (~ ((IData)(vlSelf->top__DOT__mul_state_d_o) 
                                            >> 1U))))) 
                       & vlSelf->top__DOT__rs2_d_o) 
                      | ((- (IData)((1U & ((IData)(vlSelf->top__DOT__mul_state_d_o) 
                                           >> 1U)))) 
                         & (vlSelf->top__DOT__rs2_d_o 
                            >> 0x10U))));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output 
        = ((vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output_reg 
            << 0x10U) | (vlSelf->top__DOT__u_pipeline_withFIFO__DOT__sram_output_reg 
                         >> 0x10U));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid 
        = ((((IData)(vlSelf->resetn) & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay)) 
            & (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__resetn_delay2)) 
           & (~ (IData)(vlSelf->top__DOT__flush_jal_d_o)));
    if ((8U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
        if ((4U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                = vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data;
        } else if ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                = vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data;
        } else if ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                = vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data;
        } else if ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))) {
            if ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))) {
                vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                    = (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                       >> 0x10U);
            }
        } else {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                = (0xffffU & vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data);
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
        if ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                = ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))
                    ? ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))
                        ? ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))
                            ? (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                               >> 0x18U) : (0xffU & 
                                            (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                             >> 0x10U)))
                        : ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))
                            ? (0xffU & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                        >> 8U)) : (0xffU 
                                                   & vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data)))
                    : vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data);
        } else if ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__mem_op))) {
            if ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))) {
                if ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))) {
                    vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                        = (((- (IData)((vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                        >> 0x1fU))) 
                            << 0x10U) | (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                         >> 0x10U));
                }
            } else {
                vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                    = (((- (IData)((1U & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data));
            }
        } else {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
                = ((2U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))
                    ? ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))
                        ? (((- (IData)((vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                        >> 0x1fU))) 
                            << 8U) | (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                      >> 0x18U)) : 
                       (((- (IData)((1U & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                           >> 0x17U)))) 
                         << 8U) | (0xffU & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                            >> 0x10U))))
                    : ((1U & (IData)(vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_addr))
                        ? (((- (IData)((1U & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                              >> 0xfU)))) 
                            << 8U) | (0xffU & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                               >> 8U)))
                        : (((- (IData)((1U & (vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data))));
        }
    } else {
        vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data 
            = vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_read_data;
    }
    if (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__sft__leftOrRight) {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill 
            = ((8U & vlSelf->top__DOT__alu_op_d_o) ? 0U
                : (vlSelf->top__DOT__rs1_d_o >> 0x1fU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
            = vlSelf->top__DOT__rs1_d_o;
    } else {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill = 0U;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
            = ((vlSelf->top__DOT__rs1_d_o << 0x1fU) 
               | ((0x40000000U & (vlSelf->top__DOT__rs1_d_o 
                                  << 0x1dU)) | ((0x20000000U 
                                                 & (vlSelf->top__DOT__rs1_d_o 
                                                    << 0x1bU)) 
                                                | ((0x10000000U 
                                                    & (vlSelf->top__DOT__rs1_d_o 
                                                       << 0x19U)) 
                                                   | ((0x8000000U 
                                                       & (vlSelf->top__DOT__rs1_d_o 
                                                          << 0x17U)) 
                                                      | ((0x4000000U 
                                                          & (vlSelf->top__DOT__rs1_d_o 
                                                             << 0x15U)) 
                                                         | ((0x2000000U 
                                                             & (vlSelf->top__DOT__rs1_d_o 
                                                                << 0x13U)) 
                                                            | ((0x1000000U 
                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                   << 0x11U)) 
                                                               | ((0x800000U 
                                                                   & (vlSelf->top__DOT__rs1_d_o 
                                                                      << 0xfU)) 
                                                                  | ((0x400000U 
                                                                      & (vlSelf->top__DOT__rs1_d_o 
                                                                         << 0xdU)) 
                                                                     | ((0x200000U 
                                                                         & (vlSelf->top__DOT__rs1_d_o 
                                                                            << 0xbU)) 
                                                                        | ((0x100000U 
                                                                            & (vlSelf->top__DOT__rs1_d_o 
                                                                               << 9U)) 
                                                                           | ((0x80000U 
                                                                               & (vlSelf->top__DOT__rs1_d_o 
                                                                                << 7U)) 
                                                                              | ((0x40000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                << 5U)) 
                                                                                | ((0x20000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->top__DOT__rs1_d_o 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))));
    }
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16su 
        = (1U & (((vlSelf->top__DOT__alu_op_d_o >> 0xcU) 
                  & (IData)(vlSelf->top__DOT__mul_state_d_o)) 
                 | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss) 
                    & (1U == (IData)(vlSelf->top__DOT__mul_state_d_o)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss) 
           & (2U == (IData)(vlSelf->top__DOT__mul_state_d_o)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu 
        = (1U & (((vlSelf->top__DOT__alu_op_d_o >> 0xdU) 
                  | ((vlSelf->top__DOT__alu_op_d_o 
                      >> 0xcU) & (~ (IData)(vlSelf->top__DOT__mul_state_d_o)))) 
                 | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss) 
                    & (0U == (IData)(vlSelf->top__DOT__mul_state_d_o)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dividend 
        = ((vlSelf->top__DOT__rs1_d_o >> 0x1fU) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__div__unsign)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub1 
        = (0x7ffffffffULL & ((((0x7fffffffcULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem) 
                               | (QData)((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvd 
                                                  >> 0x1eU)))) 
                              + vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt) 
                             + (- (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub2 
        = (0x7ffffffffULL & ((((0x7fffffffcULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem) 
                               | (QData)((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvd 
                                                  >> 0x1eU)))) 
                              + ((0x7fffffffeULL & 
                                  (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                   << 1U)) | (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))) 
                             + (- (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
        = ((0x7fffffffeULL & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                              << 1U)) | (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken 
        = (IData)(((vlSelf->top__DOT__alu_op_d_o >> 0x14U) 
                   & (((vlSelf->top__DOT__alu_op_d_o 
                        >> 1U) & ((~ (vlSelf->top__DOT__alu_op_d_o 
                                      >> 0x12U)) ^ 
                                  (0ULL == vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__add_ans))) 
                      | ((IData)((0U != (0x300U & vlSelf->top__DOT__alu_op_d_o))) 
                         & ((~ (vlSelf->top__DOT__alu_op_d_o 
                                >> 0x13U)) ^ (IData)(
                                                     (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__add_ans 
                                                      >> 0x20U)))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 0xfU)))) 
                      ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 0xdU)))) 
                      ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 0xbU)))) 
                      ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 7U)))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 0xeU)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                   >> 0xdU)) & ((~ 
                                                 ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                  >> 0xfU)) 
                                                ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                   >> 0xdU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 5U)))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 9U)))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 3U)))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__mcand_comp 
        = (0xffffU & ((- (IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                        >> 1U)))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 0xcU)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                   >> 0xbU)) & ((~ 
                                                 ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                  >> 0xdU)) 
                                                ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                   >> 0xbU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 0xaU)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                   >> 9U)) & ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                  >> 0xbU)) 
                                              ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                 >> 9U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 6U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                 >> 5U)) & ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 7U)) 
                                            ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                               >> 5U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 4U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                 >> 3U)) & ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 5U)) 
                                            ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                               >> 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 8U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                 >> 7U)) & ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 9U)) 
                                            ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                               >> 7U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__zero 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                      >> 2U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                 >> 1U)) & ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 3U)) 
                                            ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                               >> 1U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__zero 
        = (IData)((0U == (3U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin))));
    vlSelf->top__DOT__instruction_f_o = ((0x13U & (- (IData)(
                                                             (1U 
                                                              & (~ (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid)))))) 
                                         | ((- (IData)((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid))) 
                                            & (((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir1) 
                                                << 0x10U) 
                                               | (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir0))));
    vlSelf->top__DOT__bypass_m_o = (((((- (IData)((1U 
                                                   & (IData)(vlSelf->top__DOT__resultSrc_e_o)))) 
                                       & vlSelf->top__DOT__aluResult_e_o) 
                                      | ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelf->top__DOT__resultSrc_e_o) 
                                                        >> 1U)))) 
                                         & vlSelf->top__DOT__extendedImm_e_o)) 
                                     | ((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelf->top__DOT__resultSrc_e_o) 
                                                       >> 2U)))) 
                                        & vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__read_data)) 
                                    | ((- (IData)((1U 
                                                   & ((IData)(vlSelf->top__DOT__resultSrc_e_o) 
                                                      >> 3U)))) 
                                       & vlSelf->top__DOT__pcPlus4_e_o));
    if ((1U & vlSelf->top__DOT__rs2_d_o)) {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 3U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 4U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 5U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 6U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_06 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 7U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_07 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 8U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_08 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 9U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_09 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xaU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_10 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xbU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_11 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xcU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_12 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xdU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_13 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xeU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_14 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xfU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_15 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x10U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_16 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x11U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_17 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x12U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_18 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x13U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_19 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x14U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_20 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x15U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_21 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x16U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_22 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x17U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_23 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x18U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_24 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x19U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_25 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1aU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_26 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1bU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_27 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1cU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_28 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1dU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_29 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1eU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_30 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1fU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_31 
            = (1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill));
    } else {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 2U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 3U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 4U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 5U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_06 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 6U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_07 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 7U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_08 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 8U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_09 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 9U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_10 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xaU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_11 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xbU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_12 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xcU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_13 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xdU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_14 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xeU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_15 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0xfU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_16 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x10U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_17 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x11U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_18 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x12U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_19 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x13U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_20 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x14U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_21 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x15U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_22 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x16U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_23 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x17U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_24 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x18U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_25 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x19U));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_26 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1aU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_27 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1bU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_28 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1cU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_29 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1dU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_30 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1eU));
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_31 
            = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                     >> 0x1fU));
    }
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__sign 
        = (((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__mul__ss) 
              & (3U == (IData)(vlSelf->top__DOT__mul_state_d_o))) 
             & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)) 
                >> 0xfU)) | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16su) 
                             & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                >> 0xfU))) | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                              & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
        = ((- (IData)((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                        >> 0xfU) & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu) 
                                    | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16su))))) 
           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem1 
        = (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub1 
                     >> 0x22U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dvd)) 
           & (0ULL != vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem2 
        = (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub2 
                     >> 0x22U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dvd)) 
           & (0ULL != vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub2));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa0__DOT__axorb 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa1__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 1U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 1U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa2__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 2U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 2U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa3__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 3U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa4__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 4U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 4U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa5__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 5U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 5U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa6__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 6U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 6U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa7__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 7U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 7U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa8__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 8U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 8U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa9__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 9U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                             >> 9U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa10__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0xaU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                               >> 0xaU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa11__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0xbU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                               >> 0xbU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa12__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0xcU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                               >> 0xcU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa13__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0xdU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                               >> 0xdU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa14__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0xeU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                               >> 0xeU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa15__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0xfU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                               >> 0xfU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa16__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x10U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x10U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa17__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x11U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x11U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa18__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x12U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x12U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa19__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x13U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x13U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa20__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x14U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x14U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa21__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x15U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x15U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa22__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x16U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x16U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa23__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x17U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x17U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa24__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x18U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x18U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa25__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x19U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x19U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa26__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x1aU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1aU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa27__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x1bU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1bU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa28__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x1cU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1cU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa29__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x1dU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1dU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa30__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x1eU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1eU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa31__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x1fU)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x1fU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa32__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x20U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x20U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa33__DOT__axorb 
        = (1U & ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                          >> 0x21U)) ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                >> 0x21U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa34__DOT__axorb 
        = (IData)(((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                    ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin) 
                   >> 0x22U));
    vlSelf->top__DOT__ptnt_e_i = ((IData)(vlSelf->top__DOT__hu__DOT__bpt) 
                                  & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken)));
    vlSelf->top__DOT__redirection_e_o = ((IData)(vlSelf->top__DOT__hu__DOT__Dcmiss_st_keep)
                                          ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__redirection_r)
                                          : ((((IData)(vlSelf->top__DOT__btype_d_o) 
                                               & (IData)(vlSelf->top__DOT__sbp_taken_d_o)) 
                                              ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken)) 
                                             | ((IData)(vlSelf->top__DOT__jalr_d_o) 
                                                & (~ (IData)(vlSelf->top__DOT__sbp_taken_d_o)))));
    vlSelf->top__DOT__hu__DOT__flush = ((((((IData)(vlSelf->top__DOT__hu__DOT__jd1) 
                                            | (IData)(vlSelf->top__DOT__hu__DOT__jd_b2)) 
                                           | (IData)(vlSelf->top__DOT__hu__DOT__bptnt)) 
                                          | ((IData)(vlSelf->top__DOT__hu__DOT__bpt) 
                                             & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken))) 
                                         | (IData)(vlSelf->top__DOT__hu__DOT__bnt1)) 
                                        | ((IData)(vlSelf->top__DOT__hu__DOT__bnt) 
                                           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0x7fU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | ((IData)((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                        >> 0xfU) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__zero)))) 
              << 7U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 0xfU) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                     | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                                 & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                    >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xbfU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (0x40U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                        >> 7U) & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__zero)) 
                                  << 6U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 0xdU) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                     | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                                 & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                    >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xdfU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (0x20U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                        >> 6U) & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__zero)) 
                                  << 5U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 0xbU) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                     | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                                 & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                    >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xf7U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (8U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 4U) & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__zero)) 
                               << 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 7U) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                   | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                               & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                  >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xfbU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (4U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 3U) & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__zero)) 
                               << 2U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 5U) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                   | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                               & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                  >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xefU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (0x10U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                        >> 5U) & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__zero)) 
                                  << 4U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 9U) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                   | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                               & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                  >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xfdU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (2U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 2U) & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__zero)) 
                               << 1U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 3U) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                   | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                               & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                  >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg 
        = ((0xfeU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)) 
           | (1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 1U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__zero)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__s 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__zero)) 
                 & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                     >> 1U) ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16us) 
                                   | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16uu))) 
                               & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ain) 
                                  >> 0xfU)))));
    vlSelf->id_instr = vlSelf->top__DOT__instruction_f_o;
    vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 0U;
    if ((0U == (3U & vlSelf->top__DOT__instruction_f_o))) {
        if ((0U == (7U & (vlSelf->top__DOT__instruction_f_o 
                          >> 0xdU)))) {
            if ((0U == (0xffU & (vlSelf->top__DOT__instruction_f_o 
                                 >> 5U)))) {
                vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
            }
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                = (0x10413U | ((0x3c000000U & (vlSelf->top__DOT__instruction_f_o 
                                               << 0x13U)) 
                               | ((0x3000000U & (vlSelf->top__DOT__instruction_f_o 
                                                 << 0xdU)) 
                                  | ((0x800000U & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x12U)) 
                                     | ((0x400000U 
                                         & (vlSelf->top__DOT__instruction_f_o 
                                            << 0x10U)) 
                                        | (0x380U & 
                                           (vlSelf->top__DOT__instruction_f_o 
                                            << 5U)))))));
        } else {
            if ((2U != (7U & (vlSelf->top__DOT__instruction_f_o 
                              >> 0xdU)))) {
                if ((6U != (7U & (vlSelf->top__DOT__instruction_f_o 
                                  >> 0xdU)))) {
                    vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                }
            }
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
            if ((2U == (7U & (vlSelf->top__DOT__instruction_f_o 
                              >> 0xdU)))) {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x42403U | ((0x4000000U & (vlSelf->top__DOT__instruction_f_o 
                                                  << 0x15U)) 
                                   | ((0x3800000U & 
                                       (vlSelf->top__DOT__instruction_f_o 
                                        << 0xdU)) | 
                                      ((0x400000U & 
                                        (vlSelf->top__DOT__instruction_f_o 
                                         << 0x10U)) 
                                       | ((0x38000U 
                                           & (vlSelf->top__DOT__instruction_f_o 
                                              << 8U)) 
                                          | (0x380U 
                                             & (vlSelf->top__DOT__instruction_f_o 
                                                << 5U)))))));
            } else if ((6U == (7U & (vlSelf->top__DOT__instruction_f_o 
                                     >> 0xdU)))) {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x842023U | ((0x4000000U & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x15U)) 
                                    | ((0x2000000U 
                                        & (vlSelf->top__DOT__instruction_f_o 
                                           << 0xdU)) 
                                       | ((0x700000U 
                                           & (vlSelf->top__DOT__instruction_f_o 
                                              << 0x12U)) 
                                          | ((0x38000U 
                                              & (vlSelf->top__DOT__instruction_f_o 
                                                 << 8U)) 
                                             | ((0xc00U 
                                                 & vlSelf->top__DOT__instruction_f_o) 
                                                | (0x200U 
                                                   & (vlSelf->top__DOT__instruction_f_o 
                                                      << 3U))))))));
            }
        }
    } else if ((1U == (3U & vlSelf->top__DOT__instruction_f_o))) {
        if ((0x8000U & vlSelf->top__DOT__instruction_f_o)) {
            if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                          >> 0xeU)))) {
                if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                              >> 0xdU)))) {
                    if ((0x800U & vlSelf->top__DOT__instruction_f_o)) {
                        if ((0x400U & vlSelf->top__DOT__instruction_f_o)) {
                            if ((0x1000U & vlSelf->top__DOT__instruction_f_o)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                            }
                        }
                    } else if ((0x1000U & vlSelf->top__DOT__instruction_f_o)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                    }
                }
            }
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
            if ((0x4000U & vlSelf->top__DOT__instruction_f_o)) {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x40063U | (((- (IData)((1U 
                                                & (vlSelf->top__DOT__instruction_f_o 
                                                   >> 0xcU)))) 
                                    << 0x1cU) | ((0xc000000U 
                                                  & (vlSelf->top__DOT__instruction_f_o 
                                                     << 0x15U)) 
                                                 | ((0x2000000U 
                                                     & (vlSelf->top__DOT__instruction_f_o 
                                                        << 0x17U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->top__DOT__instruction_f_o 
                                                           << 8U)) 
                                                       | ((0x1000U 
                                                           & (vlSelf->top__DOT__instruction_f_o 
                                                              >> 1U)) 
                                                          | ((0xc00U 
                                                              & vlSelf->top__DOT__instruction_f_o) 
                                                             | ((0x300U 
                                                                 & (vlSelf->top__DOT__instruction_f_o 
                                                                    << 5U)) 
                                                                | (0x80U 
                                                                   & (vlSelf->top__DOT__instruction_f_o 
                                                                      >> 5U))))))))));
            } else if ((0x2000U & vlSelf->top__DOT__instruction_f_o)) {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x6fU | ((0x80000000U & (vlSelf->top__DOT__instruction_f_o 
                                                << 0x13U)) 
                                | ((0x40000000U & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x16U)) 
                                   | ((0x30000000U 
                                       & (vlSelf->top__DOT__instruction_f_o 
                                          << 0x13U)) 
                                      | ((0x8000000U 
                                          & (vlSelf->top__DOT__instruction_f_o 
                                             << 0x15U)) 
                                         | ((0x4000000U 
                                             & (vlSelf->top__DOT__instruction_f_o 
                                                << 0x13U)) 
                                            | ((0x2000000U 
                                                & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x17U)) 
                                               | ((0x1000000U 
                                                   & (vlSelf->top__DOT__instruction_f_o 
                                                      << 0xdU)) 
                                                  | ((0xe00000U 
                                                      & (vlSelf->top__DOT__instruction_f_o 
                                                         << 0x12U)) 
                                                     | ((0x1ff000U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->top__DOT__instruction_f_o 
                                                                           >> 0xcU)))) 
                                                            << 0xcU)) 
                                                        | (0x80U 
                                                           & ((~ 
                                                               (vlSelf->top__DOT__instruction_f_o 
                                                                >> 0xfU)) 
                                                              << 7U))))))))))));
            } else if ((0x800U & vlSelf->top__DOT__instruction_f_o)) {
                if ((0x400U & vlSelf->top__DOT__instruction_f_o)) {
                    if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                                  >> 0xcU)))) {
                        vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                            = ((0x40U & vlSelf->top__DOT__instruction_f_o)
                                ? ((0x20U & vlSelf->top__DOT__instruction_f_o)
                                    ? (0x847433U | 
                                       ((0x700000U 
                                         & (vlSelf->top__DOT__instruction_f_o 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->top__DOT__instruction_f_o 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->top__DOT__instruction_f_o))))
                                    : (0x846433U | 
                                       ((0x700000U 
                                         & (vlSelf->top__DOT__instruction_f_o 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->top__DOT__instruction_f_o 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->top__DOT__instruction_f_o)))))
                                : ((0x20U & vlSelf->top__DOT__instruction_f_o)
                                    ? (0x844433U | 
                                       ((0x700000U 
                                         & (vlSelf->top__DOT__instruction_f_o 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->top__DOT__instruction_f_o 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->top__DOT__instruction_f_o))))
                                    : (0x40840433U 
                                       | ((0x700000U 
                                           & (vlSelf->top__DOT__instruction_f_o 
                                              << 0x12U)) 
                                          | ((0x38000U 
                                              & (vlSelf->top__DOT__instruction_f_o 
                                                 << 8U)) 
                                             | (0x380U 
                                                & vlSelf->top__DOT__instruction_f_o))))));
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                        = (0x47413U | (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT__instruction_f_o 
                                                       >> 0xcU)))) 
                                        << 0x1aU) | 
                                       ((0x2000000U 
                                         & (vlSelf->top__DOT__instruction_f_o 
                                            << 0xdU)) 
                                        | ((0x1f00000U 
                                            & (vlSelf->top__DOT__instruction_f_o 
                                               << 0x12U)) 
                                           | ((0x38000U 
                                               & (vlSelf->top__DOT__instruction_f_o 
                                                  << 8U)) 
                                              | (0x380U 
                                                 & vlSelf->top__DOT__instruction_f_o))))));
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x45413U | ((0x40000000U & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x14U)) 
                                   | ((0x1f00000U & 
                                       (vlSelf->top__DOT__instruction_f_o 
                                        << 0x12U)) 
                                      | ((0x38000U 
                                          & (vlSelf->top__DOT__instruction_f_o 
                                             << 8U)) 
                                         | (0x380U 
                                            & vlSelf->top__DOT__instruction_f_o)))));
            }
        } else if ((0x4000U & vlSelf->top__DOT__instruction_f_o)) {
            if ((0x2000U & vlSelf->top__DOT__instruction_f_o)) {
                if ((0U == ((0x20U & (vlSelf->top__DOT__instruction_f_o 
                                      >> 7U)) | (0x1fU 
                                                 & (vlSelf->top__DOT__instruction_f_o 
                                                    >> 2U))))) {
                    vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                }
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = ((2U == (0x1fU & (vlSelf->top__DOT__instruction_f_o 
                                        >> 7U))) ? 
                       (0x10113U | (((- (IData)((1U 
                                                 & (vlSelf->top__DOT__instruction_f_o 
                                                    >> 0xcU)))) 
                                     << 0x1dU) | ((0x18000000U 
                                                   & (vlSelf->top__DOT__instruction_f_o 
                                                      << 0x18U)) 
                                                  | ((0x4000000U 
                                                      & (vlSelf->top__DOT__instruction_f_o 
                                                         << 0x15U)) 
                                                     | ((0x2000000U 
                                                         & (vlSelf->top__DOT__instruction_f_o 
                                                            << 0x17U)) 
                                                        | (0x1000000U 
                                                           & (vlSelf->top__DOT__instruction_f_o 
                                                              << 0x12U)))))))
                        : (0x37U | (((- (IData)((1U 
                                                 & (vlSelf->top__DOT__instruction_f_o 
                                                    >> 0xcU)))) 
                                     << 0x11U) | ((0x1f000U 
                                                   & (vlSelf->top__DOT__instruction_f_o 
                                                      << 0xaU)) 
                                                  | (0xf80U 
                                                     & vlSelf->top__DOT__instruction_f_o)))));
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x13U | (((- (IData)((1U & (vlSelf->top__DOT__instruction_f_o 
                                                   >> 0xcU)))) 
                                 << 0x1aU) | ((0x2000000U 
                                               & (vlSelf->top__DOT__instruction_f_o 
                                                  << 0xdU)) 
                                              | ((0x1f00000U 
                                                  & (vlSelf->top__DOT__instruction_f_o 
                                                     << 0x12U)) 
                                                 | (0xf80U 
                                                    & vlSelf->top__DOT__instruction_f_o)))));
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                = ((0x2000U & vlSelf->top__DOT__instruction_f_o)
                    ? (0x6fU | ((0x80000000U & (vlSelf->top__DOT__instruction_f_o 
                                                << 0x13U)) 
                                | ((0x40000000U & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x16U)) 
                                   | ((0x30000000U 
                                       & (vlSelf->top__DOT__instruction_f_o 
                                          << 0x13U)) 
                                      | ((0x8000000U 
                                          & (vlSelf->top__DOT__instruction_f_o 
                                             << 0x15U)) 
                                         | ((0x4000000U 
                                             & (vlSelf->top__DOT__instruction_f_o 
                                                << 0x13U)) 
                                            | ((0x2000000U 
                                                & (vlSelf->top__DOT__instruction_f_o 
                                                   << 0x17U)) 
                                               | ((0x1000000U 
                                                   & (vlSelf->top__DOT__instruction_f_o 
                                                      << 0xdU)) 
                                                  | ((0xe00000U 
                                                      & (vlSelf->top__DOT__instruction_f_o 
                                                         << 0x12U)) 
                                                     | ((0x1ff000U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->top__DOT__instruction_f_o 
                                                                           >> 0xcU)))) 
                                                            << 0xcU)) 
                                                        | (0x80U 
                                                           & ((~ 
                                                               (vlSelf->top__DOT__instruction_f_o 
                                                                >> 0xfU)) 
                                                              << 7U))))))))))))
                    : (0x13U | (((- (IData)((1U & (vlSelf->top__DOT__instruction_f_o 
                                                   >> 0xcU)))) 
                                 << 0x1aU) | ((0x2000000U 
                                               & (vlSelf->top__DOT__instruction_f_o 
                                                  << 0xdU)) 
                                              | ((0x1f00000U 
                                                  & (vlSelf->top__DOT__instruction_f_o 
                                                     << 0x12U)) 
                                                 | ((0xf8000U 
                                                     & (vlSelf->top__DOT__instruction_f_o 
                                                        << 8U)) 
                                                    | (0xf80U 
                                                       & vlSelf->top__DOT__instruction_f_o)))))));
        }
    } else if ((2U == (3U & vlSelf->top__DOT__instruction_f_o))) {
        if ((0x8000U & vlSelf->top__DOT__instruction_f_o)) {
            if ((0x4000U & vlSelf->top__DOT__instruction_f_o)) {
                if ((0x2000U & vlSelf->top__DOT__instruction_f_o)) {
                    vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                }
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
                if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                              >> 0xdU)))) {
                    vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                        = (0x12023U | ((0xc000000U 
                                        & (vlSelf->top__DOT__instruction_f_o 
                                           << 0x13U)) 
                                       | ((0x2000000U 
                                           & (vlSelf->top__DOT__instruction_f_o 
                                              << 0xdU)) 
                                          | ((0x1f00000U 
                                              & (vlSelf->top__DOT__instruction_f_o 
                                                 << 0x12U)) 
                                             | (0xe00U 
                                                & vlSelf->top__DOT__instruction_f_o)))));
                }
            } else {
                if ((0x2000U & vlSelf->top__DOT__instruction_f_o)) {
                    vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                } else if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                                     >> 0xcU)))) {
                    if ((0U == (0x1fU & (vlSelf->top__DOT__instruction_f_o 
                                         >> 2U)))) {
                        if ((0U == (0x1fU & (vlSelf->top__DOT__instruction_f_o 
                                             >> 7U)))) {
                            vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
                        }
                    }
                }
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
                if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                              >> 0xdU)))) {
                    vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                        = ((0x1000U & vlSelf->top__DOT__instruction_f_o)
                            ? ((0U != (0x1fU & (vlSelf->top__DOT__instruction_f_o 
                                                >> 2U)))
                                ? (0x33U | ((0x1f00000U 
                                             & (vlSelf->top__DOT__instruction_f_o 
                                                << 0x12U)) 
                                            | ((0xf8000U 
                                                & (vlSelf->top__DOT__instruction_f_o 
                                                   << 8U)) 
                                               | (0xf80U 
                                                  & vlSelf->top__DOT__instruction_f_o))))
                                : ((0U == (0x1fU & 
                                           (vlSelf->top__DOT__instruction_f_o 
                                            >> 7U)))
                                    ? 0x100073U : (0xe7U 
                                                   | (0xf8000U 
                                                      & (vlSelf->top__DOT__instruction_f_o 
                                                         << 8U)))))
                            : ((0U != (0x1fU & (vlSelf->top__DOT__instruction_f_o 
                                                >> 2U)))
                                ? (0x33U | ((0x1f00000U 
                                             & (vlSelf->top__DOT__instruction_f_o 
                                                << 0x12U)) 
                                            | (0xf80U 
                                               & vlSelf->top__DOT__instruction_f_o)))
                                : (0x67U | (0xf8000U 
                                            & (vlSelf->top__DOT__instruction_f_o 
                                               << 8U)))));
                }
            }
        } else if ((0x4000U & vlSelf->top__DOT__instruction_f_o)) {
            if ((0x2000U & vlSelf->top__DOT__instruction_f_o)) {
                vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
            } else if ((0U == (0x1fU & (vlSelf->top__DOT__instruction_f_o 
                                        >> 7U)))) {
                vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
            }
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
            if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                          >> 0xdU)))) {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x12003U | ((0xc000000U & (vlSelf->top__DOT__instruction_f_o 
                                                  << 0x18U)) 
                                   | ((0x2000000U & 
                                       (vlSelf->top__DOT__instruction_f_o 
                                        << 0xdU)) | 
                                      ((0x1c00000U 
                                        & (vlSelf->top__DOT__instruction_f_o 
                                           << 0x12U)) 
                                       | (0xf80U & vlSelf->top__DOT__instruction_f_o)))));
            }
        } else {
            if ((0x2000U & vlSelf->top__DOT__instruction_f_o)) {
                vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
            } else if ((0x1000U & vlSelf->top__DOT__instruction_f_o)) {
                vlSelf->top__DOT__u_pipelineID__DOT__compress_instr_illegal = 1U;
            }
            vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
            if ((1U & (~ (vlSelf->top__DOT__instruction_f_o 
                          >> 0xdU)))) {
                vlSelf->top__DOT__u_pipelineID__DOT__instr_o 
                    = (0x1013U | ((0x1f00000U & (vlSelf->top__DOT__instruction_f_o 
                                                 << 0x12U)) 
                                  | ((0xf8000U & (vlSelf->top__DOT__instruction_f_o 
                                                  << 8U)) 
                                     | (0xf80U & vlSelf->top__DOT__instruction_f_o))));
            }
        }
    } else {
        vlSelf->top__DOT__u_pipelineID__DOT__instr_o = 0x13U;
    }
    vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o = 1U;
    if ((0U != (3U & vlSelf->top__DOT__instruction_f_o))) {
        if ((1U != (3U & vlSelf->top__DOT__instruction_f_o))) {
            if ((2U != (3U & vlSelf->top__DOT__instruction_f_o))) {
                vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o = 0U;
            }
        }
    }
    if ((2U & vlSelf->top__DOT__rs2_d_o)) {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_06;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_07;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_08;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_09;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_10;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_11;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_12;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_13;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_12 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_14;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_13 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_15;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_14 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_16;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_15 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_17;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_16 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_18;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_17 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_19;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_18 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_20;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_19 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_21;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_20 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_22;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_21 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_23;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_22 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_24;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_23 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_25;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_24 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_26;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_25 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_27;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_26 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_28;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_27 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_29;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_28 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_30;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_30 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_29 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_31;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_31 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
    } else {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_06;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_07;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_08;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_09;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_10;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_11;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_12 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_12;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_13 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_13;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_14 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_14;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_15 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_15;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_16 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_16;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_17 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_17;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_18 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_18;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_19 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_19;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_20 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_20;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_21 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_21;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_22 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_22;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_23 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_23;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_24 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_24;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_25 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_25;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_26 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_26;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_27 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_27;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_28 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_28;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_30 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_30;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_29 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_29;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_31 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_31;
    }
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffffeULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | (IData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa0__DOT__axorb) 
                                    ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffffeULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | (IData)((IData)((1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt) 
                                     & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa0__DOT__axorb)) 
                                    | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain) 
                                       & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin)))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffffdULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa1__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 1U)))))) 
              << 1U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffffdULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 1U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa1__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 1U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 1U))))))) 
              << 1U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffffbULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa2__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 2U)))))) 
              << 2U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffffbULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 2U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa2__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 2U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 2U))))))) 
              << 2U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffff7ULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa3__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 3U)))))) 
              << 3U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffff7ULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 3U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa3__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 3U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 3U))))))) 
              << 3U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffffefULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa4__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 4U)))))) 
              << 4U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffffefULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 4U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa4__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 4U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 4U))))))) 
              << 4U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffffdfULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa5__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 5U)))))) 
              << 5U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffffdfULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 5U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa5__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 5U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 5U))))))) 
              << 5U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffffbfULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa6__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 6U)))))) 
              << 6U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffffbfULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 6U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa6__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 6U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 6U))))))) 
              << 6U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffff7fULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa7__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 7U)))))) 
              << 7U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffff7fULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 7U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa7__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 7U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 7U))))))) 
              << 7U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffeffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa8__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 8U)))))) 
              << 8U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffeffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 8U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa8__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 8U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 8U))))))) 
              << 8U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffdffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa9__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 9U)))))) 
              << 9U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffdffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 9U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa9__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 9U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 9U))))))) 
              << 9U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffffbffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa10__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xaU)))))) 
              << 0xaU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffffbffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0xaU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa10__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0xaU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0xaU))))))) 
              << 0xaU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffff7ffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa11__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xbU)))))) 
              << 0xbU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffff7ffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0xbU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa11__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0xbU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0xbU))))))) 
              << 0xbU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffefffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa12__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xcU)))))) 
              << 0xcU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffefffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0xcU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa12__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0xcU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0xcU))))))) 
              << 0xcU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffdfffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa13__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xdU)))))) 
              << 0xdU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffdfffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0xdU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa13__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0xdU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0xdU))))))) 
              << 0xdU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffffbfffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa14__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xeU)))))) 
              << 0xeU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffffbfffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0xeU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa14__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0xeU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0xeU))))))) 
              << 0xeU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffff7fffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa15__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0xfU)))))) 
              << 0xfU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffff7fffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0xfU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa15__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0xfU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0xfU))))))) 
              << 0xfU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffeffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa16__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x10U)))))) 
              << 0x10U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffeffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x10U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa16__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x10U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x10U))))))) 
              << 0x10U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffdffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa17__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x11U)))))) 
              << 0x11U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffdffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x11U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa17__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x11U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x11U))))))) 
              << 0x11U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fffbffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa18__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x12U)))))) 
              << 0x12U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fffbffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x12U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa18__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x12U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x12U))))))) 
              << 0x12U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fff7ffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa19__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x13U)))))) 
              << 0x13U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fff7ffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x13U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa19__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x13U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x13U))))))) 
              << 0x13U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffefffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa20__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x14U)))))) 
              << 0x14U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffefffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x14U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa20__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x14U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x14U))))))) 
              << 0x14U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffdfffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa21__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x15U)))))) 
              << 0x15U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffdfffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x15U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa21__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x15U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x15U))))))) 
              << 0x15U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ffbfffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa22__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x16U)))))) 
              << 0x16U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ffbfffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x16U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa22__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x16U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x16U))))))) 
              << 0x16U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7ff7fffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa23__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x17U)))))) 
              << 0x17U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7ff7fffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x17U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa23__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x17U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x17U))))))) 
              << 0x17U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7feffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa24__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x18U)))))) 
              << 0x18U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7feffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x18U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa24__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x18U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x18U))))))) 
              << 0x18U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fdffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa25__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x19U)))))) 
              << 0x19U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fdffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x19U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa25__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x19U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x19U))))))) 
              << 0x19U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7fbffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa26__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1aU)))))) 
              << 0x1aU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7fbffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x1aU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa26__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x1aU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x1aU))))))) 
              << 0x1aU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7f7ffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa27__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1bU)))))) 
              << 0x1bU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7f7ffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x1bU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa27__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x1bU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x1bU))))))) 
              << 0x1bU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7efffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa28__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1cU)))))) 
              << 0x1cU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7efffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x1cU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa28__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x1cU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x1cU))))))) 
              << 0x1cU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7dfffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa29__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1dU)))))) 
              << 0x1dU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7dfffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x1dU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa29__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x1dU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x1dU))))))) 
              << 0x1dU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x7bfffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa30__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1eU)))))) 
              << 0x1eU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x7bfffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x1eU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa30__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x1eU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x1eU))))))) 
              << 0x1eU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x77fffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa31__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x1fU)))))) 
              << 0x1fU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x77fffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x1fU)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa31__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x1fU)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x1fU))))))) 
              << 0x1fU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x6ffffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa32__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x20U)))))) 
              << 0x20U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x6ffffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x20U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa32__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x20U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x20U))))))) 
              << 0x20U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x5ffffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)((1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa33__DOT__axorb) 
                                     ^ (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                                >> 0x21U)))))) 
              << 0x21U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x5ffffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x21U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa33__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x21U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x21U))))))) 
              << 0x21U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
        = ((0x3ffffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps) 
           | ((QData)((IData)(((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa34__DOT__axorb) 
                               ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                  >> 0x22U)))) << 0x22U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
        = ((0x3ffffffffULL & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc) 
           | ((QData)((IData)((1U & (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvs_ivt 
                                               >> 0x22U)) 
                                      & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__csa_35__DOT__fa34__DOT__axorb)) 
                                     | ((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__ain 
                                                 >> 0x22U)) 
                                        & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT____Vcellinp__csa_35__bin 
                                                   >> 0x22U))))))) 
              << 0x22U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0x7fU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__s) 
              << 7U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
        = (((- (IData)((1U & VL_REDXOR_16((0x6000U 
                                           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 0xeU)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                  >> 0xdU)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 0xfU) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 0xdU)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b7__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 0xfU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xbfU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__s) 
              << 6U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
        = (((- (IData)((1U & VL_REDXOR_16((0x1800U 
                                           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 0xcU)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                  >> 0xbU)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 0xdU) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 0xbU)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b6__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 0xdU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xdfU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__s) 
              << 5U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
        = (((- (IData)((1U & VL_REDXOR_16((0x600U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 0xaU)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                  >> 9U)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 0xbU) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 9U)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b5__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 0xbU)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xf7U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__s) 
              << 3U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
        = (((- (IData)((1U & VL_REDXOR_8((0x60U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 6U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 5U)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 7U) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 5U)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b3__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 7U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xfbU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__s) 
              << 2U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
        = (((- (IData)((1U & VL_REDXOR_8((0x18U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 4U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 3U)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 5U) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 3U)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b2__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 5U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xefU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__s) 
              << 4U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
        = (((- (IData)((1U & VL_REDXOR_16((0x180U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 8U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 7U)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 9U) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 7U)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b4__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 9U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xfdU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__s) 
              << 1U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
        = (((- (IData)((1U & VL_REDXOR_4((6U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__mcand_comp))) 
           | ((- (IData)((1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                     >> 2U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                                >> 1U)) 
                                & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                    >> 3U) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                              >> 1U)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b1__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 3U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffffffeU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign 
        = ((0xfeU & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign)) 
           | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__s));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
        = (((- (IData)((1U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))) 
            & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__s) 
                << 0x10U) | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__mcand_comp))) 
           | ((- (IData)((IData)((2U == (3U & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin)))))) 
              & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__b0__DOT__mcand_comp) 
                  << 1U) | (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16bin) 
                                  >> 1U)))));
    vlSelf->top__DOT__u_pipelineID__DOT__pc_next = 
        (((- (IData)((IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o))) 
          & ((IData)(2U) + vlSelf->top__DOT__u_pipelineID__DOT__pc_instr)) 
         | ((- (IData)((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o))))) 
            & ((IData)(4U) + vlSelf->top__DOT__u_pipelineID__DOT__pc_instr)));
    vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
        = ((IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o)
            ? vlSelf->top__DOT__u_pipelineID__DOT__instr_o
            : vlSelf->top__DOT__instruction_f_o);
    if ((4U & vlSelf->top__DOT__rs2_d_o)) {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_08 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_12;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_13;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_14;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_15;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_16;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_17;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_18;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_19;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_16 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_20;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_17 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_21;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_18 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_22;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_19 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_23;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_20 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_24;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_21 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_25;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_22 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_26;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_23 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_27;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_28 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_24 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_28;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_30 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_26 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_30;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_29 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_25 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_29;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_31 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_27 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_31;
    } else {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_08 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_12;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_13;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_14;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_15;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_16 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_16;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_17 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_17;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_18 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_18;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_19 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_19;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_20 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_20;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_21 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_21;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_22 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_22;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_23 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_23;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_28 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_28;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_24 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_24;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_30 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_30;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_26 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_26;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_29 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_29;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_25 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_25;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_31 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_31;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_27 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_27;
    }
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub3 
        = (0x7ffffffffULL & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_ps 
                              + ((0x7fffffffeULL & 
                                  (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sub3_pc 
                                   << 1U)) | (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))) 
                             + (- (QData)((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_quot)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_0_0__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_0_1__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                  >> 7U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                            >> 5U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                  >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                            >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                  >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                            >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                  >> 7U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                            >> 5U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                  >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                            >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_1 
        = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                    >> 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c8_0_1 
        = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                 & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                    >> 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_0_1__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 5U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                            >> 3U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa10_0_1__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 2U) ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                            >> 2U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 7U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                            >> 5U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 9U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                            >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 6U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                            >> 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                            >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 0xdU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                               >> 0xbU)) ^ (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                               >> 0xfU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_0 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                  >> 0xfU) | (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_2 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                  >> 1U) ^ (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                  >> 7U) ^ (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                               >> 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_2 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                  >> 1U) & (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffffffcU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (3U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fffffefU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (0x10U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                        << 1U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                  << 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa2_0_0__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 2U) ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_0_0__DOT__axorb 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 5U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                            >> 3U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                            >> 2U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 6U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                            >> 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 7U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                            >> 5U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                            >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 9U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                            >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                              >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0xaU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                              >> 8U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0xdU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                              >> 0xbU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0xeU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                              >> 0xcU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0xfU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                              >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0x10U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                               >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                  >> 0xbU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                              >> 9U)));
    if ((0x73U == vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();
    }
    vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 0U;
    if ((0x40U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 4U)))) {
                if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 1U;
                                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 8U;
                            } else {
                                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                            }
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    }
                } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 8U;
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    }
                } else {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 0U;
                        }
                    }
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
            }
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 0U;
            if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            } else if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & (~ vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))) {
                            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & (~ vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))) {
                        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                  >> 0xeU)))) {
                        if ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                        }
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 0U;
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
        }
    } else if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 3U)))) {
                if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 2U;
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    }
                } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
            }
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 0U;
            if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & (~ vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))) {
                        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & (~ vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))) {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            }
        } else {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 3U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 2U)))) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 0U;
                        }
                    }
                }
            }
            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 0U;
            if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((0U != (7U & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                      >> 0xcU)))) {
                        if ((1U != (7U & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                          >> 0xcU)))) {
                            if ((2U != (7U & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 0xcU)))) {
                                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                            }
                        }
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            }
        }
    } else if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                      >> 3U)))) {
            if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                }
            } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o 
                        = (0x13U != vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits);
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
        }
        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 0U;
        if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
        } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & (~ vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))) {
                    vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            }
        } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))) {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
        }
    } else {
        if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                      >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 2U)))) {
                if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_en_o = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 4U;
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__wb_src_o = 1U;
        }
        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 0U;
        if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
        } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
        } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                    }
                } else if ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((0x1000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
                    }
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__decoder_instr_illegal = 1U;
        }
    }
    vlSelf->top__DOT__is_load_d_o = 0U;
    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                  >> 6U)))) {
        if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                      >> 5U)))) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 4U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__is_load_d_o = 1U;
                            }
                        }
                    }
                }
            }
        }
        vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o = 0U;
        if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 4U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                if ((0U == (7U & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                  >> 0xcU)))) {
                                    vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o = 1U;
                                } else if ((1U == (7U 
                                                   & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o = 2U;
                                } else if ((2U == (7U 
                                                   & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o = 3U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                             >> 4U)))) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 3U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 2U)))) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 0xdU)))) {
                                    vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o 
                                        = ((0x1000U 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                            ? 8U : 7U);
                                }
                            } else if ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 0xcU)))) {
                                    vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o = 6U;
                                }
                            } else {
                                vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o 
                                    = ((0x1000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? 5U : 4U);
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlSelf->top__DOT__u_pipelineID__DOT__dmem_type_o = 0U;
    }
    vlSelf->top__DOT__u_pipelineID__DOT__rs2_sel_o = 1U;
    if ((0x40U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 4U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__rs2_sel_o = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 3U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 2U)))) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__rs2_sel_o = 0U;
                        }
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__u_pipelineID__DOT__rs1_sel_o = 0U;
    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                  >> 6U)))) {
        if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                      >> 5U)))) {
            if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__rs1_sel_o = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__src2_sel_d_i = ((2U & (IData)(vlSelf->top__DOT__src2_sel_d_i)) 
                                      | ((0U != (0x1fU 
                                                 & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0x14U))) 
                                         & ((IData)(vlSelf->top__DOT__hu__DOT__dst_1) 
                                            == (0x1fU 
                                                & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                   >> 0x14U)))));
    vlSelf->top__DOT__u_pipelineID__DOT__rs2_data_o 
        = (((((0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                        >> 0x14U)) == (IData)(vlSelf->top__DOT__rd_idx_m_o)) 
             & (0U != (IData)(vlSelf->top__DOT__rd_idx_m_o))) 
            & (IData)(vlSelf->top__DOT__reg_write_en_m_o))
            ? vlSelf->top__DOT__write_back_data_w_o
            : vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data
           [(0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                      >> 0x14U))]);
    vlSelf->top__DOT__src2_sel_d_i = ((1U & (IData)(vlSelf->top__DOT__src2_sel_d_i)) 
                                      | ((((0U != (0x1fU 
                                                   & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                      >> 0x14U))) 
                                           & ((IData)(vlSelf->top__DOT__hu__DOT__dst_1) 
                                              != (IData)(vlSelf->top__DOT__hu__DOT__dst_2))) 
                                          & ((IData)(vlSelf->top__DOT__hu__DOT__dst_2) 
                                             == (0x1fU 
                                                 & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0x14U)))) 
                                         << 1U));
    vlSelf->top__DOT__u_pipelineID__DOT__rs1_data_o 
        = (((((0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                        >> 0xfU)) == (IData)(vlSelf->top__DOT__rd_idx_m_o)) 
             & (0U != (IData)(vlSelf->top__DOT__rd_idx_m_o))) 
            & (IData)(vlSelf->top__DOT__reg_write_en_m_o))
            ? vlSelf->top__DOT__write_back_data_w_o
            : vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data
           [(0x1fU & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                      >> 0xfU))]);
    vlSelf->top__DOT__hu__DOT__Ldhaz_st = ((IData)(vlSelf->top__DOT__hu__DOT__ld_dst1) 
                                           & (((IData)(vlSelf->top__DOT__hu__DOT__dst_1) 
                                               == (0x1fU 
                                                   & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                      >> 0xfU))) 
                                              | ((IData)(vlSelf->top__DOT__hu__DOT__dst_1) 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                     >> 0x14U)))));
    vlSelf->top__DOT__src1_sel_d_i = ((2U & (IData)(vlSelf->top__DOT__src1_sel_d_i)) 
                                      | ((0U != (0x1fU 
                                                 & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0xfU))) 
                                         & ((IData)(vlSelf->top__DOT__hu__DOT__dst_1) 
                                            == (0x1fU 
                                                & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                   >> 0xfU)))));
    vlSelf->top__DOT__src1_sel_d_i = ((1U & (IData)(vlSelf->top__DOT__src1_sel_d_i)) 
                                      | ((((0U != (0x1fU 
                                                   & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                      >> 0xfU))) 
                                           & ((IData)(vlSelf->top__DOT__hu__DOT__dst_1) 
                                              != (IData)(vlSelf->top__DOT__hu__DOT__dst_2))) 
                                          & ((IData)(vlSelf->top__DOT__hu__DOT__dst_2) 
                                             == (0x1fU 
                                                 & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0xfU)))) 
                                         << 1U));
    vlSelf->top__DOT__u_pipelineID__DOT__branchJALR_o = 0U;
    if ((0x40U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
        if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 4U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__branchJALR_o = 1U;
                            }
                        }
                    }
                }
                vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o = 0U;
                if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o = 1U;
                                vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                                vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 1U;
                            } else {
                                vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                            }
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 2U;
                            }
                        }
                    } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 4U;
                        }
                    }
                }
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                if ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                    if ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                        if ((1U & (~ 
                                                   (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0xcU)))) {
                                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0xcU)))) {
                                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                if ((8U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                            }
                        }
                    }
                } else if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation 
                                = ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                    ? 0x200U : 0x100U);
                        } else if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                             >> 0xdU)))) {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 2U;
                        }
                    }
                }
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq = 0U;
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                              >> 0xeU)))) {
                                    if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                  >> 0xdU)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                    >> 0xcU)))) {
                                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq = 1U;
                                        }
                                    }
                                }
                                vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
                                vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 1U;
                            } else {
                                vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
                            }
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o = 0U;
                vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq = 0U;
                vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o = 0U;
            vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq = 0U;
            vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
        }
    } else {
        vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o = 0U;
        vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
        if ((0x20U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 3U)))) {
                    if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                                vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 0U;
                                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                            } else {
                                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                            }
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        }
                    } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 6U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation 
                                = ((0x2000000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                    ? ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? ((0x2000U 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                            ? ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 0x20000U
                                                : 0x10000U)
                                            : ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 0x8000U
                                                : 0x4000U))
                                        : ((0x2000U 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                            ? ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 0x1000U
                                                : 0x2000U)
                                            : ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 0x800U
                                                : 0x400U)))
                                    : ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? ((0x2000U 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                            ? ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 0x40U
                                                : 0x20U)
                                            : ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                    ? 0x10U
                                                    : 8U)
                                                : 0x80U))
                                        : ((0x2000U 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                            ? ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 0x200U
                                                : 0x100U)
                                            : ((0x1000U 
                                                & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                ? 4U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                                    ? 2U
                                                    : 1U)))));
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                }
            } else if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                              >> 2U)))) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 5U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
            }
        } else if ((0x10U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 3U)))) {
                if ((4U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                            vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        } else {
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        }
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                    }
                } else if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 2U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation 
                            = ((0x4000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                ? ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                    ? ((0x1000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? 0x40U : 0x20U)
                                    : ((0x1000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? ((0x40000000U 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                            ? 0x10U
                                            : 8U) : 0x80U))
                                : ((0x2000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                    ? ((0x1000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? 0x200U : 0x100U)
                                    : ((0x1000U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)
                                        ? 4U : 1U)));
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
            }
        } else if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                          >> 2U)))) {
                if ((2U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                    if ((1U & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits)) {
                        vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o = 2U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                    } else {
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                    }
                } else {
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                    vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
                }
            } else {
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
                vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
            }
        } else {
            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt = 0U;
            vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation = 1U;
        }
        vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq = 0U;
        vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o = 0U;
    }
    if ((8U & vlSelf->top__DOT__rs2_d_o)) {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_28 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_20 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_28;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_24 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_16 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_24;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_30 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_22 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_30;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_26 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_18 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_26;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_29 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_21 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_29;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_25 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_17 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_25;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_31 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_23 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_31;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_27 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_19 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_27;
    } else {
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_28 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_28;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_20 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_20;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_24 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_24;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_16 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_16;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_30 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_30;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_22 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_22;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_26 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_26;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_18 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_18;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_29 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_29;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_21 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_21;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_25 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_25;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_17 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_17;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_31 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_31;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_23 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_23;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_27 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_27;
        vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_19 
            = vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_19;
    }
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_rem3 
        = (((IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub3 
                     >> 0x22U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__sign_dvd)) 
           & (0ULL != vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem_sub3));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_0_0 
        = (1U & (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                      >> 6U)) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_0_0__DOT__axorb)) 
                 | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 0xfU) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                 >> 0xdU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_0_0__DOT__axorb) 
                 ^ (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                       >> 6U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_0_1__DOT__axorb) 
                 ^ (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                       >> 2U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w3 
        = (1U & ((~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 0xcU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                   >> 0xbU) ^ (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                  >> 5U))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct27_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 0xbU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w3 
        = (1U & ((~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 4U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 3U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                               >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                   >> 3U) ^ (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                >> 1U))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                   >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                               >> 0xaU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct26_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct25_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 0xbU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                   >> 0xbU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                               >> 9U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                   >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                             >> 2U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 4U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 8U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                   >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 0xaU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 0xbU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                   >> 0xbU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 9U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_0_1__DOT__axorb) 
                 ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                    >> 1U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_1 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 1U) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_0_1__DOT__axorb)) 
                 | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 5U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_1 
        = (1U & ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                   >> 5U) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa10_0_1__DOT__axorb)) 
                 | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 2U) & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s10_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa10_0_1__DOT__axorb) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                    >> 5U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w3 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                  ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                     >> 6U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                               >> 0xaU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 3U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                               >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                             >> 1U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 5U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                               >> 9U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 5U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                             >> 3U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 2U) ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 2U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                               >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                             >> 2U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 4U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                               >> 8U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                   >> 0xbU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                               >> 9U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                     >> 0xbU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 0xbU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                   >> 0xbU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                               >> 9U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                   >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                               >> 0xaU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                   >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                               >> 0xaU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffffffbU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (4U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa2_0_0__DOT__axorb) 
                     << 2U) ^ (0xfffffffcU & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                              << 1U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffffff3U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (8U & ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                      << 2U) & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa2_0_0__DOT__axorb) 
                                << 3U)) | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                            << 1U) 
                                           & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                              << 3U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c5_0_0 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 1U) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_0_0__DOT__axorb)) 
                 | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                     >> 5U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                               >> 3U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s5_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_0_0__DOT__axorb) 
                 ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                    >> 1U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w3 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                  ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                     >> 2U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w1)
                  ? vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                     >> 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 2U) ^ vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct6_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 2U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 1U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct7_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 3U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 4U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 2U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct8_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 4U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 8U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 5U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 3U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 5U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 9U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 8U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 0xcU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 8U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 6U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 6U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 4U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 6U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 9U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 7U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 9U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 0xdU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 0xaU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                 >> 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 0xaU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                               >> 8U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 0xbU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                               >> 9U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 0xbU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                 >> 0xfU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 0xcU) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                                 >> 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 0xcU) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                               >> 0xaU)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                     >> 7U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0 
                               >> 0xbU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder2 
                   >> 7U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                             >> 5U)) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w1)));
    vlSelf->top__DOT__de_st_d_i = ((IData)(vlSelf->top__DOT__hu__DOT__Ldhaz_st) 
                                   | (IData)(vlSelf->top__DOT__hu__DOT__Dcmiss_st_keep));
    vlSelf->top__DOT__is_j_d_o = ((IData)(vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o) 
                                  | (IData)(vlSelf->top__DOT__u_pipelineID__DOT__branchJALR_o));
    vlSelf->top__DOT__u_pipelineID__DOT__imm_o = ((4U 
                                                   & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o))
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                  >> 0x1fU))) 
                                                      << 0xcU) 
                                                     | ((0xfe0U 
                                                         & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                            >> 0x14U)) 
                                                        | (0x1fU 
                                                           & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                              >> 7U))))
                                                     : 
                                                    (((- (IData)(
                                                                 (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                  >> 0x1fU))) 
                                                      << 0xdU) 
                                                     | ((0x1000U 
                                                         & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                            >> 0x13U)) 
                                                        | ((0x800U 
                                                            & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                               << 4U)) 
                                                           | ((0x7e0U 
                                                               & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                  >> 0x14U)) 
                                                              | (0x1eU 
                                                                 & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                    >> 7U))))))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o))
                                                     ? 0U
                                                     : 
                                                    (((- (IData)(
                                                                 (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                  >> 0x1fU))) 
                                                      << 0xcU) 
                                                     | (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                        >> 0x14U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__imm_type_o))
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                  >> 0x1fU))) 
                                                      << 0x15U) 
                                                     | ((0x100000U 
                                                         & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                            >> 0xbU)) 
                                                        | ((0xff000U 
                                                            & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits) 
                                                           | ((0x800U 
                                                               & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                  >> 9U)) 
                                                              | (0x7feU 
                                                                 & (vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
                                                                    >> 0x14U))))))
                                                     : 
                                                    (0xfffff000U 
                                                     & vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits))));
    vlSelf->top__DOT__u_pipelineID__DOT__aluOperation_o 
        = (((IData)(vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o) 
            << 0x14U) | (((IData)(vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__blt) 
                          << 0x13U) | (((IData)(vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__beq) 
                                        << 0x12U) | vlSelf->top__DOT__u_pipelineID__DOT__u_decoder__DOT__alu_calculation)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xcfffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_29)) 
               << 0x1dU) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_28)) 
                            << 0x1cU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xffffcfffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_29)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_21)
                     : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13))) 
               << 0xdU) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                             ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_28)
                             : ((8U & vlSelf->top__DOT__rs2_d_o)
                                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_20)
                                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12))) 
                           << 0xcU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xffcfffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_21)) 
               << 0x15U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_20)) 
                            << 0x14U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xffffffcfU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_21)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_13)
                     : ((4U & vlSelf->top__DOT__rs2_d_o)
                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_09)
                         : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05)))) 
               << 5U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                           ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_20)
                           : ((8U & vlSelf->top__DOT__rs2_d_o)
                               ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_12)
                               : ((4U & vlSelf->top__DOT__rs2_d_o)
                                   ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_08)
                                   : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_04)))) 
                         << 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfcffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_25)) 
               << 0x19U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_24)) 
                            << 0x18U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfffffcffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_25)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_17)
                     : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09))) 
               << 9U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                           ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_24)
                           : ((8U & vlSelf->top__DOT__rs2_d_o)
                               ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_16)
                               : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_08))) 
                         << 8U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfffcffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_17)) 
               << 0x11U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_16)) 
                            << 0x10U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfffffffcU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((2U & (((0x10U & vlSelf->top__DOT__rs2_d_o)
                       ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_17)
                       : ((8U & vlSelf->top__DOT__rs2_d_o)
                           ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_09)
                           : ((4U & vlSelf->top__DOT__rs2_d_o)
                               ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_05)
                               : ((2U & vlSelf->top__DOT__rs2_d_o)
                                   ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03)
                                   : ((1U & vlSelf->top__DOT__rs2_d_o)
                                       ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                          >> 2U) : 
                                      (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in 
                                       >> 1U)))))) 
                     << 1U)) | (1U & ((0x10U & vlSelf->top__DOT__rs2_d_o)
                                       ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_16)
                                       : ((8U & vlSelf->top__DOT__rs2_d_o)
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
                                                    : vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_in))))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0x3fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_31)) 
               << 0x1fU) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_30)) 
                            << 0x1eU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xffff3fffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_31)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_23)
                     : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15))) 
               << 0xfU) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                             ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_30)
                             : ((8U & vlSelf->top__DOT__rs2_d_o)
                                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_22)
                                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14))) 
                           << 0xeU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xff3fffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_23)) 
               << 0x17U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_22)) 
                            << 0x16U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xffffff3fU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_23)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_15)
                     : ((4U & vlSelf->top__DOT__rs2_d_o)
                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_11)
                         : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07)))) 
               << 7U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                           ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_22)
                           : ((8U & vlSelf->top__DOT__rs2_d_o)
                               ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_14)
                               : ((4U & vlSelf->top__DOT__rs2_d_o)
                                   ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_10)
                                   : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06)))) 
                         << 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xf3ffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_27)) 
               << 0x1bU) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_26)) 
                            << 0x1aU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfffff3ffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_27)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_19)
                     : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11))) 
               << 0xbU) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                             ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_26)
                             : ((8U & vlSelf->top__DOT__rs2_d_o)
                                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_18)
                                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10))) 
                           << 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfff3ffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                 : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_19)) 
               << 0x13U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                              ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__msbFill)
                              : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_18)) 
                            << 0x12U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
        = ((0xfffffff3U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out) 
           | ((((0x10U & vlSelf->top__DOT__rs2_d_o)
                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_19)
                 : ((8U & vlSelf->top__DOT__rs2_d_o)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_11)
                     : ((4U & vlSelf->top__DOT__rs2_d_o)
                         ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_07)
                         : ((2U & vlSelf->top__DOT__rs2_d_o)
                             ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_05)
                             : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_03))))) 
               << 3U) | (((0x10U & vlSelf->top__DOT__rs2_d_o)
                           ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M4_18)
                           : ((8U & vlSelf->top__DOT__rs2_d_o)
                               ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M3_10)
                               : ((4U & vlSelf->top__DOT__rs2_d_o)
                                   ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M2_06)
                                   : ((2U & vlSelf->top__DOT__rs2_d_o)
                                       ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_04)
                                       : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__M1_02))))) 
                         << 2U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s30_1_0 
        = (1U ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_0_0)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct27_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_1 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co28_0_0__DOT__w3)) 
                 | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct27_0_0)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_2 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w3)) 
                 | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct26_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co27_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct26_0_0)
                  : (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                        >> 5U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct25_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co26_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct25_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                     >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_2 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w3)) 
                 & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                    >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 9U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_1__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_1)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 1U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_1__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_1)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 3U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 9U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w1 
        = (1U & ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                     >> 4U)) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w3)
                                 ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_0_0)
                                 : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                    >> 0xaU))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                     >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                     >> 9U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                     >> 9U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffffe7U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w3) 
               << 4U) | (8U & ((0xfffffff8U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder0) 
                               ^ (0xfffffff8U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder1 
                                                 << 2U))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_1 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co4_0_0__DOT__w3)) 
                 & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                    >> 2U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_1_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s5_0_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c6_0_0 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w3)) 
                 & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa6_1_0__DOT__axorb 
        = (1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                  >> 3U) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w3)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s7_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct6_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c7_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co7_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct6_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 1U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct7_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w1 
        = (1U & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                  >> 1U) ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co8_0_0__DOT__w3)
                             ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct7_0_0)
                             : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                                >> 2U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s9_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct8_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c9_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct8_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 3U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 4U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w1 
        = (IData)(((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                     >> 7U) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w3)) 
                   ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_0_0)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 8U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w1 
        = (1U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_0_0__DOT__w3)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_0_0)
                     : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                        >> 9U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 0xbU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 0xaU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s12_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 6U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s11_0_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c11_0_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_0_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_0_0)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder3 
                     >> 5U)));
    vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc = 0U;
    if (vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o) {
        vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc 
            = (vlSelf->top__DOT__u_pipelineID__DOT__pc_instr 
               + vlSelf->top__DOT__u_pipelineID__DOT__imm_o);
    }
    if (vlSelf->top__DOT__u_pipelineID__DOT__branchJALR_o) {
        if ((1U & (~ (IData)((0U != (IData)(vlSelf->top__DOT__src1_sel_d_i)))))) {
            vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc 
                = (0xfffffffeU & (vlSelf->top__DOT__u_pipelineID__DOT__rs1_data_o 
                                  + vlSelf->top__DOT__u_pipelineID__DOT__imm_o));
        }
    }
    if (vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o) {
        vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc 
            = (vlSelf->top__DOT__u_pipelineID__DOT__pc_instr 
               + vlSelf->top__DOT__u_pipelineID__DOT__imm_o);
    }
    vlSelf->top__DOT__u_pipelineID__DOT__taken = 0U;
    if (vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o) {
        vlSelf->top__DOT__u_pipelineID__DOT__taken = 1U;
    }
    if (vlSelf->top__DOT__u_pipelineID__DOT__branchJALR_o) {
        vlSelf->top__DOT__u_pipelineID__DOT__taken 
            = (1U & (~ (IData)((0U != (IData)(vlSelf->top__DOT__src1_sel_d_i)))));
    }
    if (vlSelf->top__DOT__u_pipelineID__DOT__branchBType_o) {
        vlSelf->top__DOT__u_pipelineID__DOT__taken 
            = (vlSelf->top__DOT__u_pipelineID__DOT__imm_o 
               >> 0x1fU);
    }
    vlSelf->top__DOT__is_d_d_o = (IData)((0U != (0x3c000U 
                                                 & vlSelf->top__DOT__u_pipelineID__DOT__aluOperation_o)));
    vlSelf->top__DOT__is_m_d_o = (IData)((0U != (0x3c00U 
                                                 & vlSelf->top__DOT__u_pipelineID__DOT__aluOperation_o)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft_ans 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT____Vcellinp__sft__leftOrRight)
            ? vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out
            : ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                << 0x1fU) | ((0x40000000U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                             << 0x1dU)) 
                             | ((0x20000000U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                << 0x1bU)) 
                                | ((0x10000000U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                   << 0x19U)) 
                                   | ((0x8000000U & 
                                       (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                        << 0x17U)) 
                                      | ((0x4000000U 
                                          & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                             << 0x15U)) 
                                         | ((0x2000000U 
                                             & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                << 0x13U)) 
                                            | ((0x1000000U 
                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                   << 0x11U)) 
                                               | ((0x800000U 
                                                   & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                      << 0xfU)) 
                                                  | ((0x400000U 
                                                      & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                         << 0xdU)) 
                                                     | ((0x200000U 
                                                         & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                            << 0xbU)) 
                                                        | ((0x100000U 
                                                            & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                               << 9U)) 
                                                           | ((0x80000U 
                                                               & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                  << 7U)) 
                                                              | ((0x40000U 
                                                                  & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                     << 5U)) 
                                                                 | ((0x20000U 
                                                                     & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                        << 3U)) 
                                                                    | ((0x10000U 
                                                                        & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                           << 1U)) 
                                                                       | ((0x8000U 
                                                                           & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                              >> 1U)) 
                                                                          | ((0x4000U 
                                                                              & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 3U)) 
                                                                             | ((0x2000U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft__DOT__shifter_d_out 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_1_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_0_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_0_0) 
           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_0_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_0_0) 
           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_0) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_0_1__DOT__w1)
                     ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                        >> 4U) : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6 
                                  >> 8U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_0_0) 
           | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_1_0 
        = (1U ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_0_0) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_0_0)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_0_0) 
                 ^ (((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                         >> 2U)) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_0_1__DOT__axorb)) 
                    | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                        >> 7U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                  >> 5U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w1)
                  ? (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 8U) : (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                  >> 4U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w3 
        = (1U & (((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                   >> 8U) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_0_0)) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_0_0) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb) 
                    | ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                        >> 8U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                  >> 6U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_0_0) 
                 ^ ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                     >> 7U) & (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                  >> 3U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_0) 
           & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_0_0) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_0_1__DOT__w3)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_0_1)
                     : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                        >> 2U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_0_0) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_0_1__DOT__w3)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_0_1)
                     : (~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                           >> 1U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffffdfU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_1_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_1)) 
              << 5U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fffff9fU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_1) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa5_1_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s5_0_0) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c4_0_0))) 
              << 6U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffffbfU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa6_1_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c5_0_0)) 
              << 6U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fffff7fU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c5_0_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa6_1_0__DOT__axorb)) 
               << 7U) | (0xffffff80U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                                         << 4U) & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co6_0_0__DOT__w3) 
                                                   << 7U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffffeffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c6_0_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s7_0_0)) 
              << 8U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffff7fU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c6_0_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s7_0_0)) 
              << 7U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa8_1_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c7_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_1_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w1)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c8_0_1)
                  : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 1U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c8_0_1) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s9_0_0)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c9_0_0) 
           ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_0_0__DOT__w3) 
              ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_0_0)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_0)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_1_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w1)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3)
                  : ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__neg) 
                     >> 7U)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_0_0) 
                 ^ ((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_0_1__DOT__w3)) 
                    & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_1_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w1)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_0_1)
                  : vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_0) 
           | (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_1_0__DOT__w3 
        = (1U ^ (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_1) 
                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_2)) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_0)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_0_1) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_0)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_0_0) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_0_1__DOT__w3)
                     ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_0_1)
                     : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                        >> 2U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_0) 
                 ^ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w1)
                     ? vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder6
                     : (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                        >> 4U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s11_0_0) 
                 ^ ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 3U) ^ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 1U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w1 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c11_0_0) 
                 ^ ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder4 
                     >> 3U) & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder5 
                               >> 1U))));
    vlSelf->top__DOT__taken_d_o = (1U & ((((~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay)) 
                                           | (IData)(vlSelf->top__DOT__ptnt_e_i)) 
                                          | (IData)(vlSelf->top__DOT__redirection_e_o)) 
                                         | ((~ (IData)(vlSelf->top__DOT__hu__DOT__flush)) 
                                            & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__taken))));
    vlSelf->top__DOT__fd_st_f_i = (((((~ ((IData)(vlSelf->top__DOT__u_pipelineID__DOT__fin) 
                                          | (IData)(vlSelf->top__DOT__hu__DOT__flush))) 
                                      & (((IData)(vlSelf->top__DOT__is_d_d_o) 
                                          | (IData)(vlSelf->top__DOT__is_m_d_o)) 
                                         | (IData)(vlSelf->top__DOT__hu__DOT__Linst_st_keep))) 
                                     | (IData)(vlSelf->top__DOT__hu__DOT__Icmiss_st_keep)) 
                                    | (IData)(vlSelf->top__DOT__hu__DOT__Dcmiss_st_keep)) 
                                   | (IData)(vlSelf->top__DOT__hu__DOT__Ldhaz_st));
    vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation 
        = (((((((((- (IData)((IData)((0U != (3U & vlSelf->top__DOT__alu_op_d_o))))) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__add_ans)) 
                 | ((- (IData)((IData)((0U != (0x30000U 
                                               & vlSelf->top__DOT__alu_op_d_o))))) 
                    & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__rem))) 
                | ((- (IData)((IData)((0U != (0xc000U 
                                              & vlSelf->top__DOT__alu_op_d_o))))) 
                   & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__div__DOT__dvd)) 
               | ((- (IData)((1U & (vlSelf->top__DOT__alu_op_d_o 
                                    >> 0xaU)))) & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans_temp))) 
              | ((- (IData)((IData)((0U != (0x3800U 
                                            & vlSelf->top__DOT__alu_op_d_o))))) 
                 & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__ans_temp))) 
             | ((- (IData)((IData)((0U != (0xe0U & vlSelf->top__DOT__alu_op_d_o))))) 
                & (((vlSelf->top__DOT__rs1_d_o ^ vlSelf->top__DOT__rs2_d_o) 
                    & (- (IData)((IData)((0U != (0xa0U 
                                                 & vlSelf->top__DOT__alu_op_d_o)))))) 
                   | ((vlSelf->top__DOT__rs1_d_o & vlSelf->top__DOT__rs2_d_o) 
                      & (- (IData)((IData)((0U != (0x60U 
                                                   & vlSelf->top__DOT__alu_op_d_o))))))))) 
            | ((- (IData)((IData)((0U != (0x1cU & vlSelf->top__DOT__alu_op_d_o))))) 
               & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__sft_ans)) 
           | (1U & ((- (IData)((IData)((0U != (0x300U 
                                               & vlSelf->top__DOT__alu_op_d_o))))) 
                    & (IData)((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__add_ans 
                               >> 0x20U)))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_1_0 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_0_0) 
            & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_1_0__DOT__axorb)) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_0) 
              & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_0_1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa29_1_0__DOT__axorb) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x5fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_1_0)) 
              << 0x1dU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x6fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c27_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s28_1_0)) 
              << 0x1cU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_2)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_0_2) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_0)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x6fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_1_0)) 
              << 0x1cU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x77ffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c26_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s27_1_0)) 
              << 0x1bU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w3 
        = (1U ^ (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_0_0) 
                  ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb)) 
                 ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_1)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w3 
        = (1U & (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_0_0) 
                  ^ (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                        >> 8U))) ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w1)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_1)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_1)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffffeffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa8_1_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_1)) 
              << 8U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffffdffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_1) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa8_1_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s8_0_0) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c7_0_0))) 
              << 9U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffffdffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w3) 
              << 9U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffffbffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co9_1_0__DOT__w3)) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s9_0_0)) 
              << 0xaU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w3 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s10_0_1) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s10_0_1)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c9_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_1)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_1)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_2)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_0_2) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_0)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_1)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s11_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w3 
        = (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s12_0_0) 
            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w3)) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w1)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s12_0_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c11_0_0));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt 
        = ((- (IData)((((((~ (IData)(vlSelf->top__DOT__fd_st_f_i)) 
                          & (IData)(vlSelf->resetn)) 
                         & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay)) 
                        & (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__resetn_delay2)) 
                       & (~ (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__taken_d_delay1))))) 
           & ((1U & (- (IData)((IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o)))) 
              | (2U & (- (IData)((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o))))))));
    if ((3U == (IData)(vlSelf->top__DOT__dmem_type_d_o))) {
        vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 0xfU;
        vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
            = vlSelf->top__DOT__rs2_reg_d_o;
    } else if ((1U == (IData)(vlSelf->top__DOT__dmem_type_d_o))) {
        if ((2U & vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation)) {
            if ((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation)) {
                vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 8U;
                vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                    = (vlSelf->top__DOT__rs2_reg_d_o 
                       << 0x18U);
            } else {
                vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 4U;
                vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                    = (0xff0000U & (vlSelf->top__DOT__rs2_reg_d_o 
                                    << 0x10U));
            }
        } else if ((1U & vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation)) {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 2U;
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                = (0xff00U & (vlSelf->top__DOT__rs2_reg_d_o 
                              << 8U));
        } else {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 1U;
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                = (0xffU & vlSelf->top__DOT__rs2_reg_d_o);
        }
    } else if ((2U == (IData)(vlSelf->top__DOT__dmem_type_d_o))) {
        if ((0U == (3U & vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation))) {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 3U;
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                = (0xffffU & vlSelf->top__DOT__rs2_reg_d_o);
        } else {
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 0xcU;
            vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data 
                = (vlSelf->top__DOT__rs2_reg_d_o << 0x10U);
        }
    } else {
        vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__byte_en = 0U;
        vlSelf->top__DOT__u_pipelineMEM_withloadstore__DOT__dmem_write_data = 0U;
    }
    vlSelf->top__DOT__bypass_e_o = ((((- (IData)((1U 
                                                  & (IData)(vlSelf->top__DOT__resultSrc_d_o)))) 
                                      & vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation) 
                                     | ((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelf->top__DOT__resultSrc_d_o) 
                                                       >> 1U)))) 
                                        & vlSelf->top__DOT__extended_imm_d_o)) 
                                    | ((- (IData)((1U 
                                                   & ((IData)(vlSelf->top__DOT__resultSrc_d_o) 
                                                      >> 3U)))) 
                                       & vlSelf->top__DOT__pc_plus4_d_o));
    vlSelf->top__DOT__redirection_pc_e_o = ((IData)(vlSelf->top__DOT__hu__DOT__Dcmiss_st_keep)
                                             ? vlSelf->top__DOT__u_pipelineEXE__DOT__redirection_pc_r
                                             : (((- (IData)(
                                                            ((~ (IData)(vlSelf->top__DOT__sbp_taken_d_o)) 
                                                             & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__alu_taken)))) 
                                                 & vlSelf->top__DOT__prediction_pc_d_o) 
                                                | (0xfffffffeU 
                                                   & ((- (IData)(
                                                                 ((~ (IData)(vlSelf->top__DOT__sbp_taken_d_o)) 
                                                                  & (IData)(vlSelf->top__DOT__jalr_d_o)))) 
                                                      & vlSelf->top__DOT__u_pipelineEXE__DOT__alu_calculation))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x3fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_1_0)) 
              << 0x1eU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x1fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_1_0) 
                ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s30_1_0)) 
               << 0x1eU) | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c28_1_0) 
                             ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s29_1_0)) 
                            << 0x1dU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_1_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co22_1_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct21_1_0)
                  : (~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa22_0_1__DOT__axorb))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co23_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct22_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c24_1_0 
        = (1U & ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co24_1_0__DOT__w3)
                  ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct23_1_0)
                  : (~ (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                        >> 8U))));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_1 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co25_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct24_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co19_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct18_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co21_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct20_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co20_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct19_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffff7ffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w3) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_1_0)) 
              << 0xbU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffffbffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co10_1_0__DOT__w3) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct9_1_0)) 
              << 0xaU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co15_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct14_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co16_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct15_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co17_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct16_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co18_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct17_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_0_2));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s14_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co14_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct13_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fffefffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w3)
                ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_1_0)
                : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c10_0_1)) 
              << 0xcU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffe7ffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w3) 
                ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_1_0)) 
               << 0xcU) | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co11_1_0__DOT__w3) 
                            ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct10_1_0)) 
                           << 0xbU)));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct11_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co12_0_1__DOT__w3));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w3) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_1_0 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__co13_1_0__DOT__w3)
            ? (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ct12_1_0)
            : (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_0));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__drain 
        = ((1U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt)) 
           | (2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt)));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt 
        = (7U & (((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt) 
                  + (2U & (- (IData)((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__fill))))) 
                 - ((2U & (- (IData)((2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt))))) 
                    | (1U & (- (IData)((1U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt))))))));
    vlSelf->top__DOT__redirection_d_o = (((((0x80000000U 
                                             & (- (IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay)) 
                                                              | (IData)(vlSelf->top__DOT__hu__DOT__flush)))))) 
                                            | ((- (IData)(
                                                          ((IData)(vlSelf->top__DOT__ptnt_e_i) 
                                                           & (~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o))))) 
                                               & vlSelf->top__DOT__u_pipelineID__DOT__pc_next)) 
                                           | ((- (IData)(
                                                         ((IData)(vlSelf->top__DOT__ptnt_e_i) 
                                                          & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__branchJAL_o)))) 
                                              & vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc)) 
                                          | ((- (IData)((IData)(vlSelf->top__DOT__redirection_e_o))) 
                                             & vlSelf->top__DOT__redirection_pc_e_o)) 
                                         | ((- (IData)(
                                                       (1U 
                                                        & (~ (IData)(vlSelf->top__DOT__redirection_e_o))))) 
                                            & vlSelf->top__DOT__u_pipelineID__DOT__redirection_pc));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7effffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_1_0)) 
              << 0x18U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7f7fffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c22_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s23_1_0)) 
              << 0x17U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7dffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_1_0)) 
              << 0x19U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7effffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c23_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s24_1_0)) 
              << 0x18U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7bffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c24_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_1_0)) 
              << 0x1aU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7dffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c24_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s25_1_0)) 
              << 0x19U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa26_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_1));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7f7fffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_1_0)) 
              << 0x17U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fbfffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c21_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s22_1_0)) 
              << 0x16U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fdfffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_1_0)) 
              << 0x15U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fefffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c19_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s20_1_0)) 
              << 0x14U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_1) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa16_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_1) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa17_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_2) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa18_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa19_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_1_0) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffeffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_1_0) 
               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_1_0)) 
              << 0x10U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fff7fffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c14_1_0) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s15_1_0)) 
              << 0xfU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_1) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_1_0));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa14_2_0__DOT__axorb 
        = ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_1) 
           ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_1_0));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__ceb 
        = (((IData)(vlSelf->top__DOT__taken_d_o) | 
            (3U >= (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt))) 
           & (IData)(vlSelf->resetn));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__cur_addr 
        = ((1U & ((~ (IData)(vlSelf->resetn)) | (IData)(vlSelf->top__DOT__taken_d_o)))
            ? vlSelf->top__DOT__redirection_d_o : vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__linear_addr);
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7bffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa26_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_1_0)) 
              << 0x1aU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x77ffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s26_1_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa26_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_0) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c25_1_1))) 
              << 0x1bU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fdfffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_1_0)) 
              << 0x15U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fbfffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_1_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa21_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s21_0_1) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c20_1_0))) 
              << 0x16U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffeffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa16_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_1_0)) 
              << 0x10U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffdffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_1_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa16_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s16_0_1) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c15_1_0))) 
              << 0x11U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffdffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa17_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_1_0)) 
              << 0x11U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ffbffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_1_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa17_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s17_0_2) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c16_1_0))) 
              << 0x12U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ffbffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa18_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_1)) 
              << 0x12U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7ff7ffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_1) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa18_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s18_1_0) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c17_1_0))) 
              << 0x13U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7ff7ffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa19_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_1)) 
              << 0x13U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fefffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_1) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa19_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s19_1_0) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c18_1_0))) 
              << 0x14U));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffdfffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_1_0)) 
              << 0xdU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fff9fffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_1_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa13_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s13_0_1) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c12_1_0))) 
              << 0xeU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
        = ((0x7fffbfffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1) 
           | (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa14_2_0__DOT__axorb) 
               ^ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s14_1_0)) 
              << 0xeU));
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2 
        = ((0x7fff7fffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2) 
           | ((((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s14_1_0) 
                & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa14_2_0__DOT__axorb)) 
               | ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_0_1) 
                  & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c13_1_0))) 
              << 0xfU));
    vlSelf->imem_addr = vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__cur_addr;
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans 
        = (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans1 
           + vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans2);
    vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__mul16ans 
        = ((0x80000000U & ((((((0x80000000U & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                               << 0x10U)) 
                               ^ ((~ ((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__sign) 
                                      >> 7U)) << 0x1fU)) 
                              ^ (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb) 
                                  << 0x1fU) | (0x80000000U 
                                               & ((vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder7 
                                                   << 0xfU) 
                                                  & (vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__adder8 
                                                     << 0x11U))))) 
                             ^ (((~ (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__fa30_0_0__DOT__axorb)) 
                                 & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_0_0)) 
                                << 0x1fU)) ^ (((IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__c29_1_0) 
                                               & (IData)(vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__s30_1_0)) 
                                              << 0x1fU)) 
                           ^ (0x80000000U & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans))) 
           | (0x7fffffffU & vlSelf->top__DOT__u_pipelineEXE__DOT__u_alu__DOT__mul__DOT__m16__DOT__ans));
}

void Vtop___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 32> &a);

VL_ATTR_COLD void Vtop___024root___initial__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__3\n"); );
    // Body
    Vtop___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(vlSelf->top__DOT__u_pipelineID__DOT__u_regfile__DOT__regfile_data);
}
