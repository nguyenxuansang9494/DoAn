#include "TeachingAssignment.h"

TeachingAssignment::TeachingAssignment()
{
    //ctor
}

TeachingAssignment::TeachingAssignment(Subject subject, Class clazz, Teacher teacher)
{
    this->subject = subject;
    this->clazz = clazz;
    this->teacher = teacher;
}

TeachingAssignment::TeachingAssignment(long id, Subject subject, Class clazz, Teacher teacher)
{
    this->id = id;
    this->subject = subject;
    this->clazz = clazz;
    this->teacher = teacher;
}

TeachingAssignment::~TeachingAssignment()
{
    //dtor
}
