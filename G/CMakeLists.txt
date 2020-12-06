cmake_minimum_required(VERSION 3.14)
project(G)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

#add_executable(G tc.cpp)

#add_executable(G main2.cpp)
add_executable(G main2.cpp)
#add_executable(G main4.cpp)
#add_executable(G kickstart.cpp)
#add_executable(G jam.cpp)
#add_executable(G lc.cpp)
#add_executable(G fb.cpp)

