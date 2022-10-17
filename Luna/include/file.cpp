#include "file.h"

luna::file::file(const std::string str)
{    
    if(str.empty() == true)
        throw luna::exception("\033[91mERROR\033[0m: NO FILE ENTRY! ..."); 

    if(str.find(".ln") == std::string::npos)    
        throw luna::exception("\033[91mERROR\033[0m: BAD FILE EXTENSION! ...");  

    this->name = str;
    {
        std::fstream    s_file;
        std::stringstream sstr;

        s_file.open(str);
        if(s_file.is_open() == false)
        {
            std::string error = "\033[91mERROR\033[0m: COULD NOT ACCESS FILE=" + str;
            throw luna::exception(error); 
        }
        sstr << s_file.rdbuf();
        this->content = sstr.str();

        s_file.close();
    }
}

luna::file::~file(){}

const char* luna::file::get_name(void)
{
    return this->name.c_str();
}
const luna::file& luna::file::set_name(std::string& str)
{
    this->name = str;
    return *this;
}
const std::string& luna::file::get_content(void)
{
    return this->content;
}