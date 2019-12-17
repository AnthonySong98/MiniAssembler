//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_DATA_DEF_PSEUDO_INST_COL_H
#define ASSEMBLER_DATA_DEF_PSEUDO_INST_COL_H

#include <vector>
#include "string"
#include "abstruct_ASM_COL.h"

using namespace std;
/*
 * 数据定义伪指令的数据结构
 */
class DATA_DEF_PSEUDO_INST_COL: public ABSTRUCT_ASM_COL{
public:
    DATA_DEF_PSEUDO_INST_COL();

    const string &getVariable_name() const;

    void setVariable_name(const string &variable_name);

    const string &getVariable_type() const;

    void setVariable_type(const string &variable_type);

    const vector<string> &getVariable_init_value() const;

    void setVariable_init_value(const vector<string> &variable_init_value);

    const string& getVariableInitValueByIndex(const int index) const ;

    void setVariableInitValueByIndex(const int index,string &initValue);

    void appendVariableInitValue(string &initValue);

private:
    string variable_name; // 变量名
    string variable_type; // 变量类型
    vector<string> variable_init_value; //变量初值
};

#endif //ASSEMBLER_DATA_DEF_PSEUDO_INST_COL_H
