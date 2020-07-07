#ifndef FRONTEND_H
#define FRONTEND_H
#include "person.h"
#include "client.h"

#include <QObject>


class Frontend : public QObject {

    Q_OBJECT
    public:
    explicit Frontend (QObject* parent = nullptr);

    Q_PROPERTY (QString firstName READ getFirstNameFrontend WRITE setFirstNameFrontend NOTIFY firstNameChanged)
    Q_PROPERTY (QString lastName READ getLastNameFrontend WRITE setLastNameFrontend NOTIFY lastNameChanged)
    Q_PROPERTY (QString birthday READ getBirthdayFrontend WRITE setBirthdayFrontend NOTIFY birthdayChanged)
    Q_PROPERTY (QString phoneNumber READ getPhoneNumberFrontend WRITE setPhoneNumberFrontend NOTIFY phoneNumberChanged)
    Q_PROPERTY (QString street READ getStreetFrontend WRITE setStreetFrontend NOTIFY streetChanged)
    Q_PROPERTY (QString city READ getCityFrontend WRITE setCityFrontend NOTIFY cityChanged)
    Q_PROPERTY (int postcode READ getPostcodeFrontend WRITE setPostcodeFrontend NOTIFY postcodeChanged)

    Q_INVOKABLE QString getFirstNameFrontend ();
    Q_INVOKABLE QString getLastNameFrontend ();
    Q_INVOKABLE QString getBirthdayFrontend ();
    Q_INVOKABLE QString getPhoneNumberFrontend ();
    Q_INVOKABLE QString getStreetFrontend ();
    Q_INVOKABLE QString getCityFrontend ();
    Q_INVOKABLE int getPostcodeFrontend ();

    Q_INVOKABLE void setFirstNameFrontend (QString& input);
    Q_INVOKABLE void setLastNameFrontend (QString& input);
    Q_INVOKABLE void setBirthdayFrontend (QString& input);
    Q_INVOKABLE void setPhoneNumberFrontend (QString& input);
    Q_INVOKABLE void setStreetFrontend (QString& input);
    Q_INVOKABLE void setCityFrontend (QString& input);
    Q_INVOKABLE void setPostcodeFrontend (int& input);


    signals:
    void firstNameChanged ();
    void lastNameChanged ();
    void birthdayChanged ();
    void phoneNumberChanged ();
    void streetChanged ();
    void cityChanged ();
    void postcodeChanged ();


    private:
    Person person;
    Client client;
};

#endif