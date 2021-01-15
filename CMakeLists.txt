cmake_minimum_required(VERSION 3.19)
project(opz)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES methods.cpp)
add_subdirectory(googletest)

add_executable(tests tests.cpp ${SOURCE_FILES})

add_executable(opz main.cpp methods.cpp methods.h)
target_include_directories(tests PRIVATE googletest/googletest/include PRIVATE source)

target_link_libraries(tests gtest)