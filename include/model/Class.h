#ifndef CLASS_H
#define CLASS_H
#include <string>
using namespace std;

class Class
{
    public:
        Class();
        Class(long, int, string);
        Class(int, string);
        virtual ~Class();

        int Getlevel() { return level; }
        void Setlevel(int val) { level = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }

    protected:

    private:
        long id;
        int level;
        string name;
        int year;
};

#endif // CLASS_H
