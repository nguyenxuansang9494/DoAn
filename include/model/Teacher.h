#ifndef TEACHER_H
#define TEACHER_H

#include <Person.h>
#include <Subject.h>
#include <string>
#include <vector>
using namespace std;



class Teacher : public Person
{
    public:
        Teacher();
        Teacher(string first_name, string last_name, Date dob, string email, string phone_number, Subject subject);
        Teacher(long id, string first_name, string last_name, Date dob, string email, string phone_number, Subject subject);
        virtual ~Teacher();

        Subject Getsubject() { return subject; }
        void Setsubject(Subject val) { subject = val; }

    protected:

    private:
        Subject subject;
};

#endif // TEACHER_H
