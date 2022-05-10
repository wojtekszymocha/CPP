cmake_minimum_required(VERSION 3.16)
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
#set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" CACHE PATH "" FORCE)
#set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" CACHE PATH "" FORCE)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(SHM)

set(CMAKE_CXX_STANDARD 17)

include_directories("includes/")
# file(GLOB SOURCES "sources/*.cpp")

set(SOURCES
    sources/Alcohol.cpp
    sources/Cargo.cpp
    sources/Fruit.cpp
    sources/Island.cpp
    sources/Item.cpp
    sources/Map.cpp
    sources/Player.cpp
    sources/Ship.cpp
    sources/Store.cpp
)


# add_executable(${PROJECT_NAME} sources/main.cpp)
include_directories("sources/")
add_library(${PROJECT_NAME}-lib ${SOURCES})
add_executable(${PROJECT_NAME} sources/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)


# Create libary for tests
# add_library(SHM_lib STATIC ${SOURCES})
set(TESTS
    tests/test.cpp
    tests/test_main.cpp
)

# enable_testing()



 link_libraries(gmock)
 add_executable(${PROJECT_NAME}-ut ${TESTS})
 target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib )
