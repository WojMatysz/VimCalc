cmake_minimum_required(VERSION 3.22)
project(VimCalc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BINARY_NAME vimcalc)

#Directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

#Executable target
add_executable(${BINARY_NAME} ./src/main.cpp)

#Recursive catching source files
file(GLOB_RECURSE SOURCE_FILES ${SRC_DIR}/*.cpp)
list(FILTER SOURCE_FILES EXCLUDE REGEX "main.cpp$")

add_library(src STATIC ${SOURCE_FILES})

target_include_directories(src PUBLIC ${INCLUDE_DIR})
target_include_directories(${BINARY_NAME} PRIVATE ${INCLUDE_DIR})

#Link source files
target_link_directories(${BINARY_NAME} PRIVATE ${LIB_DIR})

#Ncurses library
find_package(Curses REQUIRED)

target_link_libraries(${BINARY_NAME} PRIVATE 
	src
    -static-libgcc 
    -static-libstdc++ 
	${CURSES_LIBRARIES}
)

target_include_directories(${BINARY_NAME} PRIVATE ${CURSES_INCLUDE_DIR})
