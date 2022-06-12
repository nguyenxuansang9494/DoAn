#include <ClassDao.h>

ClassDao *ClassDao::instance = nullptr;

namespace ClassDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();
}

ClassDao::ClassDao()
{
    teacher_dao = TeacherDao::Getinstance();
    try
    {
        this->db = InitDBConn();
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        ClassDaoLogger::LOGGER->error("Database connection failure - class ClassDao");
    }
}

ClassDao::~ClassDao()
{
}

ClassDao *ClassDao::Getinstance()
{
    if (ClassDao::instance != nullptr)
        return instance;
    instance = new ClassDao();
    return ClassDao::instance;
}

void ClassDao::CreateOne(Class clazz)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "INSERT INTO class (level, name, year, teacher_id) VALUES(?, ?, ?, ?) ", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, clazz.Getlevel());
    string name = clazz.Getname();
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 3, clazz.Getyear());
    sqlite3_bind_int(stmt, 4, clazz.Getteacher().Getid());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

ArrayList<Class> ClassDao::GetAll()
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Class> result = ArrayList<Class>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM class", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(Class(sqlite3_column_int(stmt, 0), string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))), sqlite3_column_int(stmt, 2), *(teacher_dao->GetById(sqlite3_column_int(stmt, 3)))));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

Class *ClassDao::GetById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    Class *clazz = nullptr;
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM class WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    if (sqlite3_step(stmt) == SQLITE_ROW)
        clazz = new Class(sqlite3_column_int(stmt, 0), sqlite3_column_int(stmt, 1), string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))), sqlite3_column_int(stmt, 3), *(teacher_dao->GetById(sqlite3_column_int(stmt, 4))));
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return clazz;
}

void ClassDao::RemoveById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "DELETE FROM class WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

void ClassDao::UpdateById(int id, Class clazz)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "UPDATE subject SET level = ?, name = ?, year = ?, teacher_id = ? WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, clazz.Getlevel());
    string name = clazz.Getname();
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 3, clazz.Getyear());
    sqlite3_bind_int(stmt, 4, clazz.Getteacher().Getid());
    sqlite3_bind_int(stmt, 5, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

