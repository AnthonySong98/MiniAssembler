//
// Created by Anthony on 2019/12/17.
//

#include "symbol_table.h"

SYMBOL_TABLE::SYMBOL_TABLE(const unordered_map<string, unsigned int> &symbol_table) : symbol_table(symbol_table) {}

SYMBOL_TABLE::SYMBOL_TABLE() {}

// Implemented by Chen on 2019/12/17

void SYMBOL_TABLE::addEntryToSymbolTable(string _symbol, unsigned int _address){
    this->symbol_table.insert(make_pair(_symbol,_address));
}

bool SYMBOL_TABLE::containsSymbol(string _symbol){
    if(this->symbol_table.find(_symbol)!=this->symbol_table.end()) return true;
    else return false;
}

unsigned int SYMBOL_TABLE::getAddress(string _symbol){
    if(this->symbol_table.find(_symbol)!=this->symbol_table.end()) return symbol_table[_symbol];
    else return NULL;
}