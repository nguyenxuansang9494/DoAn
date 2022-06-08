#include "Class.h"

Class::Class()
{
    //ctor
}

Class::Class(long id, int level, string name)
{
    this->id = id;
    this->level = level;
    this->name = name;
}

Class::Class(int level, string name)
{
    this->level = level;
    this->name = name;
}

Class::~Class()
{
    //dtor
}
