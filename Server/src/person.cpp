#include "person.h"


// Methods to get data
std::string_view Person::getFirstName () const {
    return firstName;
}
std::string_view Person::getLastName () const {
    return lastName;
}
std::string_view Person::getBirthday () const {
    return birthday;
}
std::string_view Person::getPhoneNumber () const {
    return phoneNumber;
}
std::string_view Person::getStreet () const {
    return street;
}
std::string_view Person::getCity () const {
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