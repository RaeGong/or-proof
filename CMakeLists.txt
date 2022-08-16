cmake_minimum_required(VERSION 3.14)
project(or_proof)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)


enable_testing()
add_subdirectory(deps/googletest-release-1.10.0)
include_directories(deps/googletest-release-1.10.0/googletest/include)
include_directories(/usr/local/include)

add_subdirectory(test)





