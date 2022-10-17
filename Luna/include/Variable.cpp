#include "Variable.h"

using namespace luna;

Variable::Variable(std::string name_) : Name(name_){}
Variable::~Variable(){}

luna::Variable& Variable::setContent(std::string content_)
{
    content = content_;
    return *this;
}
const std::string& Variable::getContent() const
{
    return content;
}
const std::string& Variable::getName() const
{
    return Name;
}

bool Variable::operator==(const luna::Variable& v2)
{
    if(this->getName() == v2.getName())
        return true;
    return false;
}
Variable& Variable::operator=(const luna::Variable& v2)
{
    this->Name = v2.Name;
    this->content = v2.content;
    return *this;
}