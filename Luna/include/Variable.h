#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <iostream>
#include <string>
#include "exception.h"


namespace luna
{
    class Variable
    {
        private:
            std::string Name;
            std::string content;
        public:
            Variable()=default; 
            Variable(std::string name_);
            ~Variable();

            Variable& setContent(std::string content_);
            const std::string& getContent() const;
            const std::string& getName() const;

            bool operator==(const luna::Variable& v2);
            Variable& operator=(const luna::Variable& v2);
    };
};
#endif