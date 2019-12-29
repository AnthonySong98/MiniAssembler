//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_ASSEMBLER_H
#define ASSEMBLER_ASSEMBLER_H

#include <string>
#include <fstream>
#include <vector>

#include "./predefined_data_structures/asm_COL.h"
#include "./predefined_data_structures/data_def_pseudo_inst_COL.h"
#include "./predefined_data_structures/machine_code_COL.h"
#include "./predefined_data_structures/symbol_table.h"

#include "converter_set/inst_converter.h"
#include "util/string_util/string_util.h"
#include "predefined_data_structures/coe.h"

using namespace std;

class ASSEMBLER{
public:
    /**
     *构造函数，指定输入输出文件的路径
     * @param input_file_path
     * @param output_file_path
     */
    ASSEMBLER(const string &input_file_path, const string &output_file_path);

    /**
     * 解析输入文件，将asm_col_vector和data_def_pseudoinst_col_vector填充
     */
    void constructAsmColVector();

    /**
     * 第一遍扫描
     */
    void firstPass();

    /**
     * 第二遍扫描
     */
    void secondPass();

    /**
     * 生成机器码
     */
    void generateMachineCode();

private:
    /**
     * 构造一个asm_col
     * @param asm_col
     * @param instName
     * @param paraList
     */
    void setInstNameAndOperandList(ASM_COL& asm_col,string& instName, vector<string>& paraList);

    /**
     * 将data segement里的初始值变成二进制形式写入coe文件
     * 返回本次插入之后地址的增量
     * @param _initValue
     * @param _type
     * @param _incre
     * @return
     */
    unsigned int dataValue2BinaryCode(string _initValue, string _type, COE& data_code);

     /**
      *
      * 重定向函数
      * str 为待替换的参数
      * @param asm_col
      * @param str
      * @param num
      */
    void replaceLabelOrVariable(ASM_COL& asm_col, string& str ,int num);

    /**
     * 将重定向后的代码段翻译成二进制机器码
     * @param asm_col
     * @param current_address
     * @return
     */
    void inst2BinaryCode(ASM_COL asm_col,unsigned int& current_address, MC_COL& mc_col);

private:
    string input_file_path; // 汇编文件的路径
    string output_file_path; // coe文件的路径

    vector<ASM_COL> asm_col_vector; // 输入的汇编文件的解析结果数组（针对汇编指令,代码段）
    vector<DATA_DEF_PSEUDO_INST_COL> data_def_pseudoinst_col_vector; // 输入的汇编文件的解析结果数组（针对数据定义伪指令,数据段）

    COE data_coe;

    vector<MC_COL> text_coe_vector; // 输出的存储指令的coe文件的数组
    vector<MC_COL> data_coe_vector; // 输出的存储数据的coe文件

    unsigned int data_seg_start_address;
    unsigned int code_Seg_start_address;

    SYMBOL_TABLE literal_symbol_table; // literal symbol table
    SYMBOL_TABLE label_symbol_table; // label symbol table

    INST_CONVERTER inst_converter;

    //helper Utils
    STRING_UTIL string_util;
};
#endif //ASSEMBLER_ASSEMBLER_H
