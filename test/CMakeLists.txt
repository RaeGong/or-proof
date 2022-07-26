
add_executable(runTest test.cpp)
target_link_libraries(runTest gtest gtest_main)

add_test(NAME runTest COMMAND runTest)