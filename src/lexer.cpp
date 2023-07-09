#include "lexer.hpp"

LexerState::LexerState(uint32_t start, uint32_t current, uint32_t line)
    : Start(start), Current(current), Line(line) {}


Lexer::Lexer(std::string_view filePath)
    : HadError(false)
{
    this->Buffer = ReadFile(filePath);
}

Lexer::~Lexer()
{
}

const bool Lexer::Match(const char c)
{
    if (this->State.Current >= this->Buffer.size()) // EOF check
        return false;

    if (this->Buffer[this->State.Current] == c)
    {
        this->State.Current++;
        return true;
    }

    return false;
}

const bool Lexer::IsEnd() const
{
    return (this->State.Current >= this->Buffer.size());
}

uint32_t Lexer::Seek(const char c)
{
    uint32_t& index = this->State.Current;

    // ++index;


    // std::cout << "Index: " << index << '\n';

    for (index = this->State.Current; index < this->Buffer.size() && this->Buffer[index] != c; index++);

    return index;
}


std::vector<Token<std::string>> Lexer::Scan()
{
    uint32_t& current = this->State.Current,
        &start = this->State.Start;

    std::vector<Token<std::string>> tokens = std::vector<Token<std::string>>();

    char c;

    for (int current = 0; current < this->Buffer.size(); start = current)
    {
        switch (c = this->Buffer[current++])
        {
            case '(':
                tokens.push_back(Token<std::string>(TokenType::TK_PARALEFT, this->Buffer.substr(start, current), "", this->State.Line));

                break;

            case ')':
               tokens.push_back(Token<std::string>(TokenType::TK_PARARIGHT, this->Buffer.substr(start, current), "", this->State.Line));

               break;

            case '"':
            {
                if (this->IsEnd())
                {
                    Error::Report(Error(this->State.Line, "Unterminated string."));
                    break;
                }

                if (this->Buffer[this->Seek('"')] == '"')
                    tokens.push_back(Token<std::string>(TokenType::TK_STRING, this->Buffer.substr(start + 1, current - 1), "\"\"",  this->State.Line));

                break;
            }

            case '\n':
                this->State.Line++;
                break;

            default:
                std::string message = "Unexpected token ";

                message += c;

                Error::Report(Error(this->State.Line, message));

                this->HadError = true;


                break;
        }
    }


    return tokens;
//    tokens.push_back(Token<std::string_view>(TokenType::TK_EOF, nullptr, "\0", this->State.Line));
}
