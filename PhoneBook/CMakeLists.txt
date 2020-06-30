cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(Spyculus)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Boost 1.40.0 REQUIRED system)
find_package(Qt5 COMPONENTS Core Quick REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Spyculus)
set_property(TARGET Spyculus
    PROPERTY CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "") 
include(FetchContent)
FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json.git)
FetchContent_MakeAvailable(json)

TARGET_LINK_LIBRARIES( Spyculus LINK_PUBLIC ${Boost_LIBRARIES} )
target_link_libraries( Spyculus LINK_PUBLIC nlohmann_json::nlohmann_json)
target_compile_definitions(Spyculus
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Spyculus
  PRIVATE Qt5::Core Qt5::Quick)

add_subdirectory(src)