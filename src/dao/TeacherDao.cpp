#include <TeacherDao.h>

TeacherDao *TeacherDao::instance = nullptr;
Logger *LOGGER = Logger::Getinstance();

TeacherDao::TeacherDao()
{
}

TeacherDao::~TeacherDao()
{
}

TeacherDao *TeacherDao::Getinstance()
{
    if (instance == nullptr)
        instance = new TeacherDao();
    return instance;
}

void TeacherDao::CreateNewTeacher(Teacher teacher)
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    try
    {
        InitDBConn(db);
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        LOGGER->error("Can not create new subject due to database connection failure.");
    }
    int rc = sqlite3_prepare_v2(db, "INSERT INTO teacher (first_name, last_name, dob, email, phone_number, subject_id) VALUES(?, ?, ?, ?, ?, ?) ", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_text(stmt, 1, teacher.Getfirst_name().c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 2, teacher.Getlast_name().c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 2, teacher.Getdob().tostring().c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 2, teacher.Getemail().c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 2, teacher.Getphone_number().c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 2, teacher.Getsubject().Getid());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
}

