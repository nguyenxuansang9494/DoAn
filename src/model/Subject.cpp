#include "Subject.h"

Subject::Subject()
{
    //ctor
}

Subject::Subject(long id, string name, int grade) {
    this->id = id;
    this->name = name;
    this->grade = grade;
}

Subject::Subject(string name, int grade) {
    this->name = name;
    this->grade = grade;
}

Subject::~Subject()
{
    //dtor
}
