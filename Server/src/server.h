#ifndef SERVER_H
#define SERVER_H
#include <boost/asio.hpp>
#include "database.h"

class Server {
    public:
    Server(unsigned short port) : port(port), database("person.db") {
        database.createTable ();
    }

    void start ();


    private:
    Database database;
    boost::asio::io_context service;
    unsigned short port;
};

#endif