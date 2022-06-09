#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

class Logger
{
    public:
        virtual ~Logger();
        static Logger* Getinstance();
        Logger(Logger &other) = delete;
        void operator=(const Logger &other) = delete;
        void info(char *ch);
        void error(char *ch);
        void warn(char *ch);
    protected:

    private:
        Logger();
        ofstream logfile;
        static Logger *instance;
};

#endif // LOGGER_H
