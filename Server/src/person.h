#ifndef PERSON_H
#define PERSON_H
#include <string>

struct Person {

    public:
    Person (std::string firstName_, std::string lastName_, std::string birthday_, std::string phoneNumber_, std::string street_, std::string city_, int postcode_)
    : firstName (firstName), lastName (lastName_), birthday (birthday_), phoneNumber (phoneNumber_), street (street_), city (city_), postcode (postcode_) {
    }

    // Methods to get data
    std::string_view getFirstName () const;
    std::string_view getLastName () const;
    std::string_view getBirthday () const;
    std::string_view getPhoneNumber () const;
    std::string_view getStreet () const;
    std::string_view getCity () const;
    int getPostcode () const;

    // Methods to change data in variables

    void setFirstName (std::string input);
    void setLastName (std::string input);
    void setBirthday (std::string input);
    void setPhoneNumber (std::string input);
    void setStreet (std::string input);
    void setCity (std::string input);
    void setPostcode (int input);

    private:
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string phoneNumber;
    std::string street;
    std::string city;
    int postcode;
};

#endif