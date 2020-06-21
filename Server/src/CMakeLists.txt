target_include_directories(Server PRIVATE .)
target_sources(Server 
PRIVATE 
    main.cpp
    server.h 
    server.cpp 
    database.h 
    database.cpp 
    person.h
    person.cpp 
}

