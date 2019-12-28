//
// Created by Anthony on 2019/12/17.
//

#include "abstract_converter.h"

CONVERTER::CONVERTER() {}

CONVERTER::CONVERTER(const ASM_COL &asm_col, const MC_COL &mc_col) : asm_col(asm_col), mc_col(mc_col) {}


const ASM_COL &CONVERTER::getAsm_col() const {
    return asm_col;
}

void CONVERTER::setAsm_col(const ASM_COL &asm_col) {
    CONVERTER::asm_col = asm_col;
}

const MC_COL &CONVERTER::getMc_col() const {
    return mc_col;
}

void CONVERTER::setMc_col(const MC_COL &mc_col) {
    CONVERTER::mc_col = mc_col;
}

void CONVERTER::setMc_col(const string &machine_code, unsigned int address) {
    CONVERTER::mc_col.setMachine_code(machine_code);
    CONVERTER::mc_col.setAddress(address);
}