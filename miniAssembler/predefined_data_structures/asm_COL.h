//
// Created by Anthony on 2019/12/16.
//

#ifndef ASSEMBLER_ASM_COL_H
#define ASSEMBLER_ASM_COL_H

#include <string>
#include "abstruct_ASM_COL.h"

using namespace std;
/**
 * The class is the data structure for each input line of original assembly code.
 */
class ASM_COL: public ABSTRUCT_ASM_COL{
public:
    ASM_COL(const string &original_line_of_code, int line_number);

    ASM_COL():is_label(false), is_second_operand(false), is_third_operand(false){};

    bool isIs_label() const;

    void setIs_label(bool is_label);

    const string &getLabel_name() const;

    void setLabel_name(const string &label_name);

    const string &getOp_name() const;

    void setOp_name(const string &op_name);

    const string &getFirst_operand() const;

    void setFirst_operand(const string &first_operand);

    bool isIs_second_operand() const;

    void setIs_second_operand(bool is_second_operand);

    const string &getSecond_operand() const;

    void setSecond_operand(const string &second_operand);

    bool isIs_third_operand() const;

    void setIs_third_operand(bool is_third_operand);

    const string &getThird_operand() const;

    void setThird_operand(const string &third_operand);

    unsigned int getAddress() const;

    void setAddress(unsigned int address);

    /**
     * Set Operand By Index
     * @param operand
     * @param num
     */
    void setOperandByIndex(const string& operand, int num);

    /**
     * Get Operand By Index
     * @param num
     * @return
     */
    const string & getOperandByIndex(int num);

private:

    /* 每行汇编代码的格式如下
     * [标号:] 指令助记符 第1操作数 [, 第2操作数 [, 第3操作数]] [# 注释]
     * 进行逐一拆分存储
     */
    bool is_label; // label exists or not 标号有无
    string label_name; // the actual content of label 标号内容

    string op_name;// 指令助记符

    string first_operand; //第一个操作数

    bool is_second_operand; //第二个操作数有无
    string second_operand;// 第二个操作数

    bool is_third_operand; //第三个操作数有无
    string third_operand;// 第三个操作数

    unsigned int address;

};

#endif //ASSEMBLER_ASM_COL_H
