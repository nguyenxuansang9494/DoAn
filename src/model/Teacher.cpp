#include "Teacher.h"

Teacher::Teacher()
{
    //ctor
}

Teacher::Teacher(string first_name, string last_name, Date dob, string email, string phone_number, vector<Subject> subject)
{
    Person(first_name, last_name, dob, email, phone_number);
    this->subject = subject;
}

Teacher::Teacher(long id, string first_name, string last_name, Date dob, string email, string phone_number, vector<Subject> subject)
{
    Person(id, first_name, last_name, dob, email, phone_number);
    this->subject = subject;
}

Teacher::~Teacher()
{
    //dtor
}
