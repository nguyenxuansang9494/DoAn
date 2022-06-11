#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <Teacher.h>
using namespace std;

class Class
{
    public:
        Class();
        Class(long, int, string, int, Teacher);
        Class(int, string, int, Teacher);
        virtual ~Class();

        int Getyear() { return year; }
        void Setyear(int val) { year = val; }
        int Getlevel() { return level; }
        void Setlevel(int val) { level = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }
        Teacher Getteacher() { return teacher; }
        void Setteacher(Teacher val) { teacher = val; }

    protected:

    private:
        long id;
        int level;
        string name;
        int year;
        Teacher teacher;
};

#endif // CLASS_H
