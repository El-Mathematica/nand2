#include "CodeWriter.h"

CodeWriter::CodeWriter() {

}

void CodeWriter::setFileName(string filename, string path){
    fileName = filename;

    purepath = path.erase(path.find(".vm"));
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
    if(pushorpop==Parser::CommandType::C_PUSH && segment == "constant") {
        cout << segment << endl;
        outputFile << "@" << index << endl;
        outputFile << "D=A" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;

    } else if(pushorpop==Parser::CommandType::C_PUSH && (segment == "local" || segment == "argument" || segment == "this" || segment == "that")){
        outputFile << "@" + m[segment] << endl;
        outputFile << "D=M" << endl;
        outputFile << "@" << index << endl;
        outputFile << "D=D+A" << endl;
        outputFile << "A=D" << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;
    } else if(pushorpop==Parser::CommandType::C_PUSH && segment != "static") {
        int address = stoi(index) + stoi(m[segment]);
        outputFile << "@" + to_string(address) << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;
    } else if(pushorpop==Parser::CommandType::C_PUSH) {
        outputFile << "@" << fileName.substr(0, fileName.find(".")) << "." << index << endl;
        outputFile << "D=M" << endl;
        outputFile << "@SP" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;
        outputFile << "@SP" << endl;
        outputFile << "M=M+1" << endl;

    } else if(pushorpop==Parser::CommandType::C_POP && (segment == "local" || segment == "argument" || segment == "this" || segment == "that")) {
        

        outputFile << "@" + m[segment] << endl;
        outputFile << "D=M" << endl;
        outputFile << "@" << index << endl;
        outputFile << "D=D+A" << endl;
        outputFile << "@R13" << endl;
        outputFile << "M=D" << endl;

        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;
        
        
        outputFile << "@R13" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;

    } else if(pushorpop==Parser::CommandType::C_POP && segment != "static") {
        int address = stoi(index) + stoi(m[segment]);
        outputFile << "@" + to_string(address) << endl;
        outputFile << "D=A" << endl;
        outputFile << "@R14" << endl;
        outputFile << "M=D" << endl;

        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;

        outputFile << "@R14" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;

    } else if(pushorpop==Parser::CommandType::C_POP) {
        outputFile << "@" << fileName.substr(0, fileName.find(".")) << "." << index << endl;
        outputFile << "D=A" << endl;
        outputFile << "@R15" << endl;
        outputFile << "M=D" << endl;

        
        outputFile << "@SP" << endl;
        outputFile << "M=M-1" << endl;
        outputFile << "A=M" << endl;
        outputFile << "D=M" << endl;

        outputFile << "@R15" << endl;
        outputFile << "A=M" << endl;
        outputFile << "M=D" << endl;

    }
}

void CodeWriter::writeLabel(string label) {
    outputFile << "(" << currentFunctionName << "$" << label << ")" << endl;
}

void CodeWriter::writeCall(string functionName, int numArgs) {
    currentFunctionName = functionName;
}

void CodeWriter::writeGoto(string label) {
    outputFile << "@" << currentFunctionName << "$" << label << endl;
    outputFile << "0;JMP" << endl;
}

void CodeWriter::writeIf(string label) {
    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;
    outputFile << "@" << currentFunctionName << "$" << label << endl;
    outputFile << "D;JGT" << endl;
}