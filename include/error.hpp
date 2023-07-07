#ifndef ERROR_H_
#define ERROR_H_

#include <iostream>
#include <string_view>

class Error
{
public:
    static void Report(const Error);

    const std::string_view Message;

    const uint32_t Line;

    friend std::ostream& operator <<(std::ostream&, const Error&);

    Error(const uint32_t, std::string_view);
    ~Error();
};


#endif // ERROR_H_
