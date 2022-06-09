#ifndef SUBJECTDAO_H
#define SUBJECTDAO_H
#include <sqlite3.h>
#include <Logger.h>
using namespace std;

class SubjectDao
{
    public:
        virtual ~SubjectDao();
        SubjectDao *Getinstance();

    protected:

    private:
        SubjectDao();
        static SubjectDao *instance;
        sqlite3* initDBConn();
};

#endif // SUBJECTDAO_H
