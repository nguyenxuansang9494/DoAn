#include "Mark.h"

Mark::Mark()
{
    //ctor
}

Mark::Mark(Student student, Class clazz, Subject subject, float value)
{
    this->student = student;
    this->clazz = clazz;
    this->subject = subject;
    this->value = value;
}


Mark::Mark(long id, Student student, Class clazz, Subject subject, float value)
{
    this->id = id;
    this->student = student;
    this->clazz = clazz;
    this->subject = subject;
    this->value = value;
}


Mark::~Mark()
{
    //dtor
}
