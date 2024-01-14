#include "database/database.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string>

// This class is to aim for dealwith access sqlite and send query data to
// leetcode
// The function
// - Send queuries to the leetcode if missing problem data
// - Proviing an interface to queries problem data

using namespace std;

const char *Database::db_path =
    "/home/cheng-yen/.config/leetcodemanager/LeetCodeProblems.db";
const char *Database::leetcodeurl = "https://leetcode.com/graphql";

Database::Database()
{
    int rc = sqlite3_open(this->db_path, &this->db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(this->db));
        sqlite3_close(this->db);
        throw "Can't open database";

        // return (0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
};

Database::~Database()
{
    sqlite3_close(this->db);
}

int Database::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void Database::downloadProblems() {}

void Database::createTable()
{
    const char *sqlcreate = "CREATE TABLE `LeetCodeProblems` (" \ 
        "`ID`           INT,"
        "`difficulty`   TEXT CHECK( difficulty IN ('easy', 'medium', 'hard')),"
        "`title`        TEXT,"
        "`titleSlug`    TEXT,"
        "PRIMARY KEY (`ID`))";
    char *zErrMsg = 0;

    int rc = sqlite3_exec(this->db, sqlcreate, this->callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

string Database::getTitle(int frontid)
{
    return "hello";
}
