#ifndef MARKVIEW_H
#define MARKVIEW_H
#include <iostream>
#include <MarkDao.h>
using namespace std;

namespace MarkView {
    void MarkMenu();
    void ShowAllStudentMark();
    void ShowAllStudentSubjectMark();
    void ShowAllStudentSubjectClassMark();
    void CreateMark();
    void UpdateMark();
    void RemoveMark();
}

#endif