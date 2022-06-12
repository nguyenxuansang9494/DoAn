#ifndef TEACHERVIEW_H
#define TEACHERVIEW_H
#include <iostream>
#include <TeacherDao.h>
using namespace std;

namespace TeacherView {
    void TeacherMenu();
    void ShowAllTeacher();
    void ShowATeacher();
    void CreateTeacher();
    void UpdateTeacher();
    void RemoveTeacher();
}

#endif