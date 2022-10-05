cmake_minimum_required(VERSION 3.13)

if (CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Source and build directories cannot be the same.")
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(cpp_test)

file(GLOB_RECURSE LIB_SOURCE
  lib/*.cpp*
)

add_executable(cpp_test
  main.cpp
)

# target_include_directories(
#   cpp_test PRIVATE 
#   lib/cmsis/include/dsp
#   )

# target_compile_definitions(cpp_test PUBLIC ARM_MATH_CM0PLUS)

target_compile_options(
  cpp_test PRIVATE
  -Wall
)

# target_link_libraries(
#   cpp_test
#   # ${CMAKE_SOURCE_DIR}/lib/cmsis/libCMSISDSPSVM.a
# )
