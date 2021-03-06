#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
using namespace std;


class Subject
{
    public:
        Subject();
        Subject(long, string, int);
        Subject(string, int);
        virtual ~Subject();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        int Getgrade() { return grade; }
        void Setgrade(int val) { grade = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }

    protected:

    private:
        long id;
        string name;
        int grade;
};

#endif // SUBJECT_H
