#include "server.h"
#include <iostream>
#include <nlohmann/json.hpp>

void Server::start() {
    boost::asio::ip::tcp::acceptor acceptor (service, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
        std::cout << "waiting for client to connect" << std::endl;
        acceptor.accept (tcpSocket);
        std::cout << "Client connected to the Server" << std::endl;
        retrieveInformation ();
}

void Server::retrieveInformation() {
    //retrieve Json Object and check which mode is selected
    std::array<char, 1024> buffer;
    std::size_t size = tcpSocket.read_some (boost::asio::buffer (buffer, buffer.size ()));
    std::string message (buffer.begin (), buffer.begin () + size);
    nlohmann::json personJson = nlohmann::json::parse (message);

    if (personJson["command"] == "addPerson") {
        std::string firstName = personJson["FirstName"];
        std::string lastName = personJson["LastName"];
        std::string birthday = personJson["Birthday"];
        std::string phoneNumber = personJson["PhoneNumber"];
        std::string street = personJson["Street"];
        std::string city = personJson["City"];
        int postcode = personJson["Postcode"];
        std::string returnedServerAnswer = database.addPerson (Person (firstName, lastName, birthday, phoneNumber, street, city, postcode));
        sendInformation (returnedServerAnswer);
        std::cout << "Person added" << std::endl;
    }
    else if (personJson["command"] == "deletePerson") {
        std::string firstName = personJson["FirstName"];
        std::string lastName = personJson["LastName"];
        std::string returnedServerAnswer = database.deletePerson (firstName, lastName);
        sendInformation (returnedServerAnswer);
        std::cout << "Person deleted";
    }
    else if(personJson["command"] == "modifyPerson") {
        std::string firstName = personJson["FirstName"];
        std::string lastName = personJson["LastName"];
        std::string birthday = personJson["Birthday"];
        std::string phoneNumber = personJson["PhoneNumber"];
        std::string street = personJson["Street"];
        std::string city = personJson["City"];
        int postcode = personJson["Postcode"];
        std::string returnedServerAnswer = database.modifyPerson (Person (firstName, lastName, birthday, phoneNumber, street, city, postcode));
        sendInformation (returnedServerAnswer);
    }
    else if(personJson["command"] == "getPersonInformation") {
        std::string firstName = personJson["FirstName"];
        std::string lastName = personJson["LastName"];
        Person returnedServerAnswer = database.getPersonInformation (firstName, lastName);
        sendInformation (returnedServerAnswer);
    }
    else {
        std::cout << "Nothing found" << std::endl;
    }
}

//method for sending normal status information back to the client
void Server::sendInformation(std::string answerToSend) {
    nlohmann::json personJson;
    personJson["message"] = answerToSend;
    tcpSocket.write_some (boost::asio::buffer (personJson.dump (), personJson.dump ().length ()));
}

void Server::sendInformation(Person person) {
    nlohmann::json personJson;
    personJson["FirstName"] = person.getFirstName();
    personJson["LastName"] = person.getLastName ();
    personJson["Birthday"] = person.getBirthday();
    personJson["PhoneNumber"] = person.getPhoneNumber();
    personJson["Street"] = person.getStreet();
    personJson["City"] = person.getCity();
    personJson["Postcode"] = person.getPostcode();
    tcpSocket.write_some (boost::asio::buffer (personJson.dump (), personJson.dump ().length ()));
}

//method overloading for sending asked person information to the client