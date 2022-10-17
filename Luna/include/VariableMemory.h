#ifndef __VARI_MEM_H__
#define __VARI_MEM_H__
#include <iostream>
#include <vector>
#include <string>
#include "Variable.h"

using namespace luna;

namespace luna
{
    class VariableMemory
    {
        private:
            std::vector<Variable> ListeVariable;
        public:
            VariableMemory()=default;
            ~VariableMemory();

            void AddToList(const std::string& var);
            bool Exist(const std::string& var);
            Variable& VariableAt(Variable& var);
            Variable& VariableAt(std::string& var);
            Variable& operator[](Variable& var);
            Variable& operator[](std::string& var);
    };
};
#endif