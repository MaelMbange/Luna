#include "VariableMemory.h"
using namespace luna;


VariableMemory::~VariableMemory(){}

void VariableMemory::AddToList(const std::string& var)
{
    if(Exist(var))
    {
        std::string error = "\033[91mVARIABLE ERROR\033[0m: you can not have 2 variables having the same name!";
        throw exception(error);
    }
    Variable rvar(var);
    ListeVariable.push_back(rvar);
}

bool VariableMemory::Exist(const std::string& var)
{
    Variable rvar(var);
    for(auto& lv : ListeVariable)
    {
        if(lv == rvar)
            return true;
    }
    return false;
}

Variable& VariableMemory::VariableAt(Variable& var)
{
    return this->operator[](var);
}
Variable& VariableMemory::VariableAt(std::string& var)
{
    return this->operator[](var);
}
Variable& VariableMemory::operator[](std::string& var)
{
    for(auto& lv : ListeVariable)
    {
        if(lv.getName() == var)
            return lv;        
    }
    std::string error = "\033[91mVARIABLE ERROR\033[0m: Variables does not exists!";
    throw exception(error);
}

Variable& VariableMemory::operator[](Variable& var)
{
    for(auto& lv : ListeVariable)
    {
        if(lv == var)
            return lv;        
    }
    std::string error = "\033[91mVARIABLE ERROR\033[0m: Variables does not exists!";
    throw exception(error);
}