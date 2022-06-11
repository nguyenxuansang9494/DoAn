#include "Teacher.h"

Teacher::Teacher()
{
    //ctor
}

Teacher::Teacher(string first_name, string last_name, Date dob, string email, string phone_number, Subject subject)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->dob = dob;
    this->email = email;
    this->phone_number = phone_number;
    this->subject = subject;
}

Teacher::Teacher(long id, string first_name, string last_name, Date dob, string email, string phone_number, Subject subject)
{
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->dob = dob;
    this->email = email;
    this->phone_number = phone_number;
    this->subject = subject;
}

Teacher::~Teacher()
{
    //dtor
}
