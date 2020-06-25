#include "database.h"
#include <iostream>

void Database::openDb(const char* fileName) {
    rc = sqlite3_open(fileName, &db);
    if(rc != SQLITE_OK) {
        std::cerr << "Error opening database" << sqlite3_errmsg (db) << std::endl;
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
        std::cerr << "Error creating table" << sqlite3_errmsg(db);
    }
    closeDb();
}

std::string Database::addPerson (Person person) {

    openDb ("fileName.db");
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2 (db, "INSERT INTO Person (FirstName, LastName, Birthday, PhoneNumber, Street, City, Postcode) VALUSE(?, ?, ?, ?, ?, ?, ?)", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg (db);
    }
    //binding the values to the parameter
    rc = sqlite3_bind_text (stmt, 1, person.getFirstName().c_str(), person.getFirstName().length (), NULL);
    rc = sqlite3_bind_text (stmt, 2, person.getLastName ().c_str (), person.getLastName ().length (), NULL);
    rc = sqlite3_bind_text (stmt, 3, person.getBirthday ().c_str (), person.getBirthday().length (), NULL);
    rc = sqlite3_bind_text (stmt, 4, person.getPhoneNumber ().c_str (), person.getPhoneNumber().length (), NULL);
    rc = sqlite3_bind_text (stmt, 5, person.getStreet ().c_str (), person.getStreet ().length (), NULL);
    rc = sqlite3_bind_text (stmt, 6, person.getCity ().c_str (), person.getCity ().length (), NULL);
    rc = sqlite3_bind_int (stmt, 7, person.getPostcode ());

    if(rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg (db);
    }
    sqlite3_step (stmt);
    sqlite3_finalize (stmt);

    closeDb ();
    return "Person added";
}

std::string Database::deletePerson (std::string firstName, std::string lastName) {
    openDb(fileName);
    sqlite3_stmt* stmt;
    //first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if(rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    //delete the Person if it is in the database
    if(sqlite3_step(stmt) == SQLITE_ROW) {
        sqlite3_stmt* deleteStmt;
        rc = sqlite3_prepare_v2 (db, "DELETE FROM Person WHERE FirstName = ? AND LastName = ?", -1, &deleteStmt, NULL);

        sqlite3_bind_text (deleteStmt, 1, firstName.c_str (), firstName.length (), NULL);
        sqlite3_bind_text (deleteStmt, 2, lastName.c_str (), lastName.length (), NULL);
        sqlite3_step (deleteStmt);
        sqlite3_finalize(deleteStmt);
        closeDb ();
        return "Person was deleted";
    }
    else {
        closeDb ();
        return "Person was not found";
    }
}

std::string Database::modifyPerson (Person person){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, person.getFirstName().c_str (), person.getFirstName().length (), NULL);
    sqlite3_bind_text (stmt, 2, person.getLastName().c_str (), person.getLastName().length (), NULL);
    // modify the Person if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        sqlite3_stmt* modifyStmt;
        rc = sqlite3_prepare_v2 (db, "UPDATE Books SET FirstName = ?, LastName = ?, Birthday = ?, PhoneNumber = ?, Street = ?, City = ?, Postcode = ? WHERE FirstName = ? OR LastName = ?",
                            -1, &modifyStmt, NULL);
        if(rc != SQLITE_OK) {
            std::cerr << "Error preparing modify statement: " << sqlite3_errmsg (db);
        }
        sqlite3_bind_text (modifyStmt, 1, person.getFirstName ().c_str (), person.getFirstName ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 2, person.getLastName ().c_str (), person.getLastName ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 3, person.getBirthday ().c_str (), person.getBirthday ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 4, person.getPhoneNumber ().c_str (), person.getPhoneNumber ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 5, person.getStreet ().c_str (), person.getStreet ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 6, person.getCity ().c_str (), person.getCity ().length (), NULL);
        sqlite3_bind_int (modifyStmt, 7, person.getPostcode ());
        sqlite3_bind_text (modifyStmt, 8, person.getFirstName ().c_str (), person.getFirstName ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 6, person.getLastName ().c_str (), person.getLastName ().length (), NULL);

        sqlite3_step (modifyStmt);
        sqlite3_finalize (modifyStmt);
        closeDb ();
        return "Person was updated";
    }
    else {
        closeDb ();
        return "Person was not found";
    }
}

//Methods for returning single information
const std::string Database::getFirstName (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        const unsigned char* returnedFirstName = sqlite3_column_text (stmt, 1);
        std::string str_returnedFirstName = reinterpret_cast<char const*> (returnedFirstName);
        closeDb ();
        return str_returnedFirstName;
    }
    else {
        closeDb ();
        return "First name was not found";
    }
}
const std::string Database::getLastName (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        const unsigned char* returnedLastName = sqlite3_column_text (stmt, 2);
        std::string str_returnedLastName = reinterpret_cast<char const*> (returnedLastName);
        closeDb ();
        return str_returnedLastName;
    }
    else {
        closeDb ();
        return "Last name was not found";
    }
}
const std::string Database::getBirthday (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        const unsigned char* returnedBirthday = sqlite3_column_text (stmt, 3);
        std::string str_returnedBirthday = reinterpret_cast<char const*> (returnedBirthday);
        closeDb ();
        return str_returnedBirthday;
    }
    else {
        closeDb ();
        return "Birthday was not found";
    }
}
const std::string Database::getPhoneNumber (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        const unsigned char* returnedPhoneNumber = sqlite3_column_text (stmt, 4);
        std::string str_returnedPhoneNumber = reinterpret_cast<char const*> (returnedPhoneNumber);
        closeDb ();
        return str_returnedPhoneNumber;
    }
    else {
        closeDb ();
        return "Phonenumber was not found";
    }
}
const std::string Database::getStreet (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        const unsigned char* returnedStreet = sqlite3_column_text (stmt, 5);
        std::string str_returnedStreet = reinterpret_cast<char const*> (returnedStreet);
        closeDb ();
        return str_returnedStreet;
    }
    else {
        closeDb ();
        return "Street was not found";
    }
}
const std::string Database::getCity (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        const unsigned char* returnedCity = sqlite3_column_text (stmt, 6);
        std::string str_returnedCity = reinterpret_cast<char const*> (returnedCity);
        closeDb ();
        return str_returnedCity;
    }
    else {
        closeDb ();
        return "City was not found";
    }
}
const int Database::getPostcode (std::string firstName, std::string lastName){
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // return firstName if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        int returnedPostcode = sqlite3_column_int (stmt, 7);
        closeDb ();
        return returnedPostcode;
    }
    else {
        closeDb ();
        return "Postcode was not found";
    }
}
