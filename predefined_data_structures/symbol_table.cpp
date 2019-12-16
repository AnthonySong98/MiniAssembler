//
// Created by Anthony on 2019/12/17.
//

#include "symbol_table.h"

SYMBOL_TABLE::SYMBOL_TABLE(const unordered_map<string, unsigned int> &symbol_table) : symbol_table(symbol_table) {}

SYMBOL_TABLE::SYMBOL_TABLE() {}

// TODO: implement addEntryToSymbolTable
void SYMBOL_TABLE::addEntryToSymbolTable(string _symbol, unsigned int _address){

}

// TODO: implement containsSymbol
bool SYMBOL_TABLE::containsSymbol(string _symbol){
    return false;
}

//TODO: implement getAddress
unsigned int SYMBOL_TABLE::getAddress(string _symbol){
    return 0;
}