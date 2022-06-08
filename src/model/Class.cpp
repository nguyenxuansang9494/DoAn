#include "Class.h"

Class::Class()
{
    //ctor
}

Class::Class(long id, int level, string name, Teacher teacher)
{
    this->id = id;
    this->level = level;
    this->name = name;
    this->teacher = teacher;
}

Class::Class(int level, string name, Teacher teacher)
{
    this->level = level;
    this->name = name;
    this->teacher = teacher;
}

Class::~Class()
{
    //dtor
}
