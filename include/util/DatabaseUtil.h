#ifndef DATABASEUTIL_H
#define DATABASEUTIL_H
#include <sqlite3.h>
#include <DatabaseConnectionFailedException.h>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <Logger.h>

namespace std
{
void InitDBConn(sqlite3*&);    
} 


#endif // DATABASEUTIL_H


