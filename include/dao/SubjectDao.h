#ifndef SUBJECTDAO_H
#define SUBJECTDAO_H
#include <sqlite3.h>
#include <Logger.h>
#include <Subject.h>
#include <string>
#include <DatabaseUtil.h>

using namespace std;

class SubjectDao
{
    public:
        virtual ~SubjectDao();
        static SubjectDao *Getinstance();
        void CreateNewSubject(Subject subject);
    protected:

    private:
        SubjectDao();
        static SubjectDao *instance;
};

#endif // SUBJECTDAO_H
