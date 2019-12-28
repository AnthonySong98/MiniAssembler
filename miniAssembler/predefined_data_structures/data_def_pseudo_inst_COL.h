//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_DATA_DEF_PSEUDO_INST_COL_H
#define ASSEMBLER_DATA_DEF_PSEUDO_INST_COL_H

#include <vector>
#include "string"
#include "abstruct_ASM_COL.h"

using namespace std;
/**
 * 数据定义伪指令的数据结构
 */
class DATA_DEF_PSEUDO_INST_COL: public ABSTRUCT_ASM_COL{
public:
    DATA_DEF_PSEUDO_INST_COL();

    const string &getVariable_name() const;

    void setVariable_name(const string &variable_name);

    const vector<string> &getVariable_type() const;

    const vector<vector<string>> &getVariable_init_value() const;

    void appendVariableType(string newType);

    void appendVariableInitValue(vector<string> newInitValue);

private:
    string variable_name; // 变量名
    vector<string> variable_type; // 变量类型
    vector<vector<string> > variable_init_value; //变量初值
};

#endif //ASSEMBLER_DATA_DEF_PSEUDO_INST_COL_H
