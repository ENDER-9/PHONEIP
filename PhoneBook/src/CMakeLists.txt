target_include_directories(Spyculus PRIVATE .)
target_sources(Spyculus 
PRIVATE 
    main.cpp
    person.cpp 
    person.h 
)
add_subdirectory(qml)

