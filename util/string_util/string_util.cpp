//
// Created by Anthony on 2019/12/17.
//

#include "string_util.h"
#include "../inst_set.h"
#include <regex>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <stdlib.h>

using namespace std;

const string DATA_SEG_DEF_PSEUDO_INST_TYPE = "DATA_SEG_DEF_PSEUDO_INST";
const string CODE_SEG_DEF_PSEUDO_INST_TYPE = "CODE_SEG_DEF_PSEUDO_INST";


bool STRING_UTIL::isEmptyLine(string &_COL) {
    regex r("(\\s)*");
    smatch m;
    if(regex_search(_COL,m,r)&&m[0].str().size() == _COL.size()){
        return true;
    }
    return false;
}

string STRING_UTIL::trim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
//    if(s[0]=='\"'&&s[s.size()-1]=='\"'){
//        s = s.substr(1,s.size()-2);
//    }
    return s;
}

void STRING_UTIL::split(string s, string delimiter, vector<string> &res) {
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        trim(token);
        //check ":"
        if(token.find(":") != std::string::npos){
            for (int i = 0; i < atoi(token.substr(token.find(":")+1,token.size()-1-token.find(":")).c_str()); ++i) {
                string string1 = token.substr(0,token.find(":"));
                res.push_back(trim(string1));
            }
        }
        else{
            res.push_back(token);
        }
        s.erase(0, pos + delimiter.length());
    }
    trim(s);
    if(s.find(":") != std::string::npos){
        for (int i = 0; i < atoi(s.substr(s.find(":")+1,s.size()-1-s.find(":")).c_str()); ++i) {
            res.push_back(s.substr(0,s.find(":")));
        }
    }
    else{
        res.push_back(s);
    }
}

void STRING_UTIL::upperCase2LowerCase(string &_COL) {
    //find where comment starts
    int endpos = _COL.size()-1;
    regex r("#(.)*");
    smatch m;
    if(regex_search(_COL,m,r)){
        endpos = m.position(0)-1;
    }

    int flag = 1;
    for (int i = 0; i <= endpos; ++i) {
        char ch = _COL[i];
        if(ch == '\"'){
            flag = 1 - flag;
        }
        if(flag==1&&ch>='A'&&ch<='Z'){
            _COL[i] = (char)tolower(ch);
        }
    }
}

bool STRING_UTIL::extractComment(string _COL, string &_comment) {
    regex r("#(.)*");
    smatch m;
    if(regex_search(_COL,m,r)){
        _comment = m[0];
        return true;
    } else{
        _comment = "";
        return false;
    }
}

void STRING_UTIL::deleteComment(string& _COL) {
    regex r("#(.)*");
    smatch m;
    if(regex_search(_COL,m,r)){
        _COL = _COL.substr(0,m.position(0));
    }
}

bool STRING_UTIL::isPseudoInst(string _COL,string &_type) {
    regex r1("\\s*.data\\s*");
    smatch m1;
    if(regex_search(_COL,m1,r1)){
        _type = DATA_SEG_DEF_PSEUDO_INST_TYPE;
        return true;
    }

    regex r2("\\s*.text\\s*");
    smatch m2;
    if(regex_search(_COL,m2,r2)){
        _type = CODE_SEG_DEF_PSEUDO_INST_TYPE;
        return true;
    }

    return false;
}

unsigned int STRING_UTIL::getSegStartAddress(string _COL) {
    regex r("0x[0-9a-fA-F]+");
    smatch m;
    if(regex_search(_COL,m,r)){
        return stoi(m[0].str().substr(2,m[0].str().size()-2),0,16);
    }
    else{
        regex r1("[0-9]+");
        smatch m1;
        if(regex_search(_COL,m1,r1)){
            return stoi(m1[0].str(),0,10);
        } else{
            return 0;
        }
    }
}

void STRING_UTIL::parseDataPseudoInst(string _COL, string &variable_name, string &variable_type,
                                      vector<string> &init_value_list) {
    regex r1("[a-zA-Z][a-zA-Z0-9]*:");
    smatch m1;
    // 如果有变量名
    if(regex_search(_COL,m1,r1)){
        variable_name = m1[0].str().substr(0,m1[0].str().size()-1);
    } else{
        variable_name = "";
    }

    regex r2("(\\.byte)|(\\.half)|(\\.word)|(\\.float)|(\\.double)|(\\.asciiz)|(\\.ascii)");
    smatch m2;
    //如果有变量类型
    if(regex_search(_COL,m2,r2)){
        variable_type = m2[0].str().substr(1,m2[0].str().size()-1);
        // 进一步check 有没有初始化的list
        regex r3("((\\.byte)|(\\.half)|(\\.word)|(\\.float)|(\\.double)|(\\.ascii)|(\\.asciiz))(\\s)+");
        smatch m3;
        if(regex_search(_COL,m3,r3)){
            string init_value_list_str = _COL.substr(m3.position(0)+m3[0].str().size(),_COL.size()-m3.position(0)-m3[0].str().size());
            // check ":"
            string de = ",";
            split(init_value_list_str,de,init_value_list);
        } else{
            cerr<<"no init value list found!\n";
        }
    } else{
        variable_type = "";
    }
}

