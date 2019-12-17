//
// Created by Anthony on 2019/12/17.
//

#include "abstruct_ASM_COL.h"

const string &ABSTRUCT_ASM_COL::getOriginal_line_of_code() const {
    return original_line_of_code;
}

void ABSTRUCT_ASM_COL::setOriginal_line_of_code(const string &original_line_of_code) {
    ABSTRUCT_ASM_COL::original_line_of_code = original_line_of_code;
}

int ABSTRUCT_ASM_COL::getLine_number() const {
    return line_number;
}

void ABSTRUCT_ASM_COL::setLine_number(int line_number) {
    ABSTRUCT_ASM_COL::line_number = line_number;
}
