cmake_minimum_required(VERSION 3.6)
project(French_Helper_Console)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")

include_directories(include)
include_directories(include/external)
link_directories(include/external)

file(GLOB OTHER_SRC "include/internal/*.cpp" "include/internal/Commands/*.cpp")

set(SOURCE_FILES main.cpp)
add_executable(French_Helper_Console ${SOURCE_FILES} ${OTHER_SRC})