bool STRING_UTIL::containsDenfinedInst(string _COL, string &inst_name) {
    inst_name = "";
    int i;
    for (i = 0; i < INST_SET.size(); ++i) {
        if(_COL.find(INST_SET[i]) != std::string::npos && _COL[_COL.find(INST_SET[i])+INST_SET[i].size()]==' '
                &&(_COL.find(INST_SET[i]) == 0 || (_COL.find(INST_SET[i]) > 0 && _COL[_COL.find(INST_SET[i])-1] == ' '))){
            inst_name = INST_SET[i];
            break;
        }
    }
    if(i == INST_SET.size()) return false;
    else return true;
}

void STRING_UTIL::parseCodeInst(string _COL, string &label_name, string &inst_name, vector<string> &para_list) {
    regex r1("[a-zA-Z][a-zA-Z0-9]*:");
    smatch m1;
    // 如果有变量名
    if(regex_search(_COL,m1,r1)){
        label_name = m1[0].str().substr(0,m1[0].str().size()-1);
    } else{
        label_name = "";
    }

    // check inst keyword
    if(containsDenfinedInst(_COL,inst_name)){
        string para_list_str = _COL.substr(_COL.find(inst_name)+inst_name.size(),_COL.size()-_COL.find(inst_name)-inst_name.size());
        string de = ",";
        split(para_list_str,de,para_list);
    }
}

bool STRING_UTIL::isLabelOrVariable(string para, string& label) {
    regex r1("[a-zA-z][a-zA-Z0-9]*");
    label = "";
    smatch m1;
    if(regex_search(para,m1,r1)){
        if(m1[0].str()[0] == para[0]){
            label = m1[0];
            return true;
        }
    } else{
        return false;
    }
}

string STRING_UTIL::extractRegName(string para, int num) {
    regex r("\\$[a-zA-z][a-zA-Z0-9]*");
    smatch m;
    if(regex_search(para,m,r)){
        string RegName = m[0].str();
        std::bitset<5> binary_str(RegMap.find(RegName).operator->()->second);
        return binary_str.to_string();
    }
}

string STRING_UTIL::getExtended(string para, int type, int num) {
    if(type == 1){
        regex r("[-]?[0-9]+");
        smatch m;
        if(regex_search(para,m,r)){
            string immediate = m[0].str();
            std::bitset<16> binary_str(strtol(immediate.c_str(), NULL,10));
            return binary_str.to_string();
        }
    }
    else if (type == 0){
        regex r("[0-9]+");
        smatch m;
        if(regex_search(para,m,r)){
            string immediate = m[0].str();
            std::bitset<16> binary_str(strtol(immediate.c_str(), NULL,10));
            return binary_str.to_string();
        }
    }
    else{
        cerr<<"ERROR raised by getExtended!\n";
    }
}

//默认为26位伪地址
string STRING_UTIL::extractAddress(string para) {
    regex r("[0-9]+");
    smatch m;
    if(regex_search(para,m,r)){
        string immediate = m[0].str();
        std::bitset<28> binary_str(strtol(immediate.c_str(), NULL,10));
        return binary_str.to_string().substr(0,26);
    }
}

//需要考虑负数
string STRING_UTIL::extractImmediate(string para, int num, int type) {
    return getExtended(para,type,16);
}


string STRING_UTIL::binString2HexString(const string &bin_string) {
    string out;
    for(uint i = 0; i < bin_string.size(); i += 4){
        int8_t n = 0;
        for(uint j = i; j < i + 4; ++j){
            n <<= 1;
            if(bin_string[j] == '1')
                n |= 1;
        }

        if(n<=9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }

    return out;
}

string STRING_UTIL::extractShamt(string para, int num) {
    regex r("[0-9]+");
    smatch m;
    if(regex_search(para,m,r)){
        string shamt = m[0].str();
        std::bitset<5> binary_str(strtol(shamt.c_str(), NULL,10));
        return binary_str.to_string();
    }
}