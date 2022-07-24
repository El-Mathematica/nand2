#include "Parser.h"

Parser::Parser(string filename) {
    file.open(filename);
}

bool Parser::hasMoreCommands() {
    cout << "true" << endl;
    return 1;
}