#include <iostream>
#include <string>

#include "assembler.h"

using namespace std;

int main(int argc, char* argv[]) {
//    if(argc<2){
//        cout<<"usage: ./assembler <assemble code file name>\n";
//        return 0;
//    }

    string input_path = "../input_asm_file/bios.s";
    string output_path = "../";
    ASSEMBLER assembler(input_path,output_path);
    assembler.constructAsmColVector();
    assembler.firstPass();
    assembler.secondPass();
    assembler.generateMachineCode();
    cout<<"coe file generated!\n";
    return 0;
}