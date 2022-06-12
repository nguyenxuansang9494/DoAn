#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H
#include <iostream>
#include <StudentDao.h>
using namespace std;

namespace StudentView {
    void StudentMenu();
    void ShowAllStudent();
    void ShowAStudent();
    void CreateStudent();
    void UpdateStudent();
    void RemoveStudent();
}

#endif