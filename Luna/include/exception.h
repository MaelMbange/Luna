#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <iostream>
#include <string>

namespace luna
{
    class exception 
    {
    private:
        std::string txt;
        
    public:
        exception();
        exception(const std::string& st = "");
        const char* what() const;
        ~exception();
    };
};

#endif