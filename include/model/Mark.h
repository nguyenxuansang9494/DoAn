#ifndef MARK_H
#define MARK_H
#include <Student.h>
#include <Class.h>
#include <Subject.h>

class Mark
{
    public:
        Mark();
        Mark(Student, Class, Subject, float);
        Mark(long, Student, Class, Subject, float);
        virtual ~Mark();

        Student Getstudent() { return student; }
        void Setstudent(Student val) { student = val; }
        Class Getclazz() { return clazz; }
        void Setclazz(Class val) { clazz = val; }
        Subject Getsubject() { return subject; }
        void Setsubject(Subject val) { subject = val; }
        float Getvalue() { return value; }
        void Setvalue(float val) { value = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }

    protected:

    private:
        long id;
        Student student;
        Class clazz;
        Subject subject;
        float value;
};

#endif // MARK_H
