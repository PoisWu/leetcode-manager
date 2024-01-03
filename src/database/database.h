# ifndef DATABASE_H
# define DATABASE_H
# include <sqlite3.h>
# include <string>

using namespace std;

class Database{
// private:
public:
    sqlite3 *db;
    static const char* db_path;
    static const char* leetcodeurl;



    // callback function for sqlite3
    static int callback(void *, int , char **, char **);
    // Create database table if the table doesn't exist
    void createTable();

    // Download all problems
    void downloadProblems();



// public: 
    Database();
    ~Database();
    string getTitle(int frontid);


};

# endif
