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

        line = line.substr(line.find_first_not_of(" "));
        line = line.substr(0, line.find("//"));
        if(line[line.length() - 1] == *" ") {
            line = line.substr(0, line.find_last_not_of(" ") + 1);
        }
        cout << currentCommand << endl;
        currentCommand = line;
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
    } else if(currentCommand.find("push") != string::npos){
        return C_PUSH;
    } else if(currentCommand.find("if-goto") != string::npos) {
        return C_IF;
    } else if(currentCommand.find("goto") != string::npos) {
        return C_GOTO;
    } else if(currentCommand.find("label") != string::npos) {
        return C_LABEL;
    } else if(currentCommand.find("call") != string::npos) {
        return C_CALL;
    } else if(currentCommand.find("function") != string::npos) {
        return C_FUNCTION;
    } else if(currentCommand.find("return") != string::npos) {
        return C_RETURN;
    }
    else {
        return C_POP;
    }
} 

string Parser::arg1() {

    int i = currentCommand.find(" ") + 1;

    string arg1 = "";
    while(true) {
        if(isalnum(currentCommand[i]) || currentCommand[i] == *"." || currentCommand[i] == *"_") {
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
    string arg2 = "";
    while(isalnum(currentCommand[i])  || currentCommand[i] == *"." || currentCommand[i] == *"_") {

        i++;
    }

    i++;

    while(isalnum(currentCommand[i])  || currentCommand[i] == *"." || currentCommand[i] == *"_") {

        arg2 = arg2 + currentCommand[i];
        i++;
    }

    return arg2;
}