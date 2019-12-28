cmake_minimum_required(VERSION 3.10)
project(MiniC_Compiler)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MiniC_Compiler
        CtoMIPS.c
        definition.c
        definition.h
        lex.yy.c
        Makefile
        minic.l
        minic.tab.c
        minic.tab.h
        minic.y)
