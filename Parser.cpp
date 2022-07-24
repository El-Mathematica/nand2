#include "Parser.h"

Parser::Parser(string filename) {
    file.open(filename);
}

bool Parser::hasMoreCommands() {
    int c = file.peek();
    if (c == EOF) {
        if(file.eof()) {
            return 0;
        }
        else {
            return 1;
        }
    }

    return 1;
}

void Parser::advance() {
    string line;
    getline(file, line);

    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    if(!(line.empty() || line.substr(0, 2) == "//")) {
        currentCommand = line;
    } else {
        advance();
    }
}

bool Parser::inArithmeticCommands() {
    return find(arithmeticCommands.begin(), arithmeticCommands.end(), currentCommand) != arithmeticCommands.end();
}