#include "Person.h"

Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}

Person::Person(string first_name, string last_name, Date dob, string email, string phone_number)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->dob = dob;
    this->email = email;
    this->phone_number = phone_number;
}
