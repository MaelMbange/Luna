#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "exception.h"
// #include "lmacro.h"


namespace luna
{
    class file
    {
        private:
            std::string     name;
            std::string     content;
        public:
            file() = default;
            file(const std::string str);
            ~file();

            const char* get_name(void);
            const file& set_name(std::string& str);
            const std::string& get_content(void);
    };
};

#endif