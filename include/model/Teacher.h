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
        Teacher(string first_name, string last_name, Date dob, string email, string phone_number, vector<Subject> subject);
        Teacher(long id, string first_name, string last_name, Date dob, string email, string phone_number, vector<Subject> subject);
        virtual ~Teacher();

        vector<Subject> Getsubject() { return subject; }
        void Setsubject(vector<Subject> val) { subject = val; }

    protected:

    private:
        vector<Subject> subject;
};

#endif // TEACHER_H
