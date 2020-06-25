cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(Spyculus)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Boost 1.40.0 REQUIRED system)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Spyculus)
set_property(TARGET Spyculus
    PROPERTY CXX_STANDARD 17)

TARGET_LINK_LIBRARIES( Spyculus LINK_PUBLIC ${Boost_LIBRARIES} )

add_subdirectory(src)