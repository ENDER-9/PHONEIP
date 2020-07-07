cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(PhoneBook)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Boost 1.40.0 REQUIRED system)
find_package(Qt5 COMPONENTS Core Quick REQUIRED)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(PhoneBook)
set_property(TARGET PhoneBook
    PROPERTY CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "") 
include(FetchContent)
FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json.git)
FetchContent_MakeAvailable(json)

TARGET_LINK_LIBRARIES( PhoneBook LINK_PUBLIC ${Boost_LIBRARIES} )
target_link_libraries( PhoneBook LINK_PUBLIC nlohmann_json::nlohmann_json)
target_compile_definitions(PhoneBook
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(PhoneBook
  PRIVATE Qt5::Core Qt5::Quick)

add_subdirectory(src)