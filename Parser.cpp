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
    
    


    if(!(line.empty() || line.substr(0, 2) == "//")) {
        currentCommand = line;
        line.substr(line.find_first_not_of(" "), line.find_last_not_of(" ") - line.find_first_not_of(" "));
    } else {
        
        advance();
    }
}

bool Parser::inArithmeticCommands() {
    return find(arithmeticCommands.begin(), arithmeticCommands.end(), currentCommand) != arithmeticCommands.end();
}

Parser::CommandType Parser::commandType() {
    if(inArithmeticCommands()) {
        return C_ARITHMETIC;
    } else if (currentCommand.find("push") != string::npos){

        return C_PUSH;
    } else {

        return C_POP;
    }
} 

string Parser::arg1() {

    int i = currentCommand.find(" ") + 1;

    string arg1 = "";
    while(true) {
        if(!(currentCommand[i] == *" ")) {
            arg1 = arg1 + currentCommand[i];

            i += 1;
        } else {
            break;
        }
    }
    return arg1;
}

string Parser::arg2() {
    int i = currentCommand.find(arg1()) + 1;
    while(currentCommand[i] != *" ") {
        i++;
    }

    return currentCommand.substr(i+1);
}