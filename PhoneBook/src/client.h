#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

class Client {
    public:
    Client() : server(boost::asio::ip::address::from_string("127.0.0.1"), 3000), tcpSocket(service) {

    }

    std::string connectToServer ();
    nlohmann::json readServerAnswer ();
    std::string sendAddPersonServer (Person& person);
    std::string sendDeletePersonServer(const std::string& firstName, const std::string& lastName);
    std::string sendModifyPersonServer (Person& person);
    Person sendGetPersonInformationServer (const std::string& firstName, const std::string& lastName);



    private:
    boost::asio::io_context service;
    boost::asio::ip::tcp::endpoint server;
    boost::asio::ip::tcp::socket tcpSocket;
};

#endif