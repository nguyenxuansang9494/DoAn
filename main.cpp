#include <iostream>
#include <Logger.h>
#include <SubjectDao.h>
#include <TeacherDao.h>
#include <ClassDao.h>
#include <StudentDao.h>
#include <Date.h>
#include <Month.h>
using namespace std;

int main()
{
    Logger *LOGGER = Logger::Getinstance();
    SubjectDao *subject_dao = SubjectDao::Getinstance();
    TeacherDao *teacher_dao = TeacherDao::Getinstance();
    ClassDao *class_dao = ClassDao::Getinstance();
    StudentDao *student_dao = StudentDao::Getinstance();
    LOGGER->info("Application started.");
    ArrayList<Student> list = student_dao->GetAll();
    LOGGER->info("Application is closing.");
    return 0;
}
