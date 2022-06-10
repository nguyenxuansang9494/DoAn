#include <DatabaseUtil.h>

Logger *LOGGER = Logger::Getinstance();

void std::InitDBConn(sqlite3 *&db)
{
    string dbfile = getenv("HOME");
    dbfile.append("/.skulman/db/skulman.db");
    int rc = sqlite3_open(dbfile.c_str(), &db);
    if (rc != 0)
    {
        LOGGER->error("Database connection failed.");
        throw DatabaseConnectionFailedException();
    }
    LOGGER->info("Connect to db success.");
}