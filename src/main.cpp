#include <iostream>
#include "lexer.hpp"

int main(int argc, char** argv)
{
    Lexer lex = Lexer(argv[1]);


    const std::vector<Token<std::string>> tokens = lex.Scan();

    for (int x = 0; x < tokens.size(); x++)
        std::cout << tokens[x].Lexeme;

    std::cout << '\n';
    return 0;
}
