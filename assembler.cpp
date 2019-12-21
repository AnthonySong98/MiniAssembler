//
// Created by Anthony on 2019/12/17.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include "assembler.h"
#include "./converter_set/inst_converter.h"

using namespace std;

const string DATA_SEG_DEF_PSEUDO_INST_TYPE = "DATA_SEG_DEF_PSEUDO_INST";
const string CODE_SEG_DEF_PSEUDO_INST_TYPE = "CODE_SEG_DEF_PSEUDO_INST";
/**
 * MEM_LENGTH存储变量类型对应的字节长度
 * 暂不支持float和double
 * ascii和asciiz单独处理，故不加在这里
 */
std::unordered_map<std::string,unsigned int >MEM_LENGTH {{"byte",1},{"half",2},{"word",4}};

ASSEMBLER::ASSEMBLER(const string &input_file_path, const string &output_file_path) : input_file_path(input_file_path),
                                                                                      output_file_path(
                                                                                              output_file_path) {
}

void ASSEMBLER::setInstNameAndOperandList(ASM_COL &asm_col, string &instName, vector<string> &paraList) {
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
}



unsigned int ASSEMBLER::dataValue2BinaryCode(string _initValue, string _type, COE& data_coe) {
    int initValueDec;
    unsigned int incre;
    if(_initValue[0] != '\"' && _initValue[_initValue.size()-1] != '\"'){
        std::string result;
        initValueDec = std::stoi(_initValue,nullptr,0);
        if(_type == "word" || _type == "half" || _type == "byte"){
            std::stringstream stream;
            stream << setw(MEM_LENGTH[_type]*2) << setfill('0') << std::hex << initValueDec ;
            result = stream.str();
        }
        incre = MEM_LENGTH[_type];
        //cout<<result<<endl;
        data_coe.append_coe_string(result,_type);
    }
    else if((_type == "ascii" || _type == "asciiz") && _initValue[0] == '\"' && _initValue[_initValue.size()-1] == '\"'){
        for (int i = 1; i < _initValue.size()-1; ++i) {
            if(_initValue[i] != '\\'){
                std::stringstream stream;
                stream << setw(2) << setfill('0') << std::hex << (int)(_initValue[i]);
                data_coe.append_coe_string(stream.str(),_type);
            }
        }
        incre = _initValue.size() - 2;
    }
    return incre;

}


void ASSEMBLER::replaceLabelOrVariable(ASM_COL &asm_col, string &str, int num) {
    string current = "";
    if(literal_symbol_table.containsSymbol(str)){
        current = asm_col.getOperandByIndex(num);
        current.replace(0,(str).size(),to_string(literal_symbol_table.getAddress(str)));
        asm_col.setOperandByIndex(current,num);
    }
    current = "";
    if(label_symbol_table.containsSymbol(str)){
        current = asm_col.getOperandByIndex(num);
        current.replace(0,(str).size(),to_string(label_symbol_table.getAddress(str)));
        asm_col.setOperandByIndex(current,num);
    }
}

void ASSEMBLER::inst2BinaryCode(ASM_COL asm_col, unsigned int &current_address, MC_COL& mc_col) {
    INST_CONVERTER inst_converter;
    inst_converter.setAsm_col(asm_col);
    inst_converter.asm2mc();
    mc_col = inst_converter.getMc_col();
    mc_col.setAddress(current_address);
    current_address = current_address + 4;

}

//constructAsmColVector 将读入的汇编语言文件解析
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
                    setInstNameAndOperandList(asm_col,instName,paraList);
                    asm_col_vector.push_back(asm_col);
                }
                else{
                    if(asm_col_vector.size() != 0){
                        if(asm_col_vector[asm_col_vector.size()-1].getOp_name().empty()){
                            asm_col_vector[asm_col_vector.size()-1].setOp_name(labelName);
                            asm_col_vector[asm_col_vector.size()-1].setIs_label(true);
                            setInstNameAndOperandList(asm_col_vector[asm_col_vector.size()-1],instName,paraList);
                        }
                        else{
                            ASM_COL asm_col;
                            asm_col.setIs_label(false);
                            setInstNameAndOperandList(asm_col,instName,paraList);
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

// first pass, construct symbol table
void ASSEMBLER::firstPass() {
//construct the literal_symbol_table(data segment)
    unsigned int current_address = data_seg_start_address;
    for (int i = 0; i < data_def_pseudoinst_col_vector.size(); ++i) {
        literal_symbol_table.addEntryToSymbolTable(data_def_pseudoinst_col_vector[i].getVariable_name(),current_address);
        //generate coe file for data
        for (int j = 0; j < data_def_pseudoinst_col_vector[i].getVariable_type().size(); ++j) {
            string current_type = data_def_pseudoinst_col_vector[i].getVariable_type()[j];
            for (int k = 0; k < data_def_pseudoinst_col_vector[i].getVariable_init_value()[j].size(); ++k) {
                current_address = current_address + dataValue2BinaryCode(data_def_pseudoinst_col_vector[i].getVariable_init_value()[j][k],current_type,data_coe);
            }
        }
    }
// construct the label_symbol_table
    for (int l = 0; l < asm_col_vector.size(); ++l) {
        if(asm_col_vector[l].isIs_label()){
            // TODO: 当存在宏指令的时候，需要修正加以判断
            label_symbol_table.addEntryToSymbolTable(asm_col_vector[l].getLabel_name(),code_Seg_start_address+4*l);
        }
    }
}

// second pass
void ASSEMBLER::secondPass() {
    for (int i = 0; i < asm_col_vector.size(); ++i) {
        if(asm_col_vector[i].isIs_label()){
            asm_col_vector[i].setLabel_name(to_string(label_symbol_table.getAddress(asm_col_vector[i].getLabel_name())));
        }
        string label_name = "";
        if(string_util.isLabelOrVariable(asm_col_vector[i].getFirst_operand(),label_name)){
            replaceLabelOrVariable(asm_col_vector[i],label_name,1);
        }
        if(asm_col_vector[i].isIs_second_operand() && string_util.isLabelOrVariable(asm_col_vector[i].getSecond_operand(),label_name)){
            replaceLabelOrVariable(asm_col_vector[i],label_name,2);
        }
        if(asm_col_vector[i].isIs_third_operand() && string_util.isLabelOrVariable(asm_col_vector[i].getThird_operand(),label_name)){
            replaceLabelOrVariable(asm_col_vector[i],label_name,3);
        }
    }
}

//TODO: generate machine code
void ASSEMBLER::generateMachineCode() {
    //generate coe for data seg
    data_coe.output2file(output_file_path+"data.coe");

    //generate coe for code seg
    unsigned int current_address = code_Seg_start_address;
    std::ofstream output_file(output_file_path+"code.coe");
    if(output_file.is_open()){
        for (int i = 0; i < asm_col_vector.size(); ++i) {
            MC_COL mc_col_current;
            inst2BinaryCode(asm_col_vector[i],current_address,mc_col_current);
            output_file<<string_util.binString2HexString(mc_col_current.getMachine_code())<<" : "<<mc_col_current.getAddress()<<endl;
        }
    }


}