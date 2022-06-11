#include <TeacherDao.h>

TeacherDao *TeacherDao::instance = nullptr;
namespace TeacherDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();    
}


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
        TeacherDaoLogger::LOGGER->error("Can not create new subject due to database connection failure.");
    }
    int rc = sqlite3_prepare_v2(db, "INSERT INTO teacher (first_name, last_name, dob, email, phone_number, subject_id) VALUES(?, ?, ?, ?, ?, ?) ", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    string first_name = teacher.Getfirst_name();
    
    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, nullptr);
    string last_name = teacher.Getlast_name();
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, nullptr);
    string dob = teacher.Getdob().tostring();
    sqlite3_bind_text(stmt, 3, dob.c_str(), -1, nullptr);
    string email = teacher.Getemail();
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, nullptr);
    string phone_number = teacher.Getphone_number();
    sqlite3_bind_text(stmt, 5, phone_number.c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 6, teacher.Getsubject().Getid());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
}

