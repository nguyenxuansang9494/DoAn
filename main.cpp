#include <iostream>
#include <Logger.h>
#include <Subject.h>
#include <SubjectDao.h>
using namespace std;

int main()
{
    Logger *LOGGER = Logger::Getinstance();
    SubjectDao *subject_dao = SubjectDao::Getinstance();
    LOGGER->info("Application started."); 
    cout << "Hello world!" << endl;
    subject_dao->CreateNewSubject(Subject("Toan", 10));
    LOGGER->info("Application is closing.");
    return 0;
}
