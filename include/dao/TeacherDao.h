#ifndef TEACHERDAO_H
#define TEACHERDAO_H
#include <sqlite3.h>
#include <Logger.h>
#include <Teacher.h>
#include <string>
#include <DatabaseUtil.h>

using namespace std;

class TeacherDao
{
    public:
        virtual ~TeacherDao();
        static TeacherDao *Getinstance();
        void CreateNewTeacher(Teacher teacher);
    protected:

    private:
        TeacherDao();
        static TeacherDao *instance;
};

#endif // TEACHERDAO_H
