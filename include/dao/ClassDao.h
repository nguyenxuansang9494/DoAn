#ifndef CLASSDAO_H
#define CLASSDAO_H
#include <AbstractDao.h>
#include <Class.h>
#include <TeacherDao.h>
#include <DatabaseUtil.h>

class ClassDao : public AbstractDao<Class>
{
private:
    TeacherDao *teacher_dao;
    ClassDao();
    static ClassDao *instance;
    sqlite3 *db;

public:
    virtual ~ClassDao();
    static ClassDao *Getinstance();
    void CreateOne(Class clazz);
    ArrayList<Class> GetAll();
    Class *GetById(int id);
    void RemoveById(int id);
    void UpdateById(int id, Class Clazz);
};

#endif