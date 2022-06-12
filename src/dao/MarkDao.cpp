#include <MarkDao.h>

MarkDao *MarkDao::instance = nullptr;

namespace MarkDaoLogger
{
    Logger *LOGGER = Logger::Getinstance();
}

MarkDao::MarkDao()
{
    student_dao = StudentDao::Getinstance();
    class_dao = ClassDao::Getinstance();
    subject_dao = SubjectDao::Getinstance();
    try
    {
        this->db = InitDBConn();
    }
    catch (const DatabaseConnectionFailedException &e)
    {
        MarkDaoLogger::LOGGER->error("Database connection failure - class ClassDao");
    }
}

MarkDao::~MarkDao()
{
}

MarkDao *MarkDao::Getinstance()
{
    if (MarkDao::instance != nullptr)
        return instance;
    instance = new MarkDao();
    return instance;
}

void MarkDao::CreateOne(Mark mark)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "INSERT INTO mark (student_id, class_id, subject_id, val) VALUES(?,?,?,?)", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, mark.Getstudent().Getid());
    sqlite3_bind_int(stmt, 2, mark.Getclazz().Getid());
    sqlite3_bind_int(stmt, 3, mark.Getsubject().Getid());
    sqlite3_bind_double(stmt, 4, mark.Getvalue());
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

ArrayList<Mark> MarkDao::GetAll()
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Mark> result = ArrayList<Mark>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM mark", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(Mark(
            sqlite3_column_int(stmt, 0),
            *(student_dao->GetById(sqlite3_column_int(stmt, 1))),
            *(class_dao->GetById(sqlite3_column_int(stmt, 2))),
            *(subject_dao->GetById(sqlite3_column_int(stmt, 3))),
            sqlite3_column_double(stmt, 4)));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

ArrayList<Mark> MarkDao::GetAllByStudentId(int id)
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Mark> result = ArrayList<Mark>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM mark WHERE student_id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(Mark(
            sqlite3_column_int(stmt, 0),
            *(student_dao->GetById(sqlite3_column_int(stmt, 1))),
            *(class_dao->GetById(sqlite3_column_int(stmt, 2))),
            *(subject_dao->GetById(sqlite3_column_int(stmt, 3))),
            sqlite3_column_double(stmt, 4)));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

ArrayList<Mark> MarkDao::GetAllByStudentAndSubjectId(int student_id, int subject_id)
{
    sqlite3_stmt *stmt = nullptr;
    ArrayList<Mark> result = ArrayList<Mark>();
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM mark WHERE student_id = ? AND subject_id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, student_id);
    sqlite3_bind_int(stmt, 2, subject_id);
    for (int i = 0; sqlite3_step(stmt) == SQLITE_ROW; i++)
    {
        result.add(Mark(
            sqlite3_column_int(stmt, 0),
            *(student_dao->GetById(sqlite3_column_int(stmt, 1))),
            *(class_dao->GetById(sqlite3_column_int(stmt, 2))),
            *(subject_dao->GetById(sqlite3_column_int(stmt, 3))),
            sqlite3_column_double(stmt, 4)));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

Mark *MarkDao::GetByStudentAndSubjectIdAndClassId(int student_id, int subject_id, int class_id)
{
    sqlite3_stmt *stmt = nullptr;
    Mark *result = nullptr;
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM mark WHERE student_id = ? AND subject_id = ? AND class_id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, student_id);
    sqlite3_bind_int(stmt, 2, subject_id);
    sqlite3_bind_int(stmt, 3, class_id);
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        result = new Mark(
            sqlite3_column_int(stmt, 0),
            *(student_dao->GetById(sqlite3_column_int(stmt, 1))),
            *(class_dao->GetById(sqlite3_column_int(stmt, 2))),
            *(subject_dao->GetById(sqlite3_column_int(stmt, 3))),
            sqlite3_column_double(stmt, 4));
    }
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
    return result;
}

void MarkDao::RemoveByStudentAndSubjectIdAndClassId(int student_id, int subject_id, int class_id)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "DELETE FROM mark WHERE student_id = ? AND subject_id = ? AND class_id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_int(stmt, 1, student_id);
    sqlite3_bind_int(stmt, 2, subject_id);
    sqlite3_bind_int(stmt, 3, class_id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}

void MarkDao::UpdateByStudentAndSubjectIdAndClassId(int student_id, int subject_id, int class_id, float mark)
{
    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, "UPDATE mark SET val = ? WHERE student_id = ? AND subject_id = ? AND class_id = ?", -1, &stmt, nullptr);
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    sqlite3_bind_double(stmt, 1, mark);
    sqlite3_bind_int(stmt, 2, student_id);
    sqlite3_bind_int(stmt, 3, subject_id);
    sqlite3_bind_int(stmt, 4, class_id);
    sqlite3_step(stmt);
    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
    rc = sqlite3_finalize(stmt);
}
