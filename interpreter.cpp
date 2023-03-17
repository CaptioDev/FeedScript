#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "parser.h"
#include "interpreter.h"
#include "interpreter.h"
#include <cstring>
#include <cstdlib>

token_t* tokenize(char* input) {
    // implementation of the tokenize function // DEFINE WITH MATTHEW
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " filename\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "Error: could not open file '" << argv[1] << "'\n";
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    token_t *tokens = tokenize(input.c_str());
    expression_t *expr = parse(tokens);
    value_t result = interpret(expr);

    std::cout << result << std::endl;

    free_tokens(tokens);
    free_expression(expr);

    return 0;
}
