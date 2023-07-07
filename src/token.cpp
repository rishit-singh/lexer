#include "token.hpp"

template <typename T>
Token<T>::Token(const TokenType type, const std::string_view lexeme,
                const T literal, const uint32_t line)
    : Type(type), Lexeme(lexeme), Literal(literal), Line(line) {}


template <typename T>
Token<T>::~Token()
{}
