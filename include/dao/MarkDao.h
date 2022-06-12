#ifndef MARKDAO_H
#define MARKDAO_H
#include <StudentDao.h>
#include <ClassDao.h>
#include <SubjectDao.h>
#include <Mark.h>

class MarkDao
{
private:
    StudentDao *student_dao;
    ClassDao *class_dao;
    SubjectDao *subject_dao;
    MarkDao();
    static MarkDao *instance;
    sqlite3 *db;


public:
    ~MarkDao();
    static MarkDao *Getinstance();
    void CreateOne(Mark mark);
    ArrayList<Mark> GetAll();
    ArrayList<Mark> GetAllByStudentId(int id);
    ArrayList<Mark> GetAllByStudentAndSubjectId(int student_id, int subject_id);
    Mark *GetByStudentAndSubjectIdAndClassId(int student_id, int subject_id, int class_id);
    void RemoveByStudentAndSubjectIdAndClassId(int student_id, int subject_id, int class_id);
    void UpdateByStudentAndSubjectIdAndClassId(int student_id, int subject_id, int class_id, float mark);    
};

#endif