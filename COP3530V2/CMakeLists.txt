cmake_minimum_required(VERSION 3.21)
project(COP3530Project03)
set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(COP3530Project03 main.cpp AdjacencyList.cpp AdjacencyList.h)

target_link_libraries(COP3530Project03 sfml-graphics sfml-audio)
