cmake_minimum_required(VERSION 3.5)

project(TestClasses LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt6 6.4 REQUIRED COMPONENTS Sql Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestClasses tst_testclasses.cpp ../RMP_LosRios/database.cpp ../RMP_LosRios/networkmanager.cpp)
add_test(NAME TestClasses COMMAND TestClasses)

target_link_libraries(TestClasses PRIVATE Qt${QT_VERSION_MAJOR}::Test PRIVATE Qt6::Sql PRIVATE Qt6::Network)

