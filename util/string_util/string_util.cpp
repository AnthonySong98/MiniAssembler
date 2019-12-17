//
// Created by Anthony on 2019/12/17.
//

#include "string_util.h"
#include <regex>
#include <iostream>

using namespace std;

const string DATA_SEG_DEF_PSEUDO_INST_TYPE = "DATA_SEG_DEF_PSEUDO_INST";

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
    regex r("\\s*.data\\s+");
    smatch m;
    if(regex_search(_COL,m,r)){
        _type = DATA_SEG_DEF_PSEUDO_INST_TYPE;
        return true;
    }

}