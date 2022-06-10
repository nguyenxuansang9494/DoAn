#include <iostream>
#include <Logger.h>
using namespace std;

int main()
{
    Logger *LOGGER = Logger::Getinstance();
    LOGGER->info("Application started."); 
    cout << "Hello world!" << endl;
    LOGGER->info("Application is closing.");
    return 0;
}
