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
};

#endif //ASSEMBLER_STRING_UTIL_H
