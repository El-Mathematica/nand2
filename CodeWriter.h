#ifndef CODEWRITER_HPP_INCLUDED
#define CODEWRITER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

#include "Parser.h"

using namespace std;

class CodeWriter {
public:
    void setFileName(string fileName);
    void writeArithmetic(string command);
    void WritePushPop(Parser::CommandType pushorpop, string segment, int index);
};

#endif