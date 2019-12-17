//
// Created by Anthony on 2019/12/16.
//

#ifndef ASSEMBLER_MACHINE_CODE_COL_H
#define ASSEMBLER_MACHINE_CODE_COL_H

#include <string>
using namespace std;
/**
 * MC_COL defines the data structure for the final generate machine code, together with its vitual address.
 */
class MC_COL{
public:
    MC_COL(const string &machine_code, unsigned int address);

    const string &getMachine_code() const;

    void setMachine_code(const string &machine_code);

    unsigned int getAddress() const;

    void setAddress(unsigned int address);

private:
    string machine_code;// 存储01序列代码，定长为32位
    unsigned int address; // 存储地址(虚拟地址)
};

#endif //ASSEMBLER_MACHINE_CODE_COL_H
