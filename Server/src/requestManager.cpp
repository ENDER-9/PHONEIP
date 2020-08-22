#include "requestManager.h"


// starting the server
void RequestManager::startServer (const char* ipAddress, int port) {
    svr.listen (ipAddress, port);
    std::cout << "Server started" << std::endl;
}

// stopping the server
void RequestManager::stopServer () {
    svr.stop ();
    std::cout << "Server stopped" << std::endl;
}


// this method handles the requests of the client
void RequestManager::handleRequest () {
    svr.Post ("/addPerson", [&] (const httplib::Request& req, httplib::Response& res) {
        if (req.has_param ("firstName") && req.has_param ("lastName")) {
            // parse request into single variables
            std::string firstName = req.get_param_value ("firstName");
            std::string lastName = req.get_param_value ("lastName");
            std::string birthday = req.get_param_value ("birthday");
            std::string phoneNumber = req.get_param_value ("phoneNumber");
            std::string landlineNumber = req.get_param_value ("landlineNumber");
            std::string street = req.get_param_value ("street");
            std::string city = req.get_param_value ("firstName");
            int postcode = std::stoi (req.get_param_value ("postcode"));

            // call the database method
            database.addPerson (Person (firstName, lastName, birthday, phoneNumber, landlineNumber, street, city, postcode));
            res.set_content ("Person added", "text/plain");
        }
    });
}