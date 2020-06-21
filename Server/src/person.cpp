#include "person.h"

Person::Person (std::string firstName_, std::string lastName_, std::string birthday_, std::string phoneNumber_, std::string street_, std::string city_, std::string postcode_);
    : firstName (firstName), lastName (lastName_), birthday (birthday_), phoneNumber (phoneNumber_), street (street_), city (city_), postcode (postcode_) {
    }
    }

    // Methods to get data
    const std::string& Person::getFirstName () {
        return firstName;
    }
    const std::string& Person::getLastName () {
        return lastName;
    }
    const std::string& Person::getBirthday () {
        return birthday;
    }
    const std::string& Person::getPhoneNumber () {
        return phoneNumber;
    }
    const std::string& Person::getStreet () {
        return street;
    }
    const std::string& Person::getCity () {
        return city;
    }
    const int& Person::getPostcode () {
        return postcode;
    }
    // Methods to change data in Variables

    void Person::setFirstName (std::string& input) {
        firstName = input;
    }
    void Person::setLastName (std::string& input) {
        lastName = input;
    }
    void Person::setBirthday (std::string& input) {
        birthday = input;
    }
    void Person::setPhoneNumber (std::string& input) {
        phoneNumber = input;
    }
    void Person::setStreet (std::string& input) {
        street = input;
    }
    void Person::setCity (std::string& input) {
        city = input;
    }
    void Person::setPostcode (int& input) {
        postcode = input;
    }