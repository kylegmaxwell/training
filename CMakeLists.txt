cmake_minimum_required (VERSION 2.6)
project (Training)

include_directories ("${PROJECT_SOURCE_DIR}/header")
add_subdirectory (header)
include_directories ("${PROJECT_SOURCE_DIR}/source")
add_subdirectory (source)

# add the executable
add_executable (Training main.cpp)

# add the install targets
install (TARGETS Tutorial DESTINATION bin)
#install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
 # DESTINATION include)
