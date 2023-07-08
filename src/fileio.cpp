#include "fileio.hpp"

std::string ReadFile(std::string_view path)
{
    std::ifstream file = std::ifstream(path.data());

    std::string buffer;

    if (!file.is_open())
      throw std::runtime_error("Could not open file.");

    buffer = std::string(buffer_iter(file.rdbuf()), buffer_iter());

    file.close();

    return buffer;
}
