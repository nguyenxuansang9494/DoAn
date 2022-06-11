#include <iostream>
#include <Logger.h>
#include <Subject.h>
#include <SubjectDao.h>
#include <TeacherDao.h>
#include <ClassDao.h>
#include <Date.h>
#include <Month.h>
using namespace std;

int main()
{
    Logger *LOGGER = Logger::Getinstance();
    SubjectDao *subject_dao = SubjectDao::Getinstance();
    TeacherDao *teacher_dao = TeacherDao::Getinstance();
    ClassDao *class_dao = ClassDao::Getinstance();
    LOGGER->info("Application started."); 
    Teacher *teacher = teacher_dao->GetById(3);
    Class clazz = Class(11, "A5", 2011, *teacher);
    // class_dao->RemoveById(1);
    class_dao->CreateOne(clazz);
    LOGGER->info("Application is closing.");
    return 0;
}
