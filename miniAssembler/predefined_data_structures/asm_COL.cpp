//
// Created by Anthony on 2019/12/16.
//

#include "asm_COL.h"


const string &ASM_COL::getLabel_name() const {
    return label_name;
}

void ASM_COL::setLabel_name(const string &label_name) {
    ASM_COL::label_name = label_name;
}

const string &ASM_COL::getOp_name() const {
    return op_name;
}

void ASM_COL::setOp_name(const string &op_name) {
    ASM_COL::op_name = op_name;
}

const string &ASM_COL::getFirst_operand() const {
    return first_operand;
}

void ASM_COL::setFirst_operand(const string &first_operand) {
    ASM_COL::first_operand = first_operand;
}

bool ASM_COL::isIs_second_operand() const {
    return is_second_operand;
}

void ASM_COL::setIs_second_operand(bool is_second_operand) {
    ASM_COL::is_second_operand = is_second_operand;
}

const string &ASM_COL::getSecond_operand() const {
    return second_operand;
}

void ASM_COL::setSecond_operand(const string &second_operand) {
    ASM_COL::second_operand = second_operand;
}

bool ASM_COL::isIs_third_operand() const {
    return is_third_operand;
}

void ASM_COL::setIs_third_operand(bool is_third_operand) {
    ASM_COL::is_third_operand = is_third_operand;
}

const string &ASM_COL::getThird_operand() const {
    return third_operand;
}

void ASM_COL::setThird_operand(const string &third_operand) {
    ASM_COL::third_operand = third_operand;
}

bool ASM_COL::isIs_label() const {
    return is_label;
}

void ASM_COL::setIs_label(bool is_label) {
    ASM_COL::is_label = is_label;
}


void ASM_COL::setOperandByIndex(const string &operand, int num) {
    switch (num){
        case 1:{
            setFirst_operand(operand);
            break;
        }
        case 2:{
            setSecond_operand(operand);
            break;
        }
        case 3:{
            setThird_operand(operand);
            break;
        }
    }
}

const string& ASM_COL::getOperandByIndex(int num) {
    switch (num){
        case 1:{
            return getFirst_operand();
        }
        case 2:{
            return getSecond_operand();
        }
        case 3:{
            return getThird_operand();
        }
    }
}

unsigned int ASM_COL::getAddress() const {
    return address;
}

void ASM_COL::setAddress(unsigned int address) {
    ASM_COL::address = address;
}
