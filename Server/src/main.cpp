#include <iostream>
#include "server.h"

int main () {

    unsigned short port = 3000;
    Server server (port);
    while(true) {
        server.start ();
    }

}
