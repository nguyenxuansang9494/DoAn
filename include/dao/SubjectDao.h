#ifndef SUBJECTDAO_H
#define SUBJECTDAO_H
#include <sqlite3.h>
#include <Logger.h>
#include <Subject.h>
#include <string>
#include <DatabaseUtil.h>
#include <ArrayList.h>
using namespace std;

class SubjectDao
{
    public:
        virtual ~SubjectDao();
        static SubjectDao *Getinstance();
        void CreateNewSubject(Subject subject);
        ArrayList<Subject> GetAllSubjects();
        Subject *GetById(int id);
        void RemoveById(int id);
        void Update(int id, Subject subject);
    protected:

    private:
        SubjectDao();
        static SubjectDao *instance;
};

#endif // SUBJECTDAO_H
