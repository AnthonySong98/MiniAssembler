//
// Created by Anthony on 2019/12/18.
//

#ifndef ASSEMBLER_INST_SET_H
#define ASSEMBLER_INST_SET_H

#include <unordered_map>

#define ADD_INST "add";
#define ADDU_INST "addu";
#define SUB_INST "sub";
#define SUBU_INST "subu";
#define AND_INST "and";
#define MULT_INST "mult";
#define MULTU_INST "multu";
#define DIV_INST "div";
#define DIVU_INST "divu";
#define MFHI_INST "mfhi";
#define MFLO_INST "mflo";
#define MTHI_INST "mthi";
#define MTLO_INST "mtlo";
#define MFC0_INST "mfc0";
#define MTC0_INST "mtc0";
#define OR_INST "or";
#define XOR_INST "xor";
#define NOR_INST "nor";
#define SLT_INST "slt";
#define SLTU_INST "sltu";
#define SLL_INST "sll";
#define SRL_INST "srl";
#define SRA_INST "sra";
#define SLLV_INST "sllv";
#define SRLV_INST "srlv";
#define SRAV_INST "srav";
#define JR_INST "jr";
#define JALR_INST "jalr";
#define BREAK_INST "break";
#define SYSCALL_INST "syscall";
#define ERET_INST "eret";
#define ADDI_INST "addi";
#define ADDIU_INST "addiu";
#define ANDI_INST "andi";
#define ORI_INST "ori";
#define XORI_INST "xori";
#define LUI_INST "lui";
#define LB_INST "lb";
#define LBU_INST "lbu";
#define LH_INST "lh";
#define LHU_INST "lhu";
#define SB_INST "sb";
#define SH_INST "sh";
#define LW_INST "lw";
#define SW_INST "sw";
#define BEQ_INST "beq";
#define BNE_INST "bne";
#define BGEZ_INST "bgez";
#define BGTZ_INST "bgtz";
#define BLEZ_INST "blez";
#define BLTZ_INST "bltz";
#define BGEZAL_INST "bgezal";
#define BLTZAL_INST "bltzal";
#define SLTI_INST "slti";
#define SLTIU_INST "sltiu";
#define J_INST "j";
#define JAL_INST "jal";

std::vector<std::string> INST_SET{"add","addi","lw","sw","j"};
#endif //ASSEMBLER_INST_SET_H
