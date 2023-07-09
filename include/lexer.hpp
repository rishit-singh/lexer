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

    LexerState(const uint32_t = 0, const uint32_t = 0, const uint32_t = 1);
};

class Lexer
{
private:
    bool HadError;

    LexerState State;

    std::string Buffer;

    uint32_t Seek(const char);
    bool Match(const char);

public:
    std::vector<Token<std::string>> Scan();

    Lexer(std::string_view);
    ~Lexer();
};


#endif // LEXER_H_
