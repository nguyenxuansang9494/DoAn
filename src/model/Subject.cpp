#include "Subject.h"

Subject::Subject()
{
    //ctor
}

Subject::Subject(string name, int grade) {
    this->name = name;
    this->grade = grade;
}

Subject::~Subject()
{
    //dtor
}
