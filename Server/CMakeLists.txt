cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(Server)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Server)
set_property(TARGET Server
    PROPERTY CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "") 
include(FetchContent)
FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json.git)
FetchContent_MakeAvailable(json)

TARGET_LINK_LIBRARIES( Server LINK_PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(Server LINK_PUBLIC sqlite3)

add_subdirectory(src)