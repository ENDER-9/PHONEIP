#include "database.h"
#include <iostream>

void Database::openDb(const char* fileName) {
    rc = sqlite3_open(fileName, &db);
    if(rc != SQLITE_OK) {
        std::cout << "Error opening database" << sqlite3_errmsg (db) << std::endl;
    }
}

void Database::closeDb() {
    sqlite3_close(db);
}

void Database::createTable() {
    openDb(fileName);
    rc = sqlite3_exec(db,
                     "CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, FirstName TEXT NOT NULL, LastName TEXT NOT NULL, Birthday TEXT NOT NULL, "
                       "PhoneNumber TEXT NOT NULL, Street TEXT NOT NULL, City TEXT NOT NULL, Postcode INT NOT NULL)",
                       NULL, 0, NULL);
    if(rc != SQLITE_OK) {
        std::cout << "Error creating table" << sqlite3_errmsg(db);
        closeDb();
    }
    closeDb();
}

std::string Database::addPerson (Person person) {

}

std::string Database::deletePerson (std::string firstName, std::string lastName) {

}

std::string Database::modifyPerson (Person person){

}

//Methods for returning single information
const std::string Database::getFirstName (std::string firstName, std::string lastName){

}
const std::string Database::getLastName (std::string firstName, std::string lastName){

}
const std::string Database::getBirthday (std::string firstName, std::string lastName){

}
const std::string Database::getPhoneNumber (std::string firstName, std::string lastName){

}
const std::string Database::getStreet (std::string firstName, std::string lastName){

}
const std::string Database::getCity (std::string firstName, std::string lastName){

}
const int Database::getPostcode (std::string firstName, std::string lastName){

}
