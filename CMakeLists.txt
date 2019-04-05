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


# documentation ########################################################

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)