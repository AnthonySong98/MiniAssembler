//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_ABSTRUCT_ASM_COL_H
#define ASSEMBLER_ABSTRUCT_ASM_COL_H

#include <string>
using namespace std;

class ABSTRUCT_ASM_COL{
public:
    const string &getOriginal_line_of_code() const;

    void setOriginal_line_of_code(const string &original_line_of_code);

    int getLine_number() const;

    void setLine_number(int line_number);

protected:
    string original_line_of_code; // line of assembly code in original form.
    int line_number; // line number

};
#endif //ASSEMBLER_ABSTRUCT_ASM_COL_H
