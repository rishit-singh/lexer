#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

enum class TokenType
{
    TK_EOF,
    TK_PARALEFT,
    TK_PARARIGHT,
    TK_STRING,
};

template<typename T>
class Token
{
public:
    const TokenType Type;

    const std::string Lexeme;

    const T Literal;

    const uint32_t Line;

    Token(const TokenType, const std::string, const T, const uint32_t);
    ~Token();
};

template <typename T>
Token<T>::Token(const TokenType type, const std::string lexeme, const T literal, const uint32_t line)
    : Type(type), Lexeme(lexeme), Literal(literal), Line(line) {}


template <typename T> Token<T>::~Token() {
}

#endif // TOKEN_H_
