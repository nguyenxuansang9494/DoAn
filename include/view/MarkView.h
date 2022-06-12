#ifndef MARKVIEW_H
#define MARKVIEW_H
#include <iostream>
#include <MarkDao.h>
using namespace std;

namespace MarkView {
    void MarkMenu();
    void ShowAllMark();
    void ShowAllStudentMark();
    void ShowAllStudentSubjectMark();
    void ShowAStudentSubjectClassMark();
    void CreateMark();
    void UpdateMark();
    void RemoveMark();
}

#endif