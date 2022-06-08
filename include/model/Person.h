#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "Date.h"
using namespace std;

class Person
{
    public:
        Person();
        Person(long, string, string, Date, string, string);
        Person(string, string, Date, string, string);
        virtual ~Person();

        string Getfirst_name() { return first_name; }
        void Setfirst_name(string val) { first_name = val; }
        string Getlast_name() { return last_name; }
        void Setlast_name(string val) { last_name = val; }
        Date Getdob() { return dob; }
        void Setdob(Date val) { dob = val; }
        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string Getphone_number() { return phone_number; }
        void Setphone_number(string val) { phone_number = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }

    protected:

    private:
        long id;
        string first_name;
        string last_name;
        Date dob;
        string email;
        string phone_number;
};

#endif // PERSON_H
