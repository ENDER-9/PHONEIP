#ifndef PERSON_H
#define PERSON_H
#include <string>

struct Person {

    public:
    Person (std::string firstName_, std::string lastName_, std::string birthday_, std::string phoneNumber_, std::string street_, std::string city_, std::string postcode_);

    // Methods to get data
    const std::string& getFirstName ();
    const std::string& getLastName ();
    const std::string& getBirthday ();
    const std::string& getPhoneNumber ();
    const std::string& getStreet ();
    const std::string& getCity ();
    const int& getPostcode ();

    // Methods to change data in variables

    void setFirstName (std::string& input);
    void setLastName (std::string& input);
    void setBirthday (std::string& input);
    void setPhoneNumber (std::string& input);
    void setStreet (std::string& input);
    void setCity (std::string& input);
    void setPostcode (int& input);

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