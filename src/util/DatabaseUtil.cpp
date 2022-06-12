#include <DatabaseUtil.h>

Logger *LOGGER = Logger::Getinstance();

sqlite3 *globaldb = nullptr;
sqlite3 *std::InitDBConn()
{
    if (globaldb != nullptr)
        return globaldb;
    string dbfile = getenv("HOME");
    dbfile.append("/.skulman/db/skulman.db");
    int rc = sqlite3_open_v2(dbfile.c_str(), &globaldb, SQLITE_OPEN_READWRITE, nullptr);
    if (rc != 0)
    {
        LOGGER->error("Database connection failed.");
        throw DatabaseConnectionFailedException();
    }
    LOGGER->info("Connect to db success.");
    return globaldb;
}