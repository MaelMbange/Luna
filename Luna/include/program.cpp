#include "program.h"


luna::Program::~Program(){}

void luna::Program::START(const int argc,const char* argv[])
{
    try
    {  
        if(!(argc > 1))
        {
            throw luna::exception("\033[91mERROR\033[0m: NOT ENOUGH PARAMETERS");
        }            
        
        luna::file fi(argv[1]);
        //std::cout << fi.get_content() << std::endl;
        
        Compiler cp(fi.get_content());
        cp.Program(fi.get_name());

    }
    catch(const luna::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
