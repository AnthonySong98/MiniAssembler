//
// Created by Anthony on 2019/12/18.
//

#include <iostream>
#include <unordered_map>
#include <fstream>
#include "coe.h"

std::unordered_map<std::string,unsigned int >MEM_LENGTH_MAP {{"byte",1},{"half",2},{"word",4}};

COE::COE(const string &coe_string, int current_offset) : coe_string(coe_string), current_offset(current_offset) {}

COE::COE() {}

const string &COE::getCoe_string() const {
    return coe_string;
}

void COE::setCoe_string(const string &coe_string) {
    COE::coe_string = coe_string;
}

int COE::getCurrent_offset() const {
    return current_offset;
}

void COE::setCurrent_offset(int current_offset) {
    COE::current_offset = current_offset;
}

void COE::append_coe_helper(string str, string& all_string) {
    if(str.size() == 2 || str.size() == 4 || str.size() == 8){
        for (int i = str.size()-1; i >=0 ; i=i-2) {
            all_string.append(str.substr(i-1,2));
        }
    } else{
        cerr<<"fail to append to the coe_string!\n";
    }
}

void COE::append_coe_string(string str,string type) {

    if(type == "word" || type == "half" || type == "byte"){
        if(current_offset%MEM_LENGTH_MAP[type] == 0){
            append_coe_helper(str,coe_string);
            current_offset = current_offset + (unsigned int) str.size()/2;
        } else{
            int next_offset = MEM_LENGTH_MAP[type]-current_offset%MEM_LENGTH_MAP[type]+current_offset;
            coe_string.insert(current_offset*2,'0',2*(next_offset-current_offset));
            append_coe_helper(str,coe_string);
            current_offset = next_offset + (unsigned int) str.size()/2;
        }
    }
    else if(type == "ascii" || type == "asciiz"){
            append_coe_helper(str,coe_string);
            current_offset = current_offset + 1;
        }
}


//
void COE::output2file(string filepath) {
    std::ofstream output_file(filepath);
    if(output_file.is_open()){
        int i = 0;
        for ( i = 0; i < (int) coe_string.size()-8; i = i + 8) {
            output_file << coe_string.substr(i+6,2) << coe_string.substr(i+4,2)<< coe_string.substr(i+2,2)<< coe_string.substr(i,2)<<"\n";
        }
        if(i<=coe_string.size()-2){
            int j = coe_string.size()-2;
            int t = j;
            string lastline;
            while(j>=i){
                lastline.append(coe_string.substr(j,2));
                j = j - 2;
            }
            int cnt =  4 - ( t - j ) / 2;
            int l = 0;
            while (l < cnt){
                lastline = "00" + lastline ;
                l++;
            }
            output_file <<lastline << endl;
        }
    }
    else{
        cerr<<"fail to open coe output file!\n";
    };
}
