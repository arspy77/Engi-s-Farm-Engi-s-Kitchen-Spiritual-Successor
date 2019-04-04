cmake_minimum_required(VERSION 2.8)
project(EngiFarm) 

include_directories(
	include/EngiFarm
	include/EngiFarm/Cell
	include/EngiFarm/FarmAnimal
	include/EngiFarm/Product
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
 
file(GLOB cell_SRC
	"src/Cell/*.cpp"
)

file(GLOB farmAnimal_SRC
	"src/FarmAnimal/*.cpp"
)

file(GLOB product_SRC
	"src/Product/*.cpp"
)

add_executable(EngiFarm
	src/main.cpp
	src/LivingThing.cpp
	src/Player.cpp
	src/World.cpp
	${cell_SRC}
	${farmAnimal_SRC}
	${product_SRC}
)