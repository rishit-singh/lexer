#ifndef FILEIO_H_
#define FILEIO_H_

#include <exception>
#include <fstream>
#include <string>
#include <string_view>


using buffer_iter = std::istreambuf_iterator<char>;

std::string ReadFile(std::string_view);


#endif // FILEIO_H_
