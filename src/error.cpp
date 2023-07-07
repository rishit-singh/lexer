#include "error.hpp"

#include <iostream>

Error::Error(const uint32_t line, const std::string_view message)
    : Line(line), Message(message) {}

Error::~Error()
{}

std::ostream& operator <<(std::ostream &stream, const Error &error)
{
    stream << "Error at line " <<  error.Line << ": " << error.Message << '\n';

    return stream;
}

void Error::Report(const Error error) { std::cout << error; }
