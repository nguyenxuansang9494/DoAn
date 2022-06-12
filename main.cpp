#include <iostream>
#include <Logger.h>
#include <SubjectDao.h>
#include <TeacherDao.h>
#include <ClassDao.h>
#include <StudentDao.h>
#include <MarkDao.h>
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
    MarkDao *mark_dao = MarkDao::Getinstance();
    LOGGER->info("Application started.");
    Student *student = student_dao->GetById(3);
    Class *clazz = class_dao->GetById(2);
    Subject *toan = subject_dao->GetById(2);
    Subject *hoa = subject_dao->GetById(6);
    Mark marktoan(*student, *clazz, *toan, 10);
    Mark markhoa(*student, *clazz, *hoa, 10);
    mark_dao->RemoveByStudentAndSubjectIdAndClassId(student->Getid(), hoa->Getid(), clazz->Getid());
    LOGGER->info("Application is closing.");
    return 0;
}
