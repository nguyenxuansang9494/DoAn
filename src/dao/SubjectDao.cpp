#include "SubjectDao.h"

SubjectDao *SubjectDao::instance = nullptr;
Logger *LOGGER = Logger::Getinstance();

SubjectDao::SubjectDao()
{
}

SubjectDao::~SubjectDao()
{
}

SubjectDao *SubjectDao::Getinstance()
{
    if (instance == nullptr)
        instance = new SubjectDao();
    return instance;
}

void SubjectDao::CreateNewSubject(Subject subject)
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    try
    {
        InitDBConn(db);
    }
    catch (const std::exception &e)
    {
        LOGGER->error("Can not create new subject due to database connection failure.");
    }
    int rc = sqlite3_prepare_v2(db, "INSERT INTO subject (name, grade) VALUES(?, ?) ", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_text(stmt, 1, subject.Getname().c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 2, subject.Getgrade());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
}

