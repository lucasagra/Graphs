# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(graphs-algorithms)

# creates the variable EXEC and sets it to hello
set(EXEC main)
set(EXEC_DJIKSTRA djikstra)
set(EXEC_KRUSKAL kruskal)
set(EXEC_PRIM prim)
set(EXEC_BELLMANFORD bellmanford)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# I../includes
include_directories(includes)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/main.cpp src/graph.cpp)
file(GLOB SOURCES_DJIKSTRA src/djikstra.cpp src/graph.cpp)
file(GLOB SOURCES_KRUSKAL src/kruskal.cpp src/graph.cpp)
file(GLOB SOURCES_PRIM src/prim.cpp src/graph.cpp)
file(GLOB SOURCES_BELLMANFORD src/bellmanford.cpp src/graph.cpp)

# compiles the files defined by SOURCES to generate the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})
add_executable(${EXEC_DJIKSTRA} ${SOURCES_DJIKSTRA})
add_executable(${EXEC_KRUSKAL} ${SOURCES_KRUSKAL})
add_executable(${EXEC_PRIM} ${SOURCES_PRIM})
add_executable(${EXEC_BELLMANFORD} ${SOURCES_BELLMANFORD})