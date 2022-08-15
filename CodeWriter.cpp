#include "CodeWriter.h"

CodeWriter::CodeWriter() {

}

void CodeWriter::setFileName(string filename, string path){
    fileName = filename;
    if(fileName.find(".vm") != string::npos) {
        fileName = fileName.substr(0, fileName.find(".vm"));
    }
    
    purepath = path.substr(0, path.find(".vm"));
    cout << purepath << endl;
    purepath = purepath + ".asm";
    cout << purepath << endl;
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
    functionCommandCount++;
    string funcCommandCount = to_string(functionCommandCount);
    string returnaddress = currentFunctionName + "$" + "return" + funcCommandCount;

    WritePushPop(Parser::CommandType::C_PUSH, "constant", returnaddress); //pushing return address

    outputFile << "@" << "LCL" << endl; //pushing lcl
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;

    outputFile << "@" << "ARG" << endl; //pushing arg
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;

    outputFile << "@" << "THIS" << endl; //pushing this
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;

    outputFile << "@" << "THAT" << endl; //pushing that
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;

    outputFile << "@" << "SP" << endl; //arg = sp - n - 5
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;
    WritePushPop(Parser::CommandType::C_PUSH, "constant", to_string(numArgs));
    writeArithmetic("sub");
    WritePushPop(Parser::CommandType::C_PUSH, "constant", "5");
    writeArithmetic("sub");
    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;
    outputFile << "@ARG" << endl;
    outputFile << "M=D" << endl;

    outputFile << "@" << "SP" << endl; //lcl = sp
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;
    outputFile << "@LCL" << endl;
    outputFile << "M=D" << endl;

    //ADD ACTUAL GOTO
    outputFile << "@" << currentFunctionName << endl;
    outputFile << "0;JMP" << endl;
    writeLabel("return" + funcCommandCount); //temp modify 
}

void CodeWriter::writeFunction(string functionName, int numLocals) {

    currentFunctionName = functionName;
    
    outputFile << "(" << currentFunctionName << ")" << endl; 
    outputFile << "@" << to_string(numLocals) << endl;//*r13 = numLocals
    outputFile << "D=A" << endl;
    outputFile << "@" << "13" << endl;
    outputFile << "M=D" << endl;
    WritePushPop(Parser::CommandType::C_PUSH, "constant", to_string(numLocals)); //push constant 2
    writeIf("INITIALISELOCALVARIABLES");
    writeGoto("FINALISEDLOCALVARIABLES");
    writeLabel("INITIALISELOCALVARIABLES");

    WritePushPop(Parser::CommandType::C_PUSH, "constant", "0");

    outputFile << "@" << "13" << endl; //numLocals = numLocals - 1
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;

    
    WritePushPop(Parser::CommandType::C_PUSH, "constant", "1");
    writeArithmetic("sub");

    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;
    outputFile << "@13" << endl;
    outputFile << "M=D" << endl;

    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;
    

    writeIf("INITIALISELOCALVARIABLES");
    writeLabel("FINALISEDLOCALVARIABLES");
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
    outputFile << "D;JNE" << endl; //modified
}

void CodeWriter::writeReturn() {
    outputFile << "@LCL" << endl; //frame = lcl
    outputFile << "D=M" << endl;
    outputFile << "@FRAME" << endl;
    outputFile << "M=D" << endl;


    outputFile << "@" << "FRAME" << endl; 
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;

    WritePushPop(Parser::CommandType::C_PUSH, "constant", "5");
    writeArithmetic("sub");

    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;

    outputFile << "@RET" << endl;
    outputFile << "M=D" << endl;

    //*arg = pop()
    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;

    outputFile << "@ARG" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;

    //sp = arg + 1
    outputFile << "@" << "ARG" << endl; 
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "A=M" << endl;
    outputFile << "M=D" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=M+1" << endl;
    WritePushPop(Parser::CommandType::C_PUSH, "constant", "1");
    writeArithmetic("add");
    outputFile << "@SP" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "A=M" << endl;
    outputFile << "D=M" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=D" << endl;

    //THAT = *(Frame - 1)
    outputFile << "@" << "FRAME" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "D=M" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "A=D" << endl;
    outputFile << "D=M" << endl;

    outputFile << "@THAT" << endl;
    outputFile << "M=D" << endl;

    //THIS = *(Frame - 2)
    outputFile << "@" << "FRAME" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "D=M" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "A=D" << endl;
    outputFile << "D=M" << endl;
    
    outputFile << "@THIS" << endl;
    outputFile << "M=D" << endl;

    //ARG = *(Frame - 3)
    outputFile << "@" << "FRAME" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "D=M" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "A=D" << endl;
    outputFile << "D=M" << endl;
    
    outputFile << "@ARG" << endl;
    outputFile << "M=D" << endl;

    //LCL = *(Frame - 4)
    
    outputFile << "@" << "FRAME" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "M=M-1" << endl;
    outputFile << "D=M" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "M=M+1" << endl;
    outputFile << "A=D" << endl;
    outputFile << "D=M" << endl;
    
    outputFile << "@LCL" << endl;
    outputFile << "M=D" << endl;


    outputFile << "@" << "RET" << endl;//goto return address
    outputFile << "A=M" << endl;
    outputFile << "0;JMP" << endl;
}

void CodeWriter::writeInit() {

    outputFile << "@256" << endl;
    outputFile << "D=A" << endl;
    outputFile << "@SP" << endl;
    outputFile << "M=D" << endl;
    writeCall("Sys.init", 0);
}