#include <stdio.h>
#include <sqlite3.h> 

// This class is to aim for dealwith access sqlite and send query data to
// leetcode 
// The function
// - Send queuries to the leetcode if missing problem data
// - Proviing an interface to queries problem data

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sqlcreate;
    char *sqlinsert;
    char *sqlselect;

    rc = sqlite3_open("~/.config/leetcodemanager/LeetCodeProblems.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlcreate = "CREATE TABLE `LeetCodeProblems` (" \ 
        "`ID` INT," \
        "`difficulty` ENUM('easy', 'medium', 'hard'),"\
        "`title` VARCHAR,"\
        "`titleSlug` VARCHAR,"\
        "PRIMARY KEY (`ID`))";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sqlcreate, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    return 0;

}

