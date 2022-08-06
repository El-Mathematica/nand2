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

    } else {
        string path(filesystem::current_path().string() + "\\" + fileOrDir); //create path variable with directory path
        for(const auto & entry : filesystem::directory_iterator(path)) { //iterate through files in dir
            string pathString = entry.path().string(); //variable containing path string of file
            if(pathString.substr(pathString.find(".")) == ".vm") { //if encountering a vm file
                Parser parser(pathString); //create parser module for each vm file
                codeWriter.setFileName(fileOrDir, pathString); //notify codewriter another vm file has been opened
                while(parser.hasMoreCommands()) {
                    parser.advance();
                    
                    if(parser.commandType() == Parser::CommandType::C_ARITHMETIC) {
                        codeWriter.writeArithmetic(parser.currentCommand);
                    } else if(parser.commandType() == Parser::CommandType::C_PUSH) {
                        cout << parser.currentCommand.back() << endl;
                        string index(1, parser.currentCommand.back());
                        codeWriter.WritePushPop(Parser::CommandType::C_PUSH, "constant", index);
                    }
                }
            }
            
        }
    }

    getchar();
}