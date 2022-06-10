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

void Logger::info(string ch)
{
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    logfile << asctime(curtime) << " - " << "INFO : " << ch << endl;
}

void Logger::error(string ch)
{
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    logfile << asctime(curtime) << " - " << "ERROR : " << ch << endl;
}

void Logger::warn(string ch)
{
    time_t _tm =time(NULL);
    struct tm * curtime = localtime ( &_tm );
    logfile << asctime(curtime) << " - " << "WARN : " << ch << endl;
}
