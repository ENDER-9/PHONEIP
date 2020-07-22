#include "client.h"
#include <iostream>




std::string Client::connectToServer() {
    tcpSocket.connect (server);
    return "";
}

nlohmann::json Client::readServerAnswer() {
std::array<char, 1024> buffer;
    std::size_t size = tcpSocket.read_some (boost::asio::buffer (buffer, buffer.size ()));
    std::string message (buffer.begin(), buffer.begin() + size);
    nlohmann::json jsonString = nlohmann::json::parse (message);
    return jsonString;
}


std::string Client::sendAddPersonServer(Person& person) {
    nlohmann::json personJson;
    personJson["Command"] = "AddPerson";
    personJson["FirstName"] = person.getFirstName ();
    personJson["LastName"] = person.getLastName ();
    personJson["Birthday"] = person.getBirthday ();
    personJson["PhoneNumber"] = person.getPhoneNumber ();
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

std::string Client::sendDeletePersonServer(const std::string& firstName, const std::string& lastName) {
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

std::string Client::sendModifyPersonServer(Person& person) {
    nlohmann::json personJson;
    personJson["Command"] = "ModifyPerson";
    personJson["FirstName"] = person.getFirstName ();
    personJson["LastName"] = person.getLastName ();
    personJson["Birthday"] = person.getBirthday ();
    personJson["PhoneNumber"] = person.getPhoneNumber ();
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

Person Client::sendGetPersonInformationServer(const std::string& firstName, const std::string& lastName) {
    nlohmann::json personJson;
    personJson["Command"] = "GetPersonInformation";
    personJson["FirstName"] = firstName;
    personJson["LastName"] = lastName;
    auto jsonString = personJson.dump ();
    connectToServer ();
    tcpSocket.write_some (boost::asio::buffer (jsonString, jsonString.length ()));
    nlohmann::json parsedReturnedJsonString = readServerAnswer ();
    Person returnedPerson (parsedReturnedJsonString["FirstName"], parsedReturnedJsonString["LastName"], parsedReturnedJsonString["Birthday"],
                           parsedReturnedJsonString["PhoneNumber"], parsedReturnedJsonString["Street"], parsedReturnedJsonString["City"], parsedReturnedJsonString["Postcode"]);
    tcpSocket.close ();
    return returnedPerson;
}
    
    