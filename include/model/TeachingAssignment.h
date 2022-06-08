#ifndef TEACHINGASSIGNMENT_H
#define TEACHINGASSIGNMENT_H
#include <Subject.h>
#include <Class.h>
#include <Teacher.h>

class TeachingAssignment
{
    public:
        TeachingAssignment();
        TeachingAssignment(long id, Subject subject, Class clazz, Teacher teacher);
        TeachingAssignment(Subject subject, Class clazz, Teacher teacher);
        virtual ~TeachingAssignment();

        Subject Getsubject() { return subject; }
        void Setsubject(Subject val) { subject = val; }
        Class Getclazz() { return clazz; }
        void Setclazz(Class val) { clazz = val; }
        Teacher Getteacher() { return teacher; }
        void Setteacher(Teacher val) { teacher = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }

    protected:

    private:
        Subject subject;
        Class clazz;
        Teacher teacher;
        long id;
};

#endif // TEACHINGASSIGNMENT_H
