cmake_minimum_required (VERSION 2.6)
project (training)

file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

add_executable(training main.cpp ${SOURCE_FILES})