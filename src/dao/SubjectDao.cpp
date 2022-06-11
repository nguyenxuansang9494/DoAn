#include "SubjectDao.h"

SubjectDao *SubjectDao::instance = nullptr;
namespace SubjectDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();
}

SubjectDao::SubjectDao()
{
    try
    {
        this->db = InitDBConn();
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        SubjectDaoLogger::LOGGER->error("Database connection failure - class SubjectDao");
    }
}

SubjectDao::~SubjectDao()
{
    sqlite3_close(this->db);
}

SubjectDao *SubjectDao::Getinstance()
{
    if (instance == nullptr)
        instance = new SubjectDao();
    return instance;
}

void SubjectDao::CreateOne(Subject subject)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "INSERT INTO subject (name, grade) VALUES(?, ?) ", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_text(stmt, 1, subject.Getname().c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 2, subject.Getgrade());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

ArrayList<Subject> SubjectDao::GetAll()
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Subject> result = ArrayList<Subject>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM subject", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(Subject(sqlite3_column_int(stmt, 0), string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))), sqlite3_column_int(stmt, 1)));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

Subject *SubjectDao::GetById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    Subject *result = nullptr;
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM subject WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    if (sqlite3_step(stmt) == SQLITE_ROW)
        result = new Subject(sqlite3_column_int(stmt, 0), string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))), sqlite3_column_int(stmt, 1));
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

void SubjectDao::RemoveById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "DELETE FROM subject WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

void SubjectDao::UpdateById(int id, Subject subject)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "UPDATE subject SET grade = ?, name = ? WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, subject.Getgrade());
    sqlite3_bind_text(stmt, 2, subject.Getname().c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 3, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}