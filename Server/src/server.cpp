#include "server.h"
#include <iostream>

void Server::start() {
    boost::asio::ip::tcp::acceptor acceptor (service, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
    while(true) {
        boost::asio::ip::tcp::socket tcpSocket (service);
        std::cout << "waiting for client to connect" << std::endl;
        acceptor.accept (tcpSocket);
    }
}