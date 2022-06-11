#include <TeacherDao.h>

TeacherDao *TeacherDao::instance = nullptr;
namespace TeacherDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();
}

TeacherDao::TeacherDao()
{
    this->subjectDao = SubjectDao::Getinstance();
    try
    {
        this->db = InitDBConn();
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        TeacherDaoLogger::LOGGER->error("Database connection failure - class TeacherDao");
    }
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

void TeacherDao::CreateOne(Teacher teacher)
{
    sqlite3_stmt *stmt = nullptr;
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

ArrayList<Teacher> TeacherDao::GetAll()
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Teacher> result = ArrayList<Teacher>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM teacher", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(
            Teacher(
                sqlite3_column_int(stmt, 0),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))),
                Date(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)))),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))),
                *(subjectDao->GetById(sqlite3_column_int(stmt, 6)))));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}

Teacher *TeacherDao::GetById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    Teacher *result = nullptr;
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM teacher WHERE id = ?", -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        result = new Teacher(
            sqlite3_column_int(stmt, 0),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))),
            Date(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)))),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))),
            *(subjectDao->GetById(sqlite3_column_int(stmt, 6))));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}

void TeacherDao::RemoveById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "DELETE FROM teacher WHERE id = ?", -1, &stmt, 0);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void TeacherDao::UpdateById(int id, Teacher teacher)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "UPDATE teacher SET first_name = ?, last_name = ?, dob = ?, email = ?, phone_number = ?, subject_id = ? WHERE id = ?", -1, &stmt, 0);
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
    sqlite3_bind_int(stmt, 7, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
}
