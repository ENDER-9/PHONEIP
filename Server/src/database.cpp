#include "database.h"
#include "person.h"
#include <iostream>
#include <string>
#include <vector>

void Database::openDb (const char* fileName) {
    rc = sqlite3_open (fileName, &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database" << sqlite3_errmsg (db) << std::endl;
    }
}

void Database::closeDb () {
    sqlite3_close (db);
}


void Database::createTable () {
    openDb (fileName);
    rc = sqlite3_exec (db,
                       "CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, FirstName TEXT NOT NULL, LastName TEXT NOT NULL, Birthday TEXT "
                       "NOT NULL, "
                       "PhoneNumber TEXT NOT NULL, LandlineNumber TEXT NOT NULL, Street TEXT NOT NULL, City TEXT NOT NULL, Postcode INT NOT NULL)",
                       NULL, 0, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table" << sqlite3_errmsg (db);
    }
    closeDb ();
}

std::string Database::addPerson (Person person) {

    openDb (fileName);
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2 (db, "INSERT INTO Person (FirstName, LastName, Birthday, PhoneNumber, LandlineNumber, Street, City, Postcode) VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
                             -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cout << "Error preparing statement: " << sqlite3_errmsg (db);
    }
    // binding the values to the parameter
    rc = sqlite3_bind_text (stmt, 1, person.getFirstName ().c_str (), person.getFirstName ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_text (stmt, 2, person.getLastName ().c_str (), person.getLastName ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_text (stmt, 3, person.getBirthday ().c_str (), person.getBirthday ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_text (stmt, 4, person.getPhoneNumber ().c_str (), person.getPhoneNumber ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_text (stmt, 5, person.getLandlineNumber ().c_str (), person.getLandlineNumber ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_text (stmt, 6, person.getStreet ().c_str (), person.getStreet ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_text (stmt, 7, person.getCity ().c_str (), person.getCity ().length (), SQLITE_TRANSIENT);
    rc = sqlite3_bind_int (stmt, 8, person.getPostcode ());

    if (rc != SQLITE_OK) {
        std::cerr << "Error bind binding arguments: " << sqlite3_errmsg (db);
    }
    sqlite3_step (stmt);
    sqlite3_finalize (stmt);

    closeDb ();
    return "Person added";
}

std::string Database::deletePerson (std::string firstName, std::string lastName) {
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);
    // delete the Person if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        sqlite3_stmt* deleteStmt;
        rc = sqlite3_prepare_v2 (db, "DELETE FROM Person WHERE FirstName = ? AND LastName = ?", -1, &deleteStmt, NULL);

        sqlite3_bind_text (deleteStmt, 1, firstName.c_str (), firstName.length (), SQLITE_TRANSIENT);
        sqlite3_bind_text (deleteStmt, 2, lastName.c_str (), lastName.length (), SQLITE_TRANSIENT);
        sqlite3_step (deleteStmt);
        sqlite3_finalize (deleteStmt);
        closeDb ();
        return "Person was deleted";
    }
    else {
        closeDb ();
        return "Person was not found";
    }
}

std::string Database::modifyPerson (Person person) {
    openDb (fileName);
    sqlite3_stmt* stmt;
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, person.getFirstName ().c_str (), person.getFirstName ().length (), NULL);
    sqlite3_bind_text (stmt, 2, person.getLastName ().c_str (), person.getLastName ().length (), NULL);
    // modify the Person if it is in the database
    if (sqlite3_step (stmt) == SQLITE_ROW) {
        sqlite3_stmt* modifyStmt;
        rc = sqlite3_prepare_v2 (db, "UPDATE Books SET FirstName = ?, LastName = ?, Birthday = ?, PhoneNumber = ?, LandlineNumber = ?  Street = ?, City = ?, Postcode = ? WHERE FirstName = ? OR LastName = ?",
                                 -1, &modifyStmt, NULL);
        if (rc != SQLITE_OK) {
            std::cerr << "Error preparing modify statement: " << sqlite3_errmsg (db);
        }
        sqlite3_bind_text (modifyStmt, 1, person.getFirstName ().c_str (), person.getFirstName ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 2, person.getLastName ().c_str (), person.getLastName ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 3, person.getBirthday ().c_str (), person.getBirthday ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 4, person.getPhoneNumber ().c_str (), person.getPhoneNumber ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 5, person.getLandlineNumber ().c_str (), person.getLandlineNumber ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 6, person.getStreet ().c_str (), person.getStreet ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 7, person.getCity ().c_str (), person.getCity ().length (), NULL);
        sqlite3_bind_int (modifyStmt, 8, person.getPostcode ());
        sqlite3_bind_text (modifyStmt, 9, person.getFirstName ().c_str (), person.getFirstName ().length (), NULL);
        sqlite3_bind_text (modifyStmt, 10, person.getLastName ().c_str (), person.getLastName ().length (), NULL);

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

// Methods for returning single information
const nlohmann::json Database::getPersonInformation (std::string firstName, std::string lastName) {
    nlohmann::json personList;
    openDb (fileName);
    sqlite3_stmt* stmt;

    //----------------------------------//
    // first check if the Person is in the database
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (stmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (stmt, 2, lastName.c_str (), lastName.length (), NULL);

    if (sqlite3_step (stmt) != SQLITE_ROW) {
        closeDb ();
        nlohmann::json errorPerson;
        errorPerson["firstName"] = "Not found";
        errorPerson["lastName"] = "Not found";
        errorPerson["birthday"] = "Not found";
        errorPerson["phoneNumber"] = "Not found";
        errorPerson["landlineNumber"] = "Not found";
        errorPerson["street"] = "Not found";
        errorPerson["city"] = "Not found";
        errorPerson["postcode"] = 0;
        return errorPerson;
    }

    //-----------------------------//
    // select every entry, that was searched
    sqlite3_stmt* selectStmt;
    rc = sqlite3_prepare_v2 (db, "SELECT * FROM Person WHERE FirstName = ? AND LastName = ?", -1, &selectStmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg;
    }
    sqlite3_bind_text (selectStmt, 1, firstName.c_str (), firstName.length (), NULL);
    sqlite3_bind_text (selectStmt, 2, lastName.c_str (), lastName.length (), NULL);

    // if entity is in database fetch data
    for (;;) {
        rc = sqlite3_step (selectStmt);


        if (rc == SQLITE_DONE) {
            break;
        }

        if (rc != SQLITE_ROW) {
            break;
        }


        const unsigned char* returnedFirstName = sqlite3_column_text (stmt, 1);
        std::string str_returnedFirstName = reinterpret_cast<char const*> (returnedFirstName);

        const unsigned char* returnedLastName = sqlite3_column_text (stmt, 2);
        std::string str_returnedLastName = reinterpret_cast<char const*> (returnedLastName);

        const unsigned char* returnedBirthday = sqlite3_column_text (stmt, 3);
        std::string str_returnedBirthday = reinterpret_cast<char const*> (returnedBirthday);

        const unsigned char* returnedPhoneNumber = sqlite3_column_text (stmt, 4);
        std::string str_returnedPhoneNumber = reinterpret_cast<char const*> (returnedPhoneNumber);

        const unsigned char* returnedLandlineNumber = sqlite3_column_text (stmt, 5);
        std::string str_returnedLandlineNumber = reinterpret_cast<char const*> (returnedLandlineNumber);

        const unsigned char* returnedStreet = sqlite3_column_text (stmt, 6);
        std::string str_returnedStreet = reinterpret_cast<char const*> (returnedStreet);

        const unsigned char* returnedCity = sqlite3_column_text (stmt, 7);
        std::string str_returnedCity = reinterpret_cast<char const*> (returnedCity);

        int returnedPostcode = sqlite3_column_int (stmt, 8);

        nlohmann::json singlePerson;
        singlePerson["firstName"] = str_returnedFirstName;
        singlePerson["lastName"] = str_returnedLastName;
        singlePerson["birthday"] = str_returnedBirthday;
        singlePerson["phoneNumber"] = str_returnedPhoneNumber;
        singlePerson["landlineNumber"] = str_returnedPhoneNumber;
        singlePerson["street"] = str_returnedStreet;
        singlePerson["city"] = str_returnedCity;
        singlePerson["postcode"] = returnedPostcode;

        personList.push_back (singlePerson);
    }
    sqlite3_finalize (stmt);
    closeDb ();
    return personList;
}
// return firstName if it is in the database
