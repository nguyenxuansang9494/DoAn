#ifndef SUBJECTDAO_H
#define SUBJECTDAO_H
#include <sqlite3.h>
#include <Logger.h>
#include <Subject.h>
#include <DatabaseConnectionFailedException.h>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
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
        void InitDBConn(sqlite3*&);
};

#endif // SUBJECTDAO_H
