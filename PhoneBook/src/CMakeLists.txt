target_include_directories(PhoneBook PRIVATE .)
target_sources(PhoneBook 
PRIVATE 
    main.cpp
    client.h 
    client.cpp 
    frontend.h 
    frontend.cpp 
    person.h 
    person.cpp 
    qml.qrc 
)
add_subdirectory(qml)