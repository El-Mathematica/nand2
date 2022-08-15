#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

#include "Parser.h"
#include "CodeWriter.h"

using namespace std;

int main(int argc, char* argv[]) {

    string fileOrDir(argv[1]); //file or dir to be compiled



    CodeWriter codeWriter;//testing codewriter module

    if(fileOrDir.find(".") != string::npos) { //checking whether its a file or dir

        string fileBaseName = fileOrDir.substr(0, fileOrDir.find(".")); //file name without extension
        string path(filesystem::current_path().string() + "\\" + fileOrDir);
        cout << path << endl;
        Parser parser(path);
 
        codeWriter.setFileName(fileOrDir, path);
        codeWriter.writeInit(); 
        while(parser.hasMoreCommands()) {
            parser.advance();

            cout << parser.currentCommand << endl;
            if(parser.commandType() == Parser::CommandType::C_ARITHMETIC) {
                codeWriter.writeArithmetic(parser.currentCommand);
            } else if(parser.commandType() == Parser::CommandType::C_PUSH) {
                codeWriter.WritePushPop(Parser::CommandType::C_PUSH, parser.arg1(), parser.arg2());

            } else if(parser.commandType() == Parser::CommandType::C_POP) {
                cout << parser.arg2() << endl;
                codeWriter.WritePushPop(Parser::CommandType::C_POP, parser.arg1(), parser.arg2());
            } else if(parser.commandType() == Parser::CommandType::C_CALL) {
                codeWriter.writeCall(parser.arg1(), stoi(parser.arg2()));
            } else if(parser.commandType() == Parser::CommandType::C_LABEL) {
                codeWriter.writeLabel(parser.arg1());
            } else if(parser.commandType() == Parser::CommandType::C_GOTO) {
                codeWriter.writeGoto(parser.arg1());
            } else if(parser.commandType() == Parser::CommandType::C_IF) {
                codeWriter.writeIf(parser.arg1());
            } else if(parser.commandType() == Parser::CommandType::C_FUNCTION) {
                codeWriter.writeFunction(parser.arg1(), stoi(parser.arg2()));
            } else if(parser.commandType() == Parser::CommandType::C_RETURN) {
                codeWriter.writeReturn();
            }
        }

    } else {
        string path(filesystem::current_path().string() + "\\" + fileOrDir); //create path variable with directory path
        codeWriter.setFileName(fileOrDir, filesystem::current_path().string() + "\\" + fileOrDir);
        cout << filesystem::current_path().string() + "\\" + fileOrDir << endl;
        for(const auto & entry : filesystem::directory_iterator(path)) { //iterate through files in dir
            string pathString = entry.path().string(); //variable containing path string of file
            if(pathString.substr(pathString.find(".")) == ".vm") { //if encountering a vm file
                Parser parser(pathString); //create parser module for each vm file
                 //notify codewriter another vm file has been opened
                codeWriter.writeInit();
                while(parser.hasMoreCommands()) {
                    parser.advance();
                    cout << parser.currentCommand << endl;
                    
                    if(parser.commandType() == Parser::CommandType::C_ARITHMETIC) {

                        codeWriter.writeArithmetic(parser.currentCommand);


                    } else if(parser.commandType() == Parser::CommandType::C_PUSH) {

                        codeWriter.WritePushPop(Parser::CommandType::C_PUSH, parser.arg1(), parser.arg2());
                        

                    } else if(parser.commandType() == Parser::CommandType::C_POP) { 
                        codeWriter.WritePushPop(Parser::CommandType::C_POP, parser.arg1(), parser.arg2());
                    } else if(parser.commandType() == Parser::CommandType::C_CALL) {

                        codeWriter.writeCall(parser.arg1(), stoi(parser.arg2()));
                    } else if(parser.commandType() == Parser::CommandType::C_LABEL) {
                        codeWriter.writeLabel(parser.arg1());
                    } else if(parser.commandType() == Parser::CommandType::C_GOTO) {
                        codeWriter.writeGoto(parser.arg1());
                    } else if(parser.commandType() == Parser::CommandType::C_IF) {
                        codeWriter.writeIf(parser.arg1());
                    } else if(parser.commandType() == Parser::CommandType::C_FUNCTION) {
                        codeWriter.writeFunction(parser.arg1(), stoi(parser.arg2()));
                    } else if(parser.commandType() == Parser::CommandType::C_RETURN) {
                        codeWriter.writeReturn();
                    }
                }
            }
            
        }
    }

    getchar();
}