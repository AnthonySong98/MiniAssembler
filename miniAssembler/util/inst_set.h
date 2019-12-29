//
// Created by Anthony on 2019/12/18.
//

#ifndef ASSEMBLER_INST_SET_H
#define ASSEMBLER_INST_SET_H

#include <map>
#include <string>
#include <vector>
using namespace std;

const map<string,int> RegMap = {
        {"$zero",0},// 常数0，该寄存器永远只返回0
        {"$at",1},// 用做汇编器的暂时变量。通常汇编的一些合成指令会使用该寄存器，比如异常处理程序中保存和恢复某些寄存器的值。
        {"$v0",2},// 用来存放一个子程序(函数)的非浮点运算的结果或返回值
        {"$v1",3},
        {"$a0",4},// 存放子程序(函数)调用时的前4个非浮点参数。
        {"$a1",5},
        {"$a2",6},
        {"$a3",7},
        {"$t0",8},// 暂时变量，子程序(函数)使用时不保存这些寄存器的值，因此调用后它们的值会被破坏。程序员和编译器都要特别注意这一点。
        {"$t1",9},
        {"$t2",10},
        {"$t3",11},
        {"$t4",12},
        {"$t5",13},
        {"$t6",14},
        {"$t7",15},
        {"$s0",16},// 8个子程序用寄存器变量
        {"$s1",17},
        {"$s2",18},
        {"$s3",19},
        {"$s4",20},
        {"$s5",21},
        {"$s6",22},
        {"$s7",23},
        {"$t8",24},// 暂时变量，子程序(函数)使用时不保存这些寄存器的值，因此调用后它们的值会被破坏。程序员和编译器都要特别注意这一点。
        {"$t9",25},
        {"$k0",26},// 为中断/异常处理保留。由操作系统的异常或中断处理程序使用，不恢复原来的值。因此程序员和编译器不要用它们做其他用途。
        {"$k1",27},
        {"$gp",28},// 全局指针 暂不支持
        {"$sp",29},// 堆栈指针，对它的调整必须显式的通过指令来实现，硬件指令不支持堆栈指针的调整。一般在子程序调用和返回的时候调整sp。
        {"$s8",30},// 第9个子程序用寄存器变量，子程序用它做堆栈帧指针。
        {"$fp",30},
        {"$ra",31},// 存放调用子程序(函数)时的返回地址
};

const string ADD_INST = "add";
const string ADDU_INST = "addu";
const string SUB_INST = "sub";
const string SUBU_INST = "subu";
const string AND_INST = "and";
const string MULT_INST = "mult";
const string MULTU_INST = "multu";
const string DIV_INST = "div";
const string DIVU_INST = "divu";
const string MFHI_INST = "mfhi";
const string MFLO_INST = "mflo";
const string MTHI_INST = "mthi";
const string MTLO_INST = "mtlo";
const string MFC0_INST = "mfc0";
const string MTC0_INST = "mtc0";
const string OR_INST = "or";
const string XOR_INST = "xor";
const string NOR_INST = "nor";
const string SLT_INST = "slt";
const string SLTU_INST = "sltu";
const string SLL_INST = "sll";
const string SRL_INST = "srl";
const string SRA_INST = "sra";
const string SLLV_INST = "sllv";
const string SRLV_INST = "srlv";
const string SRAV_INST = "srav";
const string JR_INST = "jr";
const string JALR_INST = "jalr";
const string BREAK_INST = "break";
const string SYSCALL_INST = "syscall";
const string ERET_INST = "eret";
const string ADDI_INST = "addi";
const string ADDIU_INST = "addiu";
const string ANDI_INST = "andi";
const string ORI_INST = "ori";
const string XORI_INST = "xori";
const string LUI_INST = "lui";
const string LB_INST = "lb";
const string LBU_INST = "lbu";
const string LH_INST = "lh";
const string LHU_INST = "lhu";
const string SB_INST = "sb";
const string SH_INST = "sh";
const string LW_INST = "lw";
const string SW_INST = "sw";
const string BEQ_INST = "beq";
const string BNE_INST = "bne";
const string BGEZ_INST = "bgez";
const string BGTZ_INST = "bgtz";
const string BLEZ_INST = "blez";
const string BLTZ_INST = "bltz";
const string BGEZAL_INST = "bgezal";
const string BLTZAL_INST = "bltzal";
const string SLTI_INST = "slti";
const string SLTIU_INST = "sltiu";
const string J_INST = "j";
const string JAL_INST = "jal";
const string NOP_INST = "nop";



const std::vector<std::string> INST_SET{
    ADD_INST,
    ADDU_INST,
    SUB_INST,
    SUBU_INST,
    AND_INST,
    MULT_INST,
    MULTU_INST,
    DIV_INST,
    DIVU_INST,
    MFHI_INST,
    MFLO_INST,
    MTHI_INST,
    MTLO_INST,
    MFC0_INST,
    MTC0_INST,
    OR_INST,
    XOR_INST,
    NOR_INST,
    SLT_INST,
    SLTU_INST,
    SLL_INST,
    SRL_INST,
    SRA_INST,
    SLLV_INST,
    SRLV_INST,
    SRAV_INST,
    JR_INST,
    JALR_INST,
    BREAK_INST,
    SYSCALL_INST,
    ERET_INST,
    ADDI_INST,
    ADDIU_INST,
    ANDI_INST,
    ORI_INST,
    XORI_INST,
    LUI_INST,
    LB_INST,
    LBU_INST,
    LH_INST,
    LHU_INST,
    SB_INST,
    SH_INST,
    LW_INST,
    SW_INST,
    BEQ_INST,
    BNE_INST,
    BGEZ_INST,
    BGTZ_INST,
    BLEZ_INST,
    BLTZ_INST,
    BGEZAL_INST,
    BLTZAL_INST,
    SLTI_INST,
    SLTIU_INST,
    J_INST,
    JAL_INST,
    NOP_INST
    };
#endif //ASSEMBLER_INST_SET_H
