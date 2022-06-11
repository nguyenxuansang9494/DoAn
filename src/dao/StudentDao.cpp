#include <StudentDao.h>

StudentDao *StudentDao::instance = nullptr;

namespace StudentDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();
}

StudentDao::StudentDao()
{
    class_dao = ClassDao::Getinstance();
    try
    {
        this->db = InitDBConn();
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        StudentDaoLogger::LOGGER->error("Database connection failure - class StudentDao");
    }
}

StudentDao::~StudentDao()
{
}

StudentDao *StudentDao::Getinstance()
{
    if (StudentDao::instance != nullptr)
        return instance;
    instance = new StudentDao();
    return StudentDao::instance;
}

void StudentDao::CreateOne(Student student)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "INSERT INTO student (first_name, last_name, dob, email, phone_number, class_id) VALUES(?, ?, ?, ?, ?, ?) ", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    string first_name = student.Getfirst_name();
    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, nullptr);
    string last_name = student.Getlast_name();
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, nullptr);
    string dob = student.Getdob().tostring();
    sqlite3_bind_text(stmt, 3, dob.c_str(), -1, nullptr);
    string email = student.Getemail();
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, nullptr);
    string phone_number = student.Getphone_number();
    sqlite3_bind_text(stmt, 5, phone_number.c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 6, student.Getstudentclass().Getid());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

ArrayList<Student> StudentDao::GetAll()
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Student> result = ArrayList<Student>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM student", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(
            Student(
                sqlite3_column_int(stmt, 0),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))),
                Date(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)))),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))),
                string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))),
                *(class_dao->GetById(sqlite3_column_int(stmt, 6)))));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

Student *StudentDao::GetById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    Student *result = nullptr;
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM student WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        result = new Student(
            sqlite3_column_int(stmt, 0),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))),
            Date(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)))),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))),
            string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))),
            *(class_dao->GetById(sqlite3_column_int(stmt, 6))));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

void StudentDao::RemoveById(int id)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "DELETE FROM student WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

void StudentDao::UpdateById(int id, Student student)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "UPDATE Student SET first_name = ?, last_name = ?, dob = ?, email = ?, phone_number = ?, class_id = ? WHERE id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    string first_name = student.Getfirst_name();
    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, nullptr);
    string last_name = student.Getlast_name();
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, nullptr);
    string dob = student.Getdob().tostring();
    sqlite3_bind_text(stmt, 3, dob.c_str(), -1, nullptr);
    string email = student.Getemail();
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, nullptr);
    string phone_number = student.Getphone_number();
    sqlite3_bind_text(stmt, 5, phone_number.c_str(), -1, nullptr);
    sqlite3_bind_int(stmt, 6, student.Getstudentclass().Getid());
    sqlite3_bind_int(stmt, 7, id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}
