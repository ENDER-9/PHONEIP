#ifndef SERVER_H
#define SERVER_H
#include <boost/asio.hpp>
#include "database.h"
#include "person.h"

class Server {
    public:
    Server(unsigned short port) : port(port), tcpSocket(service), database("person.db") {
        database.createTable ();
    }

    void start ();
    void retrieveInformation();
    void sendInformation (std::string answerToSend);
    void sendInformation (Person person);


    private:
    Database database;
    Person person();
    boost::asio::io_context service;
    boost::asio::ip::tcp::socket tcpSocket;
    unsigned short port;
    char modeNumber[1] = {0};
};

#endif
