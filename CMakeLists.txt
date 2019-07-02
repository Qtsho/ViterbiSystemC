#CMAKE file, written by Tien Tuan Faad


cmake_minimum_required( VERSION 2.8)
project(viterbi)

find_package(SystemCLanguage CONFIG REQUIRED)

include_directories(include)

set (CMAKE_CXX_STANDARD ${SystemC_CXX_STANDARD})

add_executable(${PROJECT_NAME}
	src/encoder.cpp
	src/driver.cpp
	src/testbench.cpp
	src/viterbi_decoder.cpp
	include/driver.h
	include/encoder.h
	include/viterbi_decoder.h
	)

target_link_libraries(${PROJECT_NAME}
	SystemC::systemc)
