//
// Created by Anthony on 2019/12/17.
//

#ifndef ASSEMBLER_SYMBOL_TABLE_H
#define ASSEMBLER_SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
using namespace std;

class SYMBOL_TABLE{
public:

    SYMBOL_TABLE();

    SYMBOL_TABLE(const unordered_map<string, unsigned int> &symbol_table);

    // 往symbol_table里面添加一个条目 Adds the pair (symbol,address) to the table.
    void addEntryToSymbolTable(string _symbol, unsigned int _address);
    // Does the symbol table contain the given symbol
    bool containsSymbol(string _symbol);
    // Returns the address associated with the symbol
    unsigned int getAddress(string _symbol);

private:
    unordered_map<string, unsigned int> symbol_table; // 存储symbol到address的hash table

};

#endif //ASSEMBLER_SYMBOL_TABLE_H
