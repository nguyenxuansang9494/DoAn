#ifndef SUBJECTVIEW_H
#define SUBJECTVIEW_H
#include <iostream>
#include <SubjectDao.h>
using namespace std;

namespace SubjectView {
    void SubjectMenu();
    void ShowAllSubject();
    void ShowASubject();
    void CreateSubject();
    void UpdateSubject();
    void RemoveSubject();
}

#endif