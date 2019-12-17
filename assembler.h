//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_ASSEMBLER_H
#define ASSEMBLER_ASSEMBLER_H

#include <string>
#include <fstream>
#include <vector>

#include "./predefined_data_structures/asm_COL.h"
#include "./predefined_data_structures/machine_code_COL.h"
#include "./predefined_data_structures/symbol_table.h"

#include "./converter_set/add_inst_converter.h"

using namespace std;

class ASSEMBLER{
public:
    ASSEMBLER(const string &input_file_path, const string &output_file_path);

    void constructAsmColVector();

    void firstPass();

    void secondPass();

    void generateMachineCode();
public:

private:
    string input_file_path; // 汇编文件的路径
    string output_file_path; // coe文件的路径

    vector<ASM_COL> asm_col_vector; // 输入的汇编文件的解析结果数组
    vector<MC_COL> text_coe_vector; // 输出的存储指令的coe文件的数组
    vector<MC_COL> data_coe_vector; // 输出的存储数据的coe文件

    SYMBOL_TABLE literal_symbol_table; // literal symbol table
    SYMBOL_TABLE label_symbol_table; // label symbol table

    //below are instruction converters
    ADD_INS_CONVERTER add_ins_converter;
};
#endif //ASSEMBLER_ASSEMBLER_H
