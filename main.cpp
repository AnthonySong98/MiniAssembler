#include <iostream>
#include <string>

#include "assembler.h"

using namespace std;

int main() {
    string input_path = "../input_asm_file/test_input.s";
    string output_path = "../output_coe_file/";
    ASSEMBLER assembler(input_path,output_path);
    assembler.constructAsmColVector();
    assembler.firstPass();
    assembler.secondPass();
    assembler.generateMachineCode();
    return 0;
}