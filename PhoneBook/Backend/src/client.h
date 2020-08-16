#ifndef CLIENT_H
#define CLIENT_H

#include "../Lib/json-develop/single_include/nlohmann/json.hpp"
#include "person.h"
#include <boost/asio.hpp>

class Client {
    public:
    Client (unsigned short port) : server (boost::asio::ip::address::from_string ("127.0.0.1"), port), tcpSocket (service) {
    }

    std::string sendAddPersonServer (Person& person);
    std::string sendDeletePersonServer (const std::string& firstName, const std::string& lastName);
    std::string sendModifyPersonServer (Person& person);
    Person sendGetPersonInformationServer (const std::string& firstName, const std::string& lastName);


    private:
    void connectToServer ();
    nlohmann::json readServerAnswer ();
    boost::asio::io_context service;
    boost::asio::ip::tcp::endpoint server;
    boost::asio::ip::tcp::socket tcpSocket;
};

#endif