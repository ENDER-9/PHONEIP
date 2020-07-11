#include "frontend.h"

Frontend::Frontend (QObject* parent) : QObject (parent), person () {
}

QString Frontend::getFirstName () {
    return QString::fromStdString (person.getFirstName ());
}
QString Frontend::getLastName () {
    return QString::fromStdString (person.getLastName ());
}
QString Frontend::getBirthday () {
    return QString::fromStdString (person.getBirthday ());
}
QString Frontend::getPhoneNumber () {
    return QString::fromStdString (person.getPhoneNumber ());
}
QString Frontend::getStreet () {
    return QString::fromStdString (person.getStreet ());
}
QString Frontend::getCity () {
    return QString::fromStdString (person.getCity ());
}
int Frontend::getPostcode () {
    return person.getPostcode ();
}


void Frontend::setFirstName (QString& input) {
    person.setFirstName (input.toStdString ());
    emit firstNameChanged ();
}
void Frontend::setLastName (QString& input) {
    person.setLastName (input.toStdString ());
    emit lastNameChanged ();
}
void Frontend::setBirthday (QString& input) {
    person.setBirthday (input.toStdString ());
    emit birthdayChanged ();
}
void Frontend::setPhoneNumber (QString& input) {
    person.setPhoneNumber (input.toStdString ());
    emit phoneNumberChanged ();
}
void Frontend::setStreet (QString& input) {
    person.setStreet (input.toStdString ());
    emit streetChanged ();
}
void Frontend::setCity (QString& input) {
    person.setCity (input.toStdString ());
    emit cityChanged ();
}
void Frontend::setPostcode (int& input) {
    person.setPostcode (input);
    emit postcodeChanged ();
}


void Frontend::triggerSearchPerson () {
    Person tempPerson = client.sendGetPersonInformationServer (person.getFirstName (), person.getLastName ());
}
