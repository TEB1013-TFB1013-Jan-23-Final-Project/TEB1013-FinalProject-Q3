cmake_minimum_required(VERSION 3.22)
project(TEB1013_FinalProject_Q3)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif (WIN32)

add_executable(TEB1013_FinalProject_Q3 main.cpp common.h common.inl question3.cpp question3.h common.cpp)
