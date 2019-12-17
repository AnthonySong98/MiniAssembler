//
// Created by Anthony on 2019/12/17.
//

#include <fstream>
#include <iostream>
#include "assembler.h"
using namespace std;

ASSEMBLER::ASSEMBLER(const string &input_file_path, const string &output_file_path) : input_file_path(input_file_path),
                                                                                      output_file_path(
                                                                                              output_file_path) {
}

//TODO: constructAsmColVector 将读入的汇编语言文件解析
void ASSEMBLER::constructAsmColVector() {
    std::ifstream input_file(input_file_path);
    if (input_file.is_open()) {
        std::string line_of_code;
        while (getline(input_file, line_of_code)) {
            //first change to lower case
            string_util.upperCase2LowerCase(line_of_code);

            //delete comment
            string_util.deleteComment(line_of_code);

            string type;
            if(string_util.isPseudoInst(line_of_code,type)){
                cout<<type<<endl;
            }
        }
        input_file.close();
    }
    else{
        cerr << "Error while opening the file " << input_file_path <<endl;
    }
}

// TODO: first pass
void ASSEMBLER::firstPass() {

}

//TODO: second pass
void ASSEMBLER::secondPass() {

}

//TODO: generate machine code
void ASSEMBLER::generateMachineCode() {

}