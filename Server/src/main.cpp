#include "requestManager.h"
#include <iostream>

int main () {
    RequestManager requestManager;
    requestManager.handleRequest ();
    requestManager.startServer ("127.0.0.1", 1234);
}
