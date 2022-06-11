#ifndef STUDENT_H
#define STUDENT_H

#include <Person.h>
#include <Class.h>
#include <string>
#include <vector>
using namespace std;


class Student : public Person
{
    public:
        Student();
        Student(string first_name, string last_name, Date dob, string email, string phone_number, Class clazz);
        Student(long id, string first_name, string last_name, Date dob, string email, string phone_number, Class clazz);
        virtual ~Student();
        Class Getstudentclass() { return student_class; }
        void Setstudentclass(Class val) { student_class = val; }

    protected:

    private:
        Class student_class;
};

#endif // STUDENT_H
