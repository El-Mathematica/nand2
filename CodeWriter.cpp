#include "CodeWriter.h"

CodeWriter::CodeWriter() {

}

void CodeWriter::setFileName(string filename, string path){
    fileName = filename;

    string purepath = path.erase(path.find(".vm"));
    purepath = purepath + ".asm";
    outputFile.open(purepath);
}

void CodeWriter::writeArithmetic(string command) {

    if(command == "add") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=D+M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;

    } else if(command == "sub") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M-D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;
    }
}

void CodeWriter::WritePushPop(Parser::CommandType pushorpop, string segment, string index) {
    if(pushorpop==Parser::CommandType::C_PUSH) {
        outputFile << "@" << index << endl;
        outputFile << "D=A" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;

    } else {

    }
}