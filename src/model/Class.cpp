#include "Class.h"

Class::Class()
{
    //ctor
}

Class::Class(long id, int level, string name, int year,Teacher teacher)
{
    this->id = id;
    this->level = level;
    this->name = name;
    this->year = year;
    this->teacher = teacher;
}

Class::Class(int level, string name, int year, Teacher teacher)
{
    this->level = level;
    this->name = name;
    this->year = year;
    this->teacher = teacher;
}

Class::~Class()
{
    //dtor
}
