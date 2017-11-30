cmake_minimum_required (VERSION 2.6)
project (training)

macro(use_cxx14)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 14)
  endif ()
endmacro(use_cxx14)

use_cxx14()


file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

add_executable(training main.cpp ${SOURCE_FILES})