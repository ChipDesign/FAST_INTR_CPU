// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

void Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();

VL_INLINE_OPT void Vtop___024root___combo__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__4\n"); );
    // Body
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid 
        = ((((IData)(vlSelf->resetn) & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay)) 
            & (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__resetn_delay2)) 
           & (~ (IData)(vlSelf->top__DOT__flush_jal_d_o)));
    vlSelf->top__DOT__instruction_f_o = ((0x13U & (- (IData)(
                                                             (1U 
                                                              & (~ (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid)))))) 
                                         | ((- (IData)((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__instru_valid))) 
                                            & (((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir1) 
                                                << 0x10U) 
                                               | (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__ir0))));
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
    vlSelf->top__DOT__u_pipelineID__DOT__pc_next = 
        (((- (IData)((IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o))) 
          & ((IData)(2U) + vlSelf->top__DOT__u_pipelineID__DOT__pc_instr)) 
         | ((- (IData)((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o))))) 
            & ((IData)(4U) + vlSelf->top__DOT__u_pipelineID__DOT__pc_instr)));
    vlSelf->top__DOT__u_pipelineID__DOT__instru_32bits 
        = ((IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o)
            ? vlSelf->top__DOT__u_pipelineID__DOT__instr_o
            : vlSelf->top__DOT__instruction_f_o);
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
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__cur_addr 
        = ((1U & ((~ (IData)(vlSelf->resetn)) | (IData)(vlSelf->top__DOT__taken_d_o)))
            ? vlSelf->top__DOT__redirection_d_o : vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__linear_addr);
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt 
        = ((- (IData)((((((~ (IData)(vlSelf->top__DOT__fd_st_f_i)) 
                          & (IData)(vlSelf->resetn)) 
                         & (IData)(vlSelf->top__DOT__u_pipelineID__DOT__resetn_delay)) 
                        & (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__resetn_delay2)) 
                       & (~ (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__taken_d_delay1))))) 
           & ((1U & (- (IData)((IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o)))) 
              | (2U & (- (IData)((1U & (~ (IData)(vlSelf->top__DOT__u_pipelineID__DOT__is_compressed_o))))))));
    vlSelf->imem_addr = vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__cur_addr;
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__drain 
        = ((1U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt)) 
           | (2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt)));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt 
        = (7U & (((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__pf_fifo_cnt) 
                  + (2U & (- (IData)((IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__fill))))) 
                 - ((2U & (- (IData)((2U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt))))) 
                    | (1U & (- (IData)((1U == (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__drain_cnt))))))));
    vlSelf->top__DOT__u_pipeline_withFIFO__DOT__ceb 
        = (((IData)(vlSelf->top__DOT__taken_d_o) | 
            (3U >= (IData)(vlSelf->top__DOT__u_pipeline_withFIFO__DOT__u_fifo5x16__DOT__next_fifo_cnt))) 
           & (IData)(vlSelf->resetn));
}
