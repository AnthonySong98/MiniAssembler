//
// Created by Anthony on 2019/12/17.
//

#include <fstream>
#include <iostream>
#include "assembler.h"
using namespace std;

const string DATA_SEG_DEF_PSEUDO_INST_TYPE = "DATA_SEG_DEF_PSEUDO_INST";
const string CODE_SEG_DEF_PSEUDO_INST_TYPE = "CODE_SEG_DEF_PSEUDO_INST";

ASSEMBLER::ASSEMBLER(const string &input_file_path, const string &output_file_path) : input_file_path(input_file_path),
                                                                                      output_file_path(
                                                                                              output_file_path) {
}

//TODO: constructAsmColVector 将读入的汇编语言文件解析
void ASSEMBLER::constructAsmColVector() {
    std::ifstream input_file(input_file_path);
    if (input_file.is_open()) {
        std::string line_of_code;
        int data_seg_flag = 1;
        int code_seg_flag = 1;
        while (getline(input_file, line_of_code)) {

            //first change to lower case
            string_util.upperCase2LowerCase(line_of_code);

            //delete comment
            string_util.deleteComment(line_of_code);

            if(string_util.isEmptyLine(line_of_code)){ continue;}
            // check扫描到哪个段了
            if(data_seg_flag == 1 || code_seg_flag == 1){
                string type = "";
                if(string_util.isPseudoInst(line_of_code,type)){
                    if(type == DATA_SEG_DEF_PSEUDO_INST_TYPE){
                        data_seg_flag = 0;
                        data_seg_start_address = string_util.getSegStartAddress(line_of_code);
                        continue;
                    }
                    if(type == CODE_SEG_DEF_PSEUDO_INST_TYPE){
                        code_seg_flag = 0;
                        code_Seg_start_address = string_util.getSegStartAddress(line_of_code);
                        continue;
                    }
                }
            }

            // 正在扫描到数据段
            if(data_seg_flag == 0 && code_seg_flag == 1){
                string variableName, variableType;
                vector<string> initValueList;
                string_util.parseDataPseudoInst(line_of_code,variableName,variableType,initValueList);
                if(!variableName.empty()){
                    DATA_DEF_PSEUDO_INST_COL data_def_pseudo_inst_col;
                    data_def_pseudo_inst_col.setVariable_name(variableName);
                    if(!variableType.empty()){
                        data_def_pseudo_inst_col.appendVariableType(variableType);
                        data_def_pseudo_inst_col.appendVariableInitValue(initValueList);
                    }
                    data_def_pseudoinst_col_vector.push_back(data_def_pseudo_inst_col);
                }
                else{
                    if(data_def_pseudoinst_col_vector.size() != 0){
                        // if(data_def_pseudoinst_col_vector[data_def_pseudoinst_col_vector.size()-1].getVariable_type().empty())
                        {
                            data_def_pseudoinst_col_vector[data_def_pseudoinst_col_vector.size()-1].appendVariableType(variableType);
                            data_def_pseudoinst_col_vector[data_def_pseudoinst_col_vector.size()-1].appendVariableInitValue(initValueList);
                        }

                    } else{
                        cerr<<"missing variable name!\n";
                    }
                }
            }

            // 正在扫描到代码段
            else if(data_seg_flag == 0 && code_seg_flag == 0){
                string labelName,instName;
                vector<string> paraList;
                string_util.parseCodeInst(line_of_code,labelName,instName,paraList);
                if(!labelName.empty()){
                    ASM_COL asm_col;
                    asm_col.setLabel_name(labelName);
                    asm_col.setIs_label(true);
                    if(!instName.empty()){
                        asm_col.setOp_name(instName);
                        if(paraList.size()>0){
                            asm_col.setFirst_operand(paraList[0]);
                            if(paraList.size()>1){
                                asm_col.setSecond_operand(paraList[1]);
                                asm_col.setIs_second_operand(true);
                                if(paraList.size()>2){
                                    asm_col.setThird_operand(paraList[2]);
                                    asm_col.setIs_third_operand(true);
                                }
                            }
                        }
                    }
                    asm_col_vector.push_back(asm_col);
                }
                else{
                    if(asm_col_vector.size() != 0){
                        if(asm_col_vector[asm_col_vector.size()-1].getOp_name().empty()){
                            asm_col_vector[asm_col_vector.size()-1].setOp_name(labelName);
                            asm_col_vector[asm_col_vector.size()-1].setIs_label(true);
                            if(!instName.empty()){
                                asm_col_vector[asm_col_vector.size()-1].setOp_name(instName);
                                if(paraList.size()>0){
                                    asm_col_vector[asm_col_vector.size()-1].setFirst_operand(paraList[0]);
                                    if(paraList.size()>1){
                                        asm_col_vector[asm_col_vector.size()-1].setSecond_operand(paraList[1]);
                                        asm_col_vector[asm_col_vector.size()-1].setIs_second_operand(true);
                                        if(paraList.size()>2){
                                            asm_col_vector[asm_col_vector.size()-1].setThird_operand(paraList[2]);
                                            asm_col_vector[asm_col_vector.size()-1].setIs_third_operand(true);
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            ASM_COL asm_col;
                            asm_col.setIs_label(false);
                            if(!instName.empty()){
                                asm_col.setOp_name(instName);
                                if(paraList.size()>0){
                                    asm_col.setFirst_operand(paraList[0]);
                                    if(paraList.size()>1){
                                        asm_col.setSecond_operand(paraList[1]);
                                        asm_col.setIs_second_operand(true);
                                        if(paraList.size()>2){
                                            asm_col.setThird_operand(paraList[2]);
                                            asm_col.setIs_third_operand(true);
                                        }
                                    }
                                }
                            }
                            asm_col_vector.push_back(asm_col);
                        }
                    }
                    else{
                        cerr<<"missing first label name!\n";
                    }
                }
            }
            else{
                cerr<<"Wrong order of data seg and code seg!\n";
            }

        }
        input_file.close();
    }
    else{
        cerr << "Error while opening the file " << input_file_path <<endl;
    }
}

// TODO: first pass
void ASSEMBLER::firstPass() {

}

//TODO: second pass
void ASSEMBLER::secondPass() {

}

//TODO: generate machine code
void ASSEMBLER::generateMachineCode() {

}