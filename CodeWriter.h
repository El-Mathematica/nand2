#ifndef CODEWRITER_HPP_INCLUDED
#define CODEWRITER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

#include "Parser.h"

using namespace std;

class CodeWriter {
public:
    string fileName = "output.asm";
    ofstream outputFile;
    CodeWriter();

    void setFileName(string fileName);
    void writeArithmetic(string command);
    void WritePushPop(Parser::CommandType pushorpop, string segment, int index);
};

#endif