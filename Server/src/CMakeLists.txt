target_include_directories(Server PRIVATE .)
target_sources(Server 
PRIVATE 
    main.cpp
    requestManager.h 
    requestManager.cpp 
    database.h 
    database.cpp 
    person.h
    person.cpp
)


