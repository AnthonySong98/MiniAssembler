//
// Created by Anthony on 2019/12/16.
//

#include "asm_COL.h"
// TODO: constructor for ASM_COL class
ASM_COL::ASM_COL(const string &original_line_of_code, int line_number) : original_line_of_code(original_line_of_code),
                                                                         line_number(line_number) {

}

const string &ASM_COL::getOriginal_line_of_code() const {
    return original_line_of_code;
}

void ASM_COL::setOriginal_line_of_code(const string &original_line_of_code) {
    ASM_COL::original_line_of_code = original_line_of_code;
}

int ASM_COL::getLine_number() const {
    return line_number;
}

void ASM_COL::setLine_number(int line_number) {
    ASM_COL::line_number = line_number;
}

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

