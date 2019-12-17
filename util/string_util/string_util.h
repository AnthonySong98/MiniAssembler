//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_STRING_UTIL_H
#define ASSEMBLER_STRING_UTIL_H

#include <string>
using namespace std;

/*
 * 字符串处理工具
 */
class STRING_UTIL{
public:
    /*
     * 大写转小写，原地转化，注释后内容不变
     */
    void upperCase2LowerCase(string &_COL);

    /*
     * extract comments, 原COL不变
     * 如果有注释，则提取出来，返回true
     * 如果没有注释，返回false
     */
    bool extractComment(string _COL, string &_comment);

    /*
     * delete comment, 原地修改
     * 逻辑同上
     */
    void deleteComment(string &_COL);


    // 判断是否是伪指令, 如果是则返回伪指令的类型
    bool isPseudoInst(string _COL, string &_type);

};

#endif //ASSEMBLER_STRING_UTIL_H
