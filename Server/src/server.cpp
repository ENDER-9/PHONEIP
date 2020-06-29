#include "server.h"
#include <iostream>
#include <nlohmann/json.hpp>

void Server::start() {
    boost::asio::ip::tcp::acceptor acceptor (service, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
        std::cout << "waiting for client to connect" << std::endl;
        acceptor.accept (tcpSocket);
        std::cout << "Client connected to the Server" << std::endl;
        
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
        std::cout << "Person added" << std::endl;
    }
    else if (personJson["command"] == "deletePerson") {
        std::string firstName = personJson["FirstName"];
        std::string lastName = personJson["LastName"];
        std::string returnedServerAnswer = database.deletePerson (firstName, lastName);
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
    }
    else {
        std::cout << "Nothing found" << std::endl;
    }
}


void Server::sendInformation(std::string answerToSend) {
    std::array<char, 1024> buffer;
    
}