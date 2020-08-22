#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {

    public:
    Person (std::string firstName_, std::string lastName_, std::string birthday_, std::string phoneNumber_, std::string landlineNumber_, std::string street_, std::string city_, int postcode_)
    : firstName (firstName_), lastName (lastName_), birthday (birthday_), phoneNumber (phoneNumber_), landlineNumber (landlineNumber_), street (street_), city (city_),
      postcode (postcode_) {
    }

    // Methods to get data
    std::string getFirstName () const;
    std::string getLastName () const;
    std::string getBirthday () const;
    std::string getPhoneNumber () const;
    std::string getLandlineNumber () const;
    std::string getStreet () const;
    std::string getCity () const;
    int getPostcode () const;

    // Methods to change data in variables

    void setFirstName (std::string& input);
    void setLastName (std::string& input);
    void setBirthday (std::string& input);
    void setPhoneNumber (std::string& input);
    void setLandlineNumber (std::string& input);
    void setStreet (std::string& input);
    void setCity (std::string& input);
    void setPostcode (int& input);

    private:
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string phoneNumber;
    std::string landlineNumber;
    std::string street;
    std::string city;
    int postcode;
};

#endif
