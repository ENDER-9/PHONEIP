#include <iostream>
#include "server.h"

int main (int argc, char* argv[]) {
    
    if(argc != 2) {
        std::cout << "the amount of arguments is wrong";
    }
    unsigned short port = atoi (argv[1]);
    Server server (port);
    server.start ();
}