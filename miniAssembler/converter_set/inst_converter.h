//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_ADD_INST_CONVERTER_H
#define ASSEMBLER_ADD_INST_CONVERTER_H

#include "abstract_converter.h"
#include "../util/inst_set.h"
#include "../util/string_util/string_util.h"

class INST_CONVERTER: public CONVERTER{
public:
    INST_CONVERTER() {}

    //TODO: reconstruct the code
    //只需关注机器码的生成，地址不在这里关心！！
    void asm2mc(){
        STRING_UTIL string_util;
        string op = "";
        string rs = "";
        string rt = "";
        string rd = "";
        string immediate = "";
        string shamt = "";
        string func = "";
        string offset = "";
        string address = "";
        string res = "";
        /**
         * J-type Inst
         */
        if(asm_col.getOp_name() == ADD_INST || asm_col.getOp_name() == ADDU_INST || asm_col.getOp_name() == SUB_INST || asm_col.getOp_name() == SUBU_INST || asm_col.getOp_name() == AND_INST){
            op = "000000";
            rd = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rs = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()){
                rt = string_util.extractRegName(asm_col.getThird_operand());
            }
            shamt = "00000";
            if(!asm_col.getOp_name().compare(ADD_INST)){func = "100000";}
            if(!asm_col.getOp_name().compare(ADDU_INST)){func = "100001";}
            if(!asm_col.getOp_name().compare(SUB_INST)){func = "100010";}
            if(!asm_col.getOp_name().compare(SUBU_INST)){func = "100011";}
            if(!asm_col.getOp_name().compare(AND_INST)){func = "100100";}
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == MULT_INST || asm_col.getOp_name() == MULTU_INST || asm_col.getOp_name() == DIV_INST || asm_col.getOp_name() == DIVU_INST){
            op = "000000";
            rs = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rt = string_util.extractRegName(asm_col.getSecond_operand());
            }
            rd = "00000";
            shamt = "00000";
            if(!asm_col.getOp_name().compare(MULT_INST)){func = "011000";}
            if(!asm_col.getOp_name().compare(MULTU_INST)){func = "011001";}
            if(!asm_col.getOp_name().compare(DIV_INST)){func = "011010";}
            if(!asm_col.getOp_name().compare(DIVU_INST)){func = "011011";}
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == MFHI_INST || asm_col.getOp_name() == MFLO_INST || asm_col.getOp_name() == MTHI_INST || asm_col.getOp_name() == MTLO_INST){
            op = "000000";
            if(asm_col.getOp_name() == MFHI_INST || asm_col.getOp_name() == MFLO_INST){
                rd = string_util.extractRegName(asm_col.getFirst_operand());
                shamt = "00000";
                if(!asm_col.getOp_name().compare(MFHI_INST)){func = "010000";}
                if(!asm_col.getOp_name().compare(MFLO_INST)){func = "010010";}
                res = op + "0000000000" + rd + shamt + func;
            }
            if(asm_col.getOp_name() == MTHI_INST || asm_col.getOp_name() == MTLO_INST){
                rs = string_util.extractRegName(asm_col.getFirst_operand());
                if(!asm_col.getOp_name().compare(MTHI_INST)){func = "010001";}
                if(!asm_col.getOp_name().compare(MTLO_INST)){func = "010011";}
                res = op + rs + "000000000000000" + func;
            }
            mc_col.setMachine_code(res);
        }

        // sel 字段赋值问题 均设置为0
        if(asm_col.getOp_name() == MFC0_INST || asm_col.getOp_name() == MTC0_INST){
            op = "010000";
            if(!asm_col.getOp_name().compare(MFC0_INST)){rs = "00000";}
            if(!asm_col.getOp_name().compare(MTC0_INST)){rs = "00100";}
            rt = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rd = string_util.extractRegName(asm_col.getSecond_operand());
            }
            shamt = "00000";
            func = "000000";
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == OR_INST || asm_col.getOp_name() == XOR_INST || asm_col.getOp_name() == NOR_INST){
            op = "000000";
            rd = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rs = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()) {
                rt = string_util.extractRegName(asm_col.getThird_operand());
            }
            shamt = "00000";
            if(asm_col.getOp_name() == (OR_INST)){func = "100101";}
            if(asm_col.getOp_name() == (XOR_INST)){func = "100110";}
            if(asm_col.getOp_name() == (NOR_INST)){func = "100111";}
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == SLT_INST || asm_col.getOp_name() == SLTU_INST ){
            op = "000000";
            rd = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rs = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()) {
                rt = string_util.extractRegName(asm_col.getThird_operand());
            }
            shamt = "00000";
            if(!asm_col.getOp_name().compare(SLT_INST)){func = "101010";}
            if(!asm_col.getOp_name().compare(SLTU_INST)){func = "101011";}
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == SLL_INST || asm_col.getOp_name() == SRL_INST || asm_col.getOp_name() == SRA_INST){
            op = "000000";
            rs = "00000";
            rd = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rt = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()) {
                shamt = string_util.extractShamt(asm_col.getThird_operand());
            }
            if(!asm_col.getOp_name().compare(SLL_INST)){func = "000000";}
            if(!asm_col.getOp_name().compare(SRL_INST)){func = "000010";}
            if(!asm_col.getOp_name().compare(SRA_INST)){func = "000011";}
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == SLLV_INST || asm_col.getOp_name() == SRLV_INST || asm_col.getOp_name() == SRAV_INST){
            op = "000000";
            rd = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rt = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()) {
                rs = string_util.extractRegName(asm_col.getThird_operand());
            }
            shamt = "00000";
            if(!asm_col.getOp_name().compare(SLLV_INST)){func = "000100";}
            if(!asm_col.getOp_name().compare(SRLV_INST)){func = "000110";}
            if(!asm_col.getOp_name().compare(SRAV_INST)){func = "000111";}
            res = op + rs + rt + rd + shamt + func;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == JR_INST || asm_col.getOp_name() == JALR_INST){
            op = "00000";
            if(!asm_col.getOp_name().compare(JR_INST)){
                rs = string_util.extractRegName(asm_col.getFirst_operand());
                res = op + rs + "000000000000000001000";
            }
            if(!asm_col.getOp_name().compare(JR_INST)) {
                rd = string_util.extractRegName(asm_col.getFirst_operand());
                if(asm_col.isIs_second_operand()) {
                    rs = string_util.extractRegName(asm_col.getSecond_operand());
                }
                res = op + rs + "00000" + rd + "00000" + "001001";
            }
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == BREAK_INST){
            res = "00000000000000000000000000001101";
            mc_col.setMachine_code(res);
        }
        if(asm_col.getOp_name() == SYSCALL_INST){
            mc_col.setMachine_code("00000000000000000000000000001100");
        }
        if(asm_col.getOp_name() == ERET_INST){
            mc_col.setMachine_code("01000010000000000000000000011000");
        }

        /**
         * I-type Inst
         */

        if(asm_col.getOp_name() == ADDI_INST || asm_col.getOp_name() == ADDIU_INST){
            if(!asm_col.getOp_name().compare(ADDI_INST)){op="001000";}
            if(!asm_col.getOp_name().compare(ADDIU_INST)){op="001001";}
            rt = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()){
                rs = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()){
                immediate = string_util.extractImmediate(asm_col.getThird_operand());
            }
            res = op + rs + rt + immediate;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == ANDI_INST || asm_col.getOp_name() == ORI_INST || asm_col.getOp_name() == XORI_INST){
            if(!asm_col.getOp_name().compare(ANDI_INST)){op="001100";}
            if(!asm_col.getOp_name().compare(ORI_INST)){op="001101";}
            if(!asm_col.getOp_name().compare(XORI_INST)){op="001110";}
            rt = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()){
                rs = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()){
                immediate = string_util.extractImmediate(asm_col.getThird_operand(),0);
            }
            res = op + rs + rt + immediate;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == LUI_INST){
            op = "001111";
            rs = "00000";
            rt = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()){
                immediate = string_util.extractImmediate(asm_col.getSecond_operand());
            }
            res = op + rs + rt + immediate;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == LB_INST || asm_col.getOp_name() == LBU_INST || asm_col.getOp_name() == LH_INST || asm_col.getOp_name() == LHU_INST
           || asm_col.getOp_name() == SB_INST || asm_col.getOp_name() == SH_INST || asm_col.getOp_name() == LW_INST || asm_col.getOp_name() == SW_INST)
        {
            if(!asm_col.getOp_name().compare(LB_INST)){op="100000";}
            if(!asm_col.getOp_name().compare(LBU_INST)){op="100100";}
            if(!asm_col.getOp_name().compare(LH_INST)){op="100001";}
            if(!asm_col.getOp_name().compare(LHU_INST)){op="100101";}
            if(!asm_col.getOp_name().compare(SB_INST)){op="101000";}
            if(!asm_col.getOp_name().compare(SH_INST)){op="101001";}
            if(!asm_col.getOp_name().compare(LW_INST)){op="100011";}
            if(!asm_col.getOp_name().compare(SW_INST)){op="101011";}
            rt = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rs = string_util.extractRegName(asm_col.getSecond_operand());
                offset = string_util.extractImmediate(asm_col.getSecond_operand());
            }
            res = op + rs + rt + offset;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == BEQ_INST || asm_col.getOp_name() == BNE_INST ){
            rs = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rt = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()){
                offset = string_util.extractImmediate(asm_col.getThird_operand());
            }
            if(!asm_col.getOp_name().compare(BEQ_INST)){op="000100";}
            if(!asm_col.getOp_name().compare(BNE_INST)){op="000101";}
            res = op + rs + rt + offset;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == BGEZ_INST || asm_col.getOp_name() == BGTZ_INST
           || asm_col.getOp_name() == BLEZ_INST || asm_col.getOp_name() == BLTZ_INST
           || asm_col.getOp_name() == BGEZAL_INST || asm_col.getOp_name() == BLTZAL_INST)
        {
            rs = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                offset = string_util.extractImmediate(asm_col.getSecond_operand());
            }
            if(!asm_col.getOp_name().compare(BGEZ_INST)){op="000001";rt="00001";}
            if(!asm_col.getOp_name().compare(BGTZ_INST)){op="000111";rt="00000";}
            if(!asm_col.getOp_name().compare(BLEZ_INST)){op="000110";rt="00000";}
            if(!asm_col.getOp_name().compare(BLTZ_INST)){op="000001";rt="00000";}
            if(!asm_col.getOp_name().compare(BGEZAL_INST)){op="000001";rt="10001";}
            if(!asm_col.getOp_name().compare(BLTZAL_INST)){op="000001";rt="10000";}
            res = op + rs + rt + offset;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == SLTI_INST || asm_col.getOp_name() == SLTIU_INST){
            if(!asm_col.getOp_name().compare(SLTI_INST)){op="001010";}
            if(!asm_col.getOp_name().compare(SLTIU_INST)){op="001011";}
            rt = string_util.extractRegName(asm_col.getFirst_operand());
            if(asm_col.isIs_second_operand()) {
                rs = string_util.extractRegName(asm_col.getSecond_operand());
            }
            if(asm_col.isIs_third_operand()){
                immediate = string_util.extractImmediate(asm_col.getThird_operand());
            }
            res = op + rs + rt +immediate;
            mc_col.setMachine_code(res);
        }

        if(asm_col.getOp_name() == J_INST || asm_col.getOp_name() == JAL_INST){
            if(!asm_col.getOp_name().compare(J_INST)){op="000010";}
            if(!asm_col.getOp_name().compare(JAL_INST)){op="000011";}
            address = string_util.extractAddress(asm_col.getFirst_operand());
            res = op + address;
            mc_col.setMachine_code(res);
        }
    }
};

#endif //ASSEMBLER_ADD_INST_CONVERTER_H
