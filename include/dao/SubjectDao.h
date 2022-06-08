#ifndef SUBJECTDAO_H
#define SUBJECTDAO_H
#include <sqlite3.h>

class SubjectDao
{
    public:
        SubjectDao();
        virtual ~SubjectDao();
        void initConnection(sqlite3 *&db, int &rc);

    protected:

    private:
};

#endif // SUBJECTDAO_H
