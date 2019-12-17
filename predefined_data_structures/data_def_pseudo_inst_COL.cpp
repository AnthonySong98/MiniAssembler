//
// Created by Anthony on 2019/12/17.
//

#include <iostream>
#include "data_def_pseudo_inst_COL.h"

DATA_DEF_PSEUDO_INST_COL::DATA_DEF_PSEUDO_INST_COL() {

}

const string &DATA_DEF_PSEUDO_INST_COL::getVariable_name() const {
    return variable_name;
}

void DATA_DEF_PSEUDO_INST_COL::setVariable_name(const string &variable_name) {
    DATA_DEF_PSEUDO_INST_COL::variable_name = variable_name;
}

const string &DATA_DEF_PSEUDO_INST_COL::getVariable_type() const {
    return variable_type;
}

void DATA_DEF_PSEUDO_INST_COL::setVariable_type(const string &variable_type) {
    DATA_DEF_PSEUDO_INST_COL::variable_type = variable_type;
}

const vector<string> &DATA_DEF_PSEUDO_INST_COL::getVariable_init_value() const {
    return variable_init_value;
}

void DATA_DEF_PSEUDO_INST_COL::setVariable_init_value(const vector<string> &variable_init_value) {
    DATA_DEF_PSEUDO_INST_COL::variable_init_value = variable_init_value;
}

const string& DATA_DEF_PSEUDO_INST_COL::getVariableInitValueByIndex(const int index) const {
    if(index<variable_init_value.size()&&index>=0){
        return variable_init_value[index];
    } else{
        cerr<<"Index out of the boundary!\n";
    }
}

void DATA_DEF_PSEUDO_INST_COL::setVariableInitValueByIndex(const int index, string &initValue) {
    if(index<variable_init_value.size()&&index>=0){
        variable_init_value[index] = initValue;
    } else{
        cerr<<"Index out of the boundary!\n";
    }
}

void DATA_DEF_PSEUDO_INST_COL::appendVariableInitValue(string &initValue) {
    variable_init_value.push_back(initValue);
}