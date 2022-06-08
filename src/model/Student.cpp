#include "Student.h"

Student::Student()
{
    //ctor
}

Student::Student(string first_name, string last_name, Date dob, string email, string phone_number, vector<Class> clazz)
{
    Person(first_name, last_name, dob, email, phone_number);
    this->student_class = clazz;
}


Student::Student(long id, string first_name, string last_name, Date dob, string email, string phone_number, vector<Class> clazz)
{
    Person(id, first_name, last_name, dob, email, phone_number);
    this->student_class = clazz;
}

Student::~Student()
{
    //dtor
}
