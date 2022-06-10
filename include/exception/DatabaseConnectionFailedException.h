#ifndef DATABASECONNECTIONFAILEDEXCETION_H
#define DATABASECONNECTIONFAILEDEXCETION_H
#include <exception>
#include <string>
using namespace std;

class DatabaseConnectionFailedException: public exception
{
private:
    string message;
public:
    string Getmessage() {
        return message;
    }
    DatabaseConnectionFailedException(string = "Database connection failed.");
    virtual ~DatabaseConnectionFailedException();
};

#endif