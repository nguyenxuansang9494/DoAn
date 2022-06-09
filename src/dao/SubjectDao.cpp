#include "SubjectDao.h"

SubjectDao* SubjectDao::instance = nullptr;
Logger *LOGGER = Logger::Getinstance();

SubjectDao::SubjectDao()
{
}

SubjectDao::~SubjectDao()
{
}

SubjectDao* SubjectDao::Getinstance() {
    if (instance == nullptr)
        instance = new SubjectDao();
    return instance;
}

sqlite3* SubjectDao::initDBConn() {
    sqlite3 *db;
    int rc = sqlite3_open("skulman.db", &db);
    if ( rc != 0 ) {
        LOGGER->error("Can not connect to Database.");
        throw runtime_error("can not connect to database.");
    }
    LOGGER->info("Connect to db success.");
    return db;
}