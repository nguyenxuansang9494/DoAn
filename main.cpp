#include <iostream>
#include <Logger.h>
#include <Subject.h>
#include <SubjectDao.h>
#include <TeacherDao.h>
#include <Date.h>
#include <Month.h>
using namespace std;

int main()
{
    Logger *LOGGER = Logger::Getinstance();
    SubjectDao *subject_dao = SubjectDao::Getinstance();
    TeacherDao *teacher_dao = TeacherDao::Getinstance();
    LOGGER->info("Application started."); 
    cout << "Hello world!" << endl;
    subject_dao->RemoveById(4);
    LOGGER->info("Application is closing.");
    return 0;
}
