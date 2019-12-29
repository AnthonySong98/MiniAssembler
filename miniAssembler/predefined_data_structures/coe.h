//
// Created by Anthony on 2019/12/18.
//

#ifndef ASSEMBLER_COE_H
#define ASSEMBLER_COE_H

#include <string>

using namespace std;
class COE{
public:
    COE(const string &coe_string, int current_offset);

    COE();

    const string &getCoe_string() const;

    void setCoe_string(const string &coe_string);

    int getCurrent_offset() const;

    void setCurrent_offset(int current_offset);

    void append_coe_string(string str, string type);

    void output2file(string filepath);

    unsigned int getStart_address() const;

    void setStart_address(unsigned int start_address);

private:
    /**
     * 倒入栈,从后往前注入（小端存储）
     */
     void append_coe_helper(string str, string& all_string);

private:
    string coe_string;
    int current_offset;
    unsigned int start_address;
};

#endif //ASSEMBLER_COE_H
