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
    multiCommandCount++;
    string multiCommandCountStr = to_string(multiCommandCount);
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

    } else if(command == "neg") {

        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=-M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;

    } else if(command == "eq") {

        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M-D" << endl;
        outputFile << "@TRUEEQ" << multiCommandCountStr << endl;
        outputFile << "D;JEQ" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=0" << endl;
        outputFile << "@CONTINUEEQ" << multiCommandCountStr << endl;
        outputFile << "0;JMP" << endl;
        outputFile << "(TRUEEQ" << multiCommandCountStr << ")" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=-1" << endl;
        outputFile << "(CONTINUEEQ" << multiCommandCountStr << ")" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;


    } else if(command == "gt") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M-D" << endl;
        outputFile << "@TRUEGT" << multiCommandCountStr << endl;
        outputFile << "D;JGT" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=0" << endl;
        outputFile << "@CONTINUEGT" << multiCommandCountStr << endl;
        outputFile << "0;JMP" << endl;
        outputFile << "(TRUEGT" << multiCommandCountStr << ")" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=-1" << endl;
        outputFile << "(CONTINUEGT" << multiCommandCountStr << ")" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;

    } else if(command=="lt") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M-D" << endl;
        outputFile << "@TRUELT" << multiCommandCountStr << endl;
        outputFile << "D;JLT" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=0" << endl;
        outputFile << "@CONTINUELT" << multiCommandCountStr << endl;
        outputFile << "0;JMP" << endl;
        outputFile << "(TRUELT" << multiCommandCountStr << ")" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=-1" << endl;
        outputFile << "(CONTINUELT" << multiCommandCountStr << ")" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;
    } else if(command=="and") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=D&M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;
    } else if(command=="or") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=D|M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;
    } else if(command=="not") {
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=!M" << endl;
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