#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
using namespace std;


class Subject
{
    public:
        Subject();
        Subject(string, int);
        virtual ~Subject();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        int Getgrade() { return grade; }
        void Setgrade(int val) { grade = val; }

    protected:

    private:
        string name;
        int grade;
};

#endif // SUBJECT_H
