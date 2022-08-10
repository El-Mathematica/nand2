#ifndef CODEWRITER_HPP_INCLUDED
#define CODEWRITER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "Parser.h"

using namespace std;

class CodeWriter {
public:
    string fileName = "output.asm";
    string purepath = "";
    string currentFunctionName = "";
    ofstream outputFile;
    int multiCommandCount = 0;
    map<string, string> m = {{"local", "LCL"}, {"argument", "ARG"}, {"this", "THIS"}, {"that", "THAT"}, {"pointer", "3"}, {"temp", "5"}};

    CodeWriter();

    void setFileName(string fileName, string path);
    void writeArithmetic(string command);
    void WritePushPop(Parser::CommandType pushorpop, string segment, string index);
    void writeInit();
    void writeLabel(string label);
    void writeGoto(string label);
    void writeIf(string label);
    void writeCall(string functionName, int numArgs);
    void writeReturn();
    void writeFunction(string functionName, int numLocals);
};

#endif