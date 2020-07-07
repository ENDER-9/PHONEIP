target_include_directories(PhoneBook PRIVATE .)
target_sources(PhoneBook 
PRIVATE 
    main.cpp
    person.cpp 
    person.h 
    client.h 
    client.cpp 
    frontend.h 
    frontend.cpp 
)
add_subdirectory(qml)

