cmake_minimum_required(VERSION 3.14)

project(plugin_metadata LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.3 REQUIRED COMPONENTS Core)

add_executable(plugin_metadata
  main.cpp
)
target_link_libraries(plugin_metadata Qt6::Core)

install(TARGETS plugin_metadata
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
