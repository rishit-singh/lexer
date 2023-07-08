#ifndef LEXER_H_
#define LEXER_H_

#include "error.hpp"
#include "token.hpp"
#include "fileio.hpp"
#include <vector>

struct LexerState
{
    uint32_t Start;

    uint32_t Current;

    uint32_t Line;

    LexerState(uint32_t = 0, uint32_t = 0, uint32_t = 1);
};

class Lexer
{
private:
    bool HadError;

    LexerState State;

    std::vector<Token<int> > Tokens;

    std::string_view Buffer;

public:
    void Scan();

    const std::vector<Token<int> >& GetTokens();

    Lexer(std::string_view);
    ~Lexer();
};


#endif // LEXER_H_
