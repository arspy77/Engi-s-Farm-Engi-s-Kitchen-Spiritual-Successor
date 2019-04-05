cmake_minimum_required(VERSION 2.8)
project(EngiFarm) 

# file globbing ########################################################

file(GLOB_RECURSE sources 
	src/*.cpp 
	src/Cell/*.cpp 
	src/FarmAnimal/*.cpp 
	src/Product/*.cpp
)

file(GLOB_RECURSE to_remove src/main.cpp)
list(REMOVE_ITEM sources ${to_remove})

file(GLOB_RECURSE testers
	test/*.cpp
)

# packaging ############################################################

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS -pthread)


# target definitions ###################################################

include_directories(
	include/EngiFarm
	include/EngiFarm/Cell
	include/EngiFarm/FarmAnimal
	include/EngiFarm/Product
)

add_executable(EngiFarm ${sources} src/main.cpp)

# testing ##############################################################

set(CMAKE_CXX_CPPCHECK "cppcheck")

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(EngiFarmTest ${testers} ${sources})
target_link_libraries(EngiFarmTest pthread gmock gtest gtest_main)
add_test(NAME AllTest COMMAND EngiFarmTest)