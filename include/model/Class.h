#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <Teacher.h>
using namespace std;

class Class
{
    public:
        Class();
        Class(long, int, string, Teacher);
        Class(int, string, Teacher);
        virtual ~Class();

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
