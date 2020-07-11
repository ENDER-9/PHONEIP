#ifndef FRONTEND_H
#define FRONTEND_H
#include "client.h"
#include "person.h"

#include <QObject>


class Frontend : public QObject {

    Q_OBJECT
    public:
    explicit Frontend (QObject* parent = nullptr);

    Q_PROPERTY (QString firstName READ getFirstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY (QString lastName READ getLastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY (QString birthday READ getBirthday WRITE setBirthday NOTIFY birthdayChanged)
    Q_PROPERTY (QString phoneNumber READ getPhoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged)
    Q_PROPERTY (QString street READ getStreet WRITE setStreet NOTIFY streetChanged)
    Q_PROPERTY (QString city READ getCity WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY (int postcode READ getPostcode WRITE setPostcode NOTIFY postcodeChanged)

    Q_INVOKABLE QString getFirstName ();
    Q_INVOKABLE QString getLastName ();
    Q_INVOKABLE QString getBirthday ();
    Q_INVOKABLE QString getPhoneNumber ();
    Q_INVOKABLE QString getStreet ();
    Q_INVOKABLE QString getCity ();
    Q_INVOKABLE int getPostcode ();

    Q_INVOKABLE void setFirstName (QString& input);
    Q_INVOKABLE void setLastName (QString& input);
    Q_INVOKABLE void setBirthday (QString& input);
    Q_INVOKABLE void setPhoneNumber (QString& input);
    Q_INVOKABLE void setStreet (QString& input);
    Q_INVOKABLE void setCity (QString& input);
    Q_INVOKABLE void setPostcode (int& input);

    Q_INVOKABLE void triggerSearchPerson ();


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