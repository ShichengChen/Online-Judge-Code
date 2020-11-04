cmake_minimum_required(VERSION 3.14)
project(G)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -Wall -O2")
#add_executable(G tc.cpp)

#add_executable(G withoutTemplate.cpp)
#add_executable(G main2.cpp)
add_executable(G tsp-opt3.cpp)
#add_executable(G tsp-mst.cpp)
#add_executable(G mwvc2.cpp)
#add_executable(G generatMWVC.cpp)
#add_executable(G tsp.cpp)
#add_executable(G generateTSPdata.cpp)
#add_executable(G tspOld.cpp)

#add_executable(G main4.cpp)
#add_executable(G kickstart.cpp)
#add_executable(G jam.cpp)
#add_executable(G lc.cpp)
#add_executable(G fb.cpp)





#add_executable(G ek2.cpp )
#add_executable(G generateData.cpp)
#add_executable(G ek2.cpp)
#add_executable(G relabel.cpp)
#add_executable(G ek_dinic.cpp)
#add_executable(G eknew.cpp)
#add_executable(G relabel3.cpp)
#add_executable(G generateData2.cpp)
