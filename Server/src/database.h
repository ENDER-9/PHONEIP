#ifndef DATABASE_H
#define DATABASE_H
#include <sqlite3.h>
#include <string>
#include "person.h"


class Database {

    public:

    Database(const char* fileName) : fileName(fileName) {

    }

    void openDb (const char* dbName);
    void closeDb ();
    void createTable();
    std::string addPerson (Person person);
    std::string deletePerson (std::string firstName, std::string lastName);
    std::string modifyPerson (Person person);
    const std::string getFirstName (std::string firstName, std::string lastName);
    const std::string getLastName (std::string firstName, std::string lastName);
    const std::string getBirthday (std::string firstName, std::string lastName);
    const std::string getPhoneNumber (std::string firstName, std::string lastName);
    const std::string getStreet (std::string firstName, std::string lastName);
    const std::string getCity (std::string firstName, std::string lastName);
    const int getPostcode (std::string firstName, std::string lastName);

    private:
    sqlite3* db;
    int rc = 0;
    const char* fileName;
};

#endif