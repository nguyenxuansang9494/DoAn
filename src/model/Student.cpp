#include "Student.h"

Student::Student()
{
    //ctor
}

Student::Student(string first_name, string last_name, Date dob, string email, string phone_number, Class clazz)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->dob = dob;
    this->email = email;
    this->phone_number = phone_number;
    this->student_class = clazz;
}


Student::Student(long id, string first_name, string last_name, Date dob, string email, string phone_number, Class clazz)
{
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->dob = dob;
    this->email = email;
    this->phone_number = phone_number;
    this->student_class = clazz;
}

Student::~Student()
{
    //dtor
}
