#include "lexer.hpp"

LexerState::LexerState(uint32_t start, uint32_t current, uint32_t line)
    : Start(start), Current(current), Line(line) {}


Lexer::Lexer(std::string_view filePath)
    : HadError(false), Tokens(std::vector<Token<int>>()) {
    this->Buffer = ReadFile(filePath);
}

Lexer::~Lexer()
{}

void Lexer::Scan()
{
    uint32_t& current = this->State.Current,
        &start = this->State.Start;

    char c;

    for (int x = 0; x < this->Buffer.size(); x++, start = current)
        switch (c = this->Buffer[current++])
        {
            case '(':
               this->Tokens.push_back(Token<int>(TokenType::TK_PARALEFT, this->Buffer.substr(start, current), 0, this->State.Line));

                break;

            case ')':
               this->Tokens.push_back(Token<int>(TokenType::TK_PARARIGHT, this->Buffer.substr(start, current), 0, this->State.Line));

               break;

            case '\n':
                this->State.Line++;
                break;

            default:
                Error::Report(Error(this->State.Line, "Unexpected token."));

                this->HadError = true;

                break;
        }


    this->Tokens.push_back(Token<int>(TokenType::TK_EOF, nullptr, 0, this->State.Line));
}

const std::vector<Token<int>> &Lexer::GetTokens() {
    return this->Tokens;
}
