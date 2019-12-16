//
// Created by Anthony on 2019/12/16.
//

#include "machine_code_COL.h"

MC_COL::MC_COL(const string &machine_code, unsigned int address) : machine_code(machine_code), address(address) {

}

const string &MC_COL::getMachine_code() const {
    return machine_code;
}

void MC_COL::setMachine_code(const string &machine_code) {
    MC_COL::machine_code = machine_code;
}

unsigned int MC_COL::getAddress() const {
    return address;
}

void MC_COL::setAddress(unsigned int address) {
    MC_COL::address = address;
}
