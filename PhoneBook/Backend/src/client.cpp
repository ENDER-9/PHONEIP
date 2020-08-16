#include "client.h"
#include <iostream>


void Client::connectToServer () {
    tcpSocket.connect (server);
}

nlohmann::json Client::readServerAnswer () {
    std::array<char, 1024> buffer;
    std::size_t size = tcpSocket.read_some (boost::asio::buffer (buffer, buffer.size ()));
    std::string message (buffer.begin (), buffer.begin () + size);
    nlohmann::json jsonString = nlohmann::json::parse (message);
    return jsonString;
}


std::string Client::sendAddPersonServer (Person& person) {
    nlohmann::json personJson;
    // pack person object to json object
    personJson["Command"] = "AddPerson";
    personJson["FirstName"] = person.getFirstName ();
    personJson["LastName"] = person.getLastName ();
    personJson["Birthday"] = person.getBirthday ();
    personJson["PhoneNumber"] = person.getPhoneNumber ();
    personJson["LandlineNumber"] = person.getLandlineNumber ();
    personJson["Street"] = person.getStreet ();
    personJson["City"] = person.getCity ();
    personJson["Postcode"] = person.getPostcode ();
    // create json object string
    auto jsonString = personJson.dump ();
    try {
        connectToServer ();
    } catch (...) {
        tcpSocket.close ();
        return "Error connecting";
    }
    // send json string
    tcpSocket.write_some (boost::asio::buffer (jsonString, jsonString.length ()));
    // read server answer
    nlohmann::json parsedReturnedJsonString = readServerAnswer ();
    tcpSocket.close ();
    return parsedReturnedJsonString["Message"];
}

std::string Client::sendDeletePersonServer (const std::string& firstName, const std::string& lastName) {
    nlohmann::json personJson;
    personJson["Command"] = "DeletePerson";
    personJson["FirstName"] = firstName;
    personJson["LastName"] = lastName;
    auto jsonString = personJson.dump ();
    connectToServer ();
    tcpSocket.write_some (boost::asio::buffer (jsonString, jsonString.length ()));
    nlohmann::json parsedReturnedJsonString = readServerAnswer ();
    tcpSocket.close ();
    return parsedReturnedJsonString["Message"];
}

std::string Client::sendModifyPersonServer (Person& person) {
    nlohmann::json personJson;
    personJson["Command"] = "ModifyPerson";
    personJson["FirstName"] = person.getFirstName ();
    personJson["LastName"] = person.getLastName ();
    personJson["Birthday"] = person.getBirthday ();
    personJson["PhoneNumber"] = person.getPhoneNumber ();
    personJson["LandlineNumber"] = person.getLandlineNumber ();
    personJson["Street"] = person.getStreet ();
    personJson["City"] = person.getCity ();
    personJson["Postcode"] = person.getPostcode ();
    auto jsonString = personJson.dump ();
    connectToServer ();
    tcpSocket.write_some (boost::asio::buffer (jsonString, jsonString.length ()));
    nlohmann::json parsedReturnedJsonString = readServerAnswer ();
    tcpSocket.close ();
    return parsedReturnedJsonString["Message"];
}

Person Client::sendGetPersonInformationServer (const std::string& firstName, connst std::string& lastName) {
    nlohmann::json personJson;
    personJson["Command"] = "GetPersonInformation";
    personJson["FirstName"] = firstName;
    personJson["LastName"] = lastName;
    auto jsonString = personJson.dump ();
    try {
        connectToServer ();
    } catch (...) {
        return Person ("Error connecting", "Error connecting", "Error connecting", "Error connecting", "Error connecting", "Error connecting", "Error connecting", 0);
    }

    tcpSocket.write_some (boost::asio::buffer (jsonString, jsonString.length ()));
    // create Person object with returned json string
    nlohmann::json parsedReturnedJsonString = readServerAnswer ();
    Person returnedPerson (parsedReturnedJsonString["FirstName"], parsedReturnedJsonString["LastName"], parsedReturnedJsonString["Birthday"],
                           parsedReturnedJsonString["PhoneNumber"], parsedReturnedJsonString["LandlineNumber"], parsedReturnedJsonString["Street"],
                           parsedReturnedJsonString["City"], parsedReturnedJsonString["Postcode"]);
    tcpSocket.close ();
    return returnedPerson;
}
