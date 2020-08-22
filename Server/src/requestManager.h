#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H
#include "database.h"
#include <../cpp-httplib/httplib.h>
#include <sqlite3.h>
#include <string>


class RequestManager {

    public:
    RequestManager () : database ("person.db", db) {
    }
    void handleRequest ();
    void startServer (const char* ipAddress, int port);
    void stopServer ();

    private:
    httplib::Server svr;
    sqlite3* db;
    Database database;
};

#endif