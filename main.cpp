#include <iostream>
#include <Logger.h>
#include <MainView.h>
#include <Month.h>
using namespace std;

int main()
{
    Logger *LOGGER = Logger::Getinstance();
    LOGGER->info("Application started.");
    MainView::MainMenu();
    LOGGER->info("Application is closing.");
    return 0;
}
