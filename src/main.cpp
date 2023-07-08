#include <iostream>
#include "lexer.hpp"

int main(int argc, char** argv)
{
    Lexer lex = Lexer(argv[1]);

    lex.Scan();


    const std::vector<Token<int> >& tokens = lex.GetTokens();

    for (int x = 0; x < tokens.size(); x++)
        std::cout << tokens[x].Lexeme;

    std::cout << '\n';
    return 0;
}
