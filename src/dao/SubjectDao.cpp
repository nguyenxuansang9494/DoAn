#include "SubjectDao.h"

SubjectDao *SubjectDao::instance = nullptr;
namespace SubjectDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();
}

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
    catch (const DatabaseConnectionFailedException &e)
    {
        SubjectDaoLogger::LOGGER->error("Can not create new subject due to database connection failure - class SubjectDao - method CreateNewSubject");
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

ArrayList<Subject> SubjectDao::GetAllSubjects()
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    try
    {
        InitDBConn(db);
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        SubjectDaoLogger::LOGGER->error("Can not create new subject due to database connection failure - class SubjectDao - method GetAllSubjects");
    }
    int rc = sqlite3_prepare_v2(db, "SELECT count(*) FROM subject", -1, &stmt, 0);
    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW)
        count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    ArrayList<Subject> result = ArrayList<Subject>(count);
    rc = sqlite3_prepare_v2(db, "SELECT * FROM subject", -1, &stmt, 0);
    for (int i = 0; i < count && sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(Subject(sqlite3_column_int(stmt, 0), string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))), sqlite3_column_int(stmt, 1)));
    }
    sqlite3_close(db);
    return result;
}

Subject* SubjectDao::GetById(int id)
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    try
    {
        InitDBConn(db);
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        SubjectDaoLogger::LOGGER->error("Can not create new subject due to database connection failure - class SubjectDao - method GetAllSubjects");
    }
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM subject WHERE id = ?", -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
    if (sqlite3_step(stmt) == SQLITE_ROW)
        return new Subject(sqlite3_column_int(stmt, 0), string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))), sqlite3_column_int(stmt, 1));
    sqlite3_close(db);
    return nullptr;
}

void SubjectDao::RemoveById(int id)
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    try
    {
        InitDBConn(db);
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        SubjectDaoLogger::LOGGER->error("Can not create new subject due to database connection failure - class SubjectDao - method GetAllSubjects");
    }
    int rc = sqlite3_prepare_v2(db, "DELETE  FROM subject WHERE id = ?", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_close(db);
}

void SubjectDao::Update(int id, Subject subject)
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    try
    {
        InitDBConn(db);
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        SubjectDaoLogger::LOGGER->error("Can not create new subject due to database connection failure - class SubjectDao - method GetAllSubjects");
    }
    int rc = sqlite3_prepare_v2(db, "UPDATE subject SET grade = ?, name = ? WHERE id = ?", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, subject.Getgrade());
    sqlite3_bind_text(stmt, 2, subject.Getname().c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 3, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_close(db);
}