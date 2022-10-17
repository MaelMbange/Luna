#ifndef __PROGRAM_H__
#define __PROGRAM_H__
#include <iostream>
#include <cstring>
#include <string>
#include "exception.h"
#include "file.h"
#include "compiler.h"
// #include "lmacro.h"


namespace luna
{
    class Program
    {   
        public:
            Program() = default;
            ~Program();
            static void START(const int argc,const char* argv[]);
    };
};

#endif