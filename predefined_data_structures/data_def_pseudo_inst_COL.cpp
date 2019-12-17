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

const vector<string> &DATA_DEF_PSEUDO_INST_COL::getVariable_type() const {
    return variable_type;
}

const vector<vector<string>> &DATA_DEF_PSEUDO_INST_COL::getVariable_init_value() const {
    return variable_init_value;
}

void DATA_DEF_PSEUDO_INST_COL::appendVariableType(string newType) {
    variable_type.push_back(newType);
}

void DATA_DEF_PSEUDO_INST_COL::appendVariableInitValue(vector<string> newInitValue) {
    variable_init_value.push_back(newInitValue);
}
