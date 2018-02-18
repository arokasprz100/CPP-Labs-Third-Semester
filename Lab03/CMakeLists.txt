cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
#set (CMAKE_BUILD_TYPE Debug)

project (Obliczenia CXX)

#file(GLOB SRC "*.cpp")

set (
	SRC
	Main.cpp
	Iloczyn1.cpp
	Iloczyn2.cpp
	Iloczyn.cpp
	Kwadrat1.cpp
	PolozeniePoczatkowe.cpp
	Przyspieszenie.cpp
	Suma1.cpp
	Suma2.cpp

)

add_executable(Obliczenia ${SRC})

set (PATHS /usr/include/boost /usr/include/libxml2)

include_directories (${PATHS})


target_link_libraries(Obliczenia boost_system)



set (CMAKE_CXX_FLAGS_RELEASE "-Wall -DNODEBUG -DNDEBUG")

#set (CMAKE_CXX_FLAGS_DEBUG "-g -Wall")

#add_definitions (-DENGLISH)

option (ENGLISH ON)
IF (ENGLISH)
	set_target_properties(Obliczenia PROPERTIES COMPILE_FLAGS "-DENGLISH")
ENDIF (ENGLISH)

enable_testing()

add_executable (TestCzasu TestCzasu.cpp)

target_link_libraries(TestCzasu boost_system)

add_test (czas TestCzasu)

add_executable (TestSumy TestSumy.cpp)

add_test (suma TestSumy)
