#include "CodeWriter.h"

CodeWriter::CodeWriter() {
    outputFile.open("output.asm");
}

void CodeWriter::setFileName(string filename){
    cout << "codewriter module implemented" << endl;
    outputFile << "setting file name" + filename << endl;
}