#ifndef TOKEN_H_
#define TOKEN_H_

#include <string_view>

enum class TokenType
{};

template<typename T>
class Token
{
public:
    const TokenType Type;

    const std::string_view Lexeme;

    const T Literal;

    const uint32_t Line;

    Token(const TokenType, const std::string_view, const T, const uint32_t);
    ~Token();
};


#endif // TOKEN_H_
