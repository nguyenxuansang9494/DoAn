#ifndef STUDENTDAO_H
#define STUDENTDAO_H
#include <Student.h>
#include <AbstractDao.h>
#include <sqlite3.h>
#include <ClassDao.h>

class StudentDao: public AbstractDao<Student>
{
private:
    ClassDao *class_dao;
    StudentDao();
    static StudentDao *instance;
    sqlite3 *db;

public:
    ~StudentDao();
    static StudentDao *Getinstance();
    void CreateOne(Student clazz);
    ArrayList<Student> GetAll();
    Student *GetById(int id);
    void RemoveById(int id);
    void UpdateById(int id, Student Clazz);
};

#endif