//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_STRING_UTIL_H
#define ASSEMBLER_STRING_UTIL_H

#include <string>
#include <vector>

using namespace std;

/*
 * 字符串处理工具
 */
class STRING_UTIL{
public:
    /**
     * 判断空行
     */
     bool isEmptyLine(string &_COL);

    /**
     * 大写转小写，原地转化，注释后内容不变
     */
    void upperCase2LowerCase(string &_COL);

    /**
     * extract comments, 原COL不变
     * 如果有注释，则提取出来，返回true
     * 如果没有注释，返回false
     */
    bool extractComment(string _COL, string &_comment);

    /**
     * delete comment, 原地修改
     * 逻辑同上
     */
    void deleteComment(string &_COL);

    /**
     * delete tab
     * @param _COL
     */
    void deleteTab(string &_COL);

    /**
     * 判断是否是数字，如果是，则判断是10进制还是16进制
     * @param para
     * @return
     */
    bool isNumber(string para, int& base);

    /**
     * 判断是否是伪指令, 如果是则返回伪指令的类型
     * 只判断.data和.text
     */
    bool isPseudoInst(string _COL, string &_type);

    /**
    * .data和.text伪指令取得起始地址
    */
    unsigned int getSegStartAddress(string _COL);

    /**
    * parse .data伪指令(single code of line)
    */
    void parseDataPseudoInst(string _COL, string& variable_name, string& variable_type, vector<string>& init_value_list);

    /**
    * trim white space
    */
    string trim(string& s);

    /**
    * split string
    */
    void split(string s,string delimiter, vector<string>& res);

    /**
     * parse .text指令（核心）
     */
    void parseCodeInst(string _COL, string& label_name, string& inst_name, vector<string>& para_list );

    /**
     * containsDenfinedInst
     * check 指令名是否存在
     */
    bool containsDenfinedInst(string _COL, string& inst_name);

    /**
     * 判断是否是label或者variable
     * @param para
     * @return
     */
    bool isLabelOrVariable(string para, string& label);

    /**
     * 提取寄存器名称，并映射到寄存器编号，最后以二进制字符串输出（默认为5位）
     * @param para
     * @return
     */
    string extractRegName(string para, int num = 5);


    /**
     * 提取立即数
     * @param para
     * @param num
     * @return
     */
    string extractImmediate(string para, int num = 16, int type = 1);

    /**
     * type为0做zero-extend
     * type为1做signed-extend
     * @param para
     * @param type
     * @return
     */
    string getExtended(string para, int type, int num = 16);


    /**
     * (PC)←( (Zero-Extend) address<<2)
     * @param para
     * @return
     */
    string extractAddress(string para);

    /**
     * binString2HexString
     * @param bin_string
     * @return
     */
    string binString2HexString(const string & bin_string);

    /**
     * 移位指令需要使用
     * @param para
     * @param num
     * @return
     */
    string extractShamt(string para,int num = 5);


    /**
     * 跳转指令 提取offset
     * 当type为0 表明para已经是立即数
     * 当type为1 表明para是个label
     * @param para
     * @param current_address
     * @param next_address
     * @param type
     * @return
     */
    string extractOffset(string para, unsigned int current_address = 0, unsigned int next_address = 0,int type = 0);
};

#endif //ASSEMBLER_STRING_UTIL_H
