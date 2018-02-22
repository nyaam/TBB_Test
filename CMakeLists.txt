cmake_minimum_required(VERSION 2.8)
project(test_TBB CXX)

# Set version information
SET(${PROJECT_NAME}_VERSION_MAJOR 1)
SET(${PROJECT_NAME}_VERSION_MINOR 0)
#add_definitions(-DLERI_VERSION=${LERI_TARGET_VERSION})


# Request C++11 explicitly on g++ and clang++
IF ( CMAKE_COMPILER_IS_GNUCXX )
  SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
ENDIF()
IF ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
  SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
ENDIF()

# Define sources and executable
ADD_EXECUTABLE(${PROJECT_NAME} test.cpp)

# Intel Threading Building Blocks
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
FIND_PACKAGE(TBB 4.4 REQUIRED
             # COMPONENTS # [tbbmalloc] [tbb_preview]
             # [OPTIONAL_COMPONENTS [tbbmalloc] [tbb_preview]]
                         )
INCLUDE_DIRECTORIES(${TBB_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}  ${TBB_tbb_LIBRARY_RELEASE}) ## tbb.dll
TARGET_LINK_LIBRARIES(${PROJECT_NAME}  ${TBB_tbb_LIBRARY_DEBUG})   ## tbb_debug.dll

## Install target
INSTALL(TARGETS ${PROJECT_NAME}  DESTINATION bin)
