#ifndef DATABASE_H
#define DATABASE_H
#include <sqlite3.h>
#include <string>

struct Person {

    public:
    Person (std::string firstName_, std::string lastName_, std::string birthday_, std::string phoneNumber_, std::string street_, std::string city_, std::string postcode_)
    : firstName (firstName), lastName (lastName_), birthday (birthday_), phoneNumber (phoneNumber_), street (street_), city (city_), postcode (postcode_) {
    }
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string phoneNumber;
    std::string street;
    std::string city;
    std::string postcode;
};

class Database {

    public:
    private:
    sqlite3* db;
    int rc = 0;
};

#endif