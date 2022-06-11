#ifndef TEACHERDAO_H
#define TEACHERDAO_H
#include <sqlite3.h>
#include <Logger.h>
#include <Teacher.h>
#include <string>
#include <DatabaseUtil.h>
#include <ArrayList.h>
#include <SubjectDao.h>

using namespace std;

class TeacherDao: public AbstractDao<Teacher>
{
    public:
        virtual ~TeacherDao();
        static TeacherDao *Getinstance();
        void CreateOne(Teacher teacher);
        ArrayList<Teacher> GetAll();
        Teacher *GetById(int id);
        void RemoveById(int id);
        void UpdateById(int id, Teacher teacher);
    protected:

    private:
        TeacherDao();
        static TeacherDao *instance;
        SubjectDao *subjectDao;
        sqlite3 *db;
};

#endif // TEACHERDAO_H
