#include "server.h"
#include <iostream>

int main () {

    unsigned short port = 4000;
    Server server (port);
    while (true) {
        server.start ();
    }
}
