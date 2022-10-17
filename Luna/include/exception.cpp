#include "exception.h"

luna::exception::exception()
{
    txt = "";
}
luna::exception::exception(const std::string& st)
{
    txt = st;
}
const char* luna::exception::what() const  
{
    return txt.c_str();
}
luna::exception::~exception(){}