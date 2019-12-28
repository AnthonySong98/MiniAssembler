//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_ABSTRACT_CONVERTER_H
#define ASSEMBLER_ABSTRACT_CONVERTER_H

#include "../predefined_data_structures/asm_COL.h"
#include "../predefined_data_structures/machine_code_COL.h"

// abstruct class
class CONVERTER{
public:
    CONVERTER();

    CONVERTER(const ASM_COL &asm_col, const MC_COL &mc_col);

//定义虚函数
    virtual void asm2mc() = 0;

    const ASM_COL &getAsm_col() const;

    void setAsm_col(const ASM_COL &asm_col);

    const MC_COL &getMc_col() const;

    void setMc_col(const MC_COL &mc_col);

    /**
     * 设置二进制编码和对应的虚拟地址
     * @param machine_code
     * @param address
     */
    void setMc_col(const string &machine_code,unsigned int address);

protected:
    ASM_COL asm_col;
    MC_COL mc_col;
};

#endif //ASSEMBLER_ABSTRACT_CONVERTER_H
