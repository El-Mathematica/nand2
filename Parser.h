#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Parser {
    public:

        string currentCommand;
        ifstream file;
        Parser(string filename);

        enum CommandType{C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL};
        bool hasMoreCommands();
        void advance();

        CommandType commandType();
        string arg1();
        string arg2();
};

#endif