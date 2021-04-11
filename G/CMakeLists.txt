cmake_minimum_required(VERSION 3.14)
project(G)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wformat -Wfloat-equal  -Wlogical-op -Wshift-overflow=2")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wformat -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2")
#-Wconversion make index warning
set(CMAKE_CXX_FLAGS_RELEASE "-O2")



set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -g")
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=undefined -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize-recover -g")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -D_GLIBCXX_DEBUG_PEDANTIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -D_FORTIFY_SOURCE=2")



#add_executable(G tc.cpp)

#add_executable(G main2.cpp)
add_executable(G operatingSystem.cpp)
#add_executable(G main4.cpp)
#add_executable(G kickstart.cpp)
#add_executable(G jam.cpp)
#add_executable(G lc.cpp)
#add_executable(G fb.cpp)

