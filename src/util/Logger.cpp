#include "Logger.h"
Logger* Logger::instance = nullptr;

Logger::Logger()
{
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    string env_home = getenv("HOME");
    string logfolder = env_home.append("./skulman");
    string logfile = logfolder.append("/log").append(asctime(curtime)).append(".log");
    mkdir(logfolder.c_str(), 0775);
    this->logfile.open(logfile.c_str());
}

Logger::~Logger()
{
    this->logfile.close();
}

Logger* Logger::Getinstance() {
    if (instance == nullptr)
        instance = new Logger();
    return instance;
}