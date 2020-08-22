#ifndef DATABASE_H
#define DATABASE_H
#include "person.h"
#include <nlohmann/json.hpp>
#include <sqlite3.h>
#include <string>
#include <vector>


class Database {

    public:
    Database (const char* fileName, sqlite3 *db) : fileName (fileName), db(db) {
    }

    void openDb (const char* dbName);
    void closeDb ();
    void createTable ();
    std::string addPerson (Person person);
    std::string deletePerson (std::string firstName, std::string lastName);
    std::string modifyPerson (Person person);
    const nlohmann::json getPersonInformation (std::string firstName, std::string lastName);

    private:
    sqlite3* db;
    int rc = 0;
    const char* fileName;
};


#endif