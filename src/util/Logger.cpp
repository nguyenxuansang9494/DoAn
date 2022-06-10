#include "Logger.h"
Logger* Logger::instance = nullptr;

Logger::Logger()
{
    char timestr[20];
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    string env_home = getenv("HOME");
    string logfolder = env_home.append("/.skulman");
    mkdir(logfolder.c_str(), 0775);
    strftime(timestr, 50, "%m-%d-%Y_%H:%M:%S", curtime);
    logfolder.append("/log-").append(timestr).append(".log");
    this->logfile.open(logfolder.c_str());
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

void Logger::info(string ch)
{
    char timestr[20];
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    strftime(timestr, 50, "%m-%d-%Y %H:%M:%S", curtime);
    logfile << timestr << " - " << "INFO : " << ch << endl;
}

void Logger::error(string ch)
{
    char timestr[20];
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    strftime(timestr, 50, "%m-%d-%Y %H:%M:%S", curtime);
    logfile << timestr << " - " << "ERROR : " << ch << endl;
}

void Logger::warn(string ch)
{
    char timestr[20];
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    strftime(timestr, 50, "%m-%d-%Y %H:%M:%S", curtime);
    logfile << timestr << " - " << "WARN : " << ch << endl;
}
