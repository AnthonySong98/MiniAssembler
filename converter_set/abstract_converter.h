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
    //定义虚函数
    virtual void asm2mc() = 0;

    const ASM_COL &getAsm_col() const;

    void setAsm_col(const ASM_COL &asm_col);

    const MC_COL &getMc_col() const;

    void setMc_col(const MC_COL &mc_col);

protected:
    ASM_COL asm_col;
    MC_COL mc_col;
};

#endif //ASSEMBLER_ABSTRACT_CONVERTER_H
