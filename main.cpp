#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <filesystem>

#include "Parser.h"
#include "CodeWriter.h"

using namespace std;

int main(int argc, char* argv[]) {

    string fileOrDir(argv[1]); //file or dir to be compiled



    CodeWriter codeWriter;//testing codewriter module

    if(fileOrDir.find(".") != string::npos) { //checking whether its a file or dir
        string fileBaseName = fileOrDir.substr(0, fileOrDir.find(".")); //file name without extension

    } else {
        string path(filesystem::current_path().string() + "\\" + fileOrDir);
        for(const auto & entry : filesystem::directory_iterator(path)) {
            string pathString = entry.path().string();
            if(pathString.substr(pathString.find(".")) == ".vm") {
                Parser parser(pathString);
                codeWriter.setFileName(pathString);
            }
            
        }
    }

    getchar();
}