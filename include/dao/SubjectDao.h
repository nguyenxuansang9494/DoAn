#ifndef SUBJECTDAO_H
#define SUBJECTDAO_H
#include <sqlite3.h>
#include <Logger.h>
#include <Subject.h>
#include <string>
#include <DatabaseUtil.h>
#include <ArrayList.h>
#include <AbstractDao.h>
using namespace std;

class SubjectDao: public AbstractDao<Subject> 
{
    public:
        virtual ~SubjectDao();
        static SubjectDao *Getinstance();
        void CreateOne(Subject subject);
        ArrayList<Subject> GetAll();
        Subject *GetById(int id);
        void RemoveById(int id);
        void UpdateById(int id, Subject subject);
    protected:

    private:
        SubjectDao();
        static SubjectDao *instance;
        sqlite3 *db;
};

#endif // SUBJECTDAO_H
