#include "person.h"


// Methods to get data
std::string Person::getFirstName () const{
    return firstName;
}
std::string Person::getLastName () const {
    return lastName;
}
std::string Person::getBirthday () const {
    return birthday;
}
std::string Person::getPhoneNumber () const {
    return phoneNumber;
}
std::string Person::getStreet () const {
    return street;
}
std::string Person::getCity () const {
    return city;
}
int Person::getPostcode () const {
    return postcode;
}
// Methods to change data in Variables

void Person::setFirstName (std::string input) {
    firstName = move (input);
}
void Person::setLastName (std::string input) {
    lastName = move (input);
}
void Person::setBirthday (std::string input) {
    birthday = move (input);
}
void Person::setPhoneNumber (std::string input) {
    phoneNumber = move (input);
}
void Person::setStreet (std::string input) {
    street = move (input);
}
void Person::setCity (std::string input) {
    city = move (input);
}
void Person::setPostcode (int input) {
    postcode = input;
}