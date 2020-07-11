cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(PhoneBook LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()
find_package(Boost 1.40.0 REQUIRED system)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

if(ANDROID)
    add_library(PhoneBook SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(PhoneBook)
    set_property(TARGET PhoneBook
    PROPERTY CXX_STANDARD 17)
endif()

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