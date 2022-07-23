#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <filesystem>


using namespace std;

int main(int argc, char* argv[]) {

    string fileOrDir(argv[1]); //file or dir to be compiled

    if(fileOrDir.find(".") != string::npos) { //checking whether its a file or dir
        string fileBaseName = fileOrDir.substr(0, fileOrDir.find(".")); //file name without extension

    } else {
        string path(filesystem::current_path().string() + "\\fileOrDir");
        cout << path;
    }

    getchar();
}