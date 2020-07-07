#include "frontend.h"

Frontend::Frontend (QObject* parent) : QObject (parent), person() {
}

QString Frontend::getFirstNameFrontend () {
    return QString::fromStdString(person.getFirstName());
}
QString Frontend::getLastNameFrontend () {
    return QString::fromStdString (person.getLastName());
}
QString Frontend::getBirthdayFrontend () {
    return QString::fromStdString (person.getBirthday ());
}
QString Frontend::getPhoneNumberFrontend () {
    return QString::fromStdString (person.getPhoneNumber ());
}
QString Frontend::getStreetFrontend () {
    return QString::fromStdString (person.getStreet ());
}
QString Frontend::getCityFrontend () {
    return QString::fromStdString (person.getCity ());
}
int Frontend::getPostcodeFrontend () {
    return person.getPostcode ();
}


void Frontend::setFirstNameFrontend (QString& input) {
    person.setFirstName(input.toStdString());
    emit firstNameChanged ();
}
void Frontend::setLastNameFrontend (QString& input) {
    person.setLastName (input.toStdString ());
    emit lastNameChanged ();
}
void Frontend::setBirthdayFrontend (QString& input) {
    person.setBirthday (input.toStdString ()); 
    emit birthdayChanged ();
}
void Frontend::setPhoneNumberFrontend (QString& input) {
    person.setPhoneNumber (input.toStdString ());
    emit phoneNumberChanged ();
}
void Frontend::setStreetFrontend (QString& input) {
    person.setStreet (input.toStdString ());
    emit streetChanged ();
}
void Frontend::setCityFrontend (QString& input) {
    person.setCity (input.toStdString ());
    emit cityChanged ();
}
void Frontend::setPostcodeFrontend (int& input) {
    person.setPostcode (input);
    emit postcodeChanged ();
}
