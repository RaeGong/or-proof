include_directories(/usr/local/include)

set(TESTS_FILES test.cpp Paillier_test.cpp Verifier_test.cpp 
    Prover_test.cpp app_test.cpp)

find_package(OpenSSL)
if (${OPENSSL_FOUND})
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

add_executable(runTest test.cpp)
add_executable(runPaillierTest Paillier_test.cpp)
add_executable(runVerifierTest Verifier_test.cpp)
add_executable(runProverTest Prover_test.cpp)
add_executable(runAppTest app_test.cpp)
add_executable(runAllTest ${TESTS_FILES})

target_link_libraries(runAllTest gtest gtest_main)
target_link_libraries(runAllTest src_stac utils_stac)
target_link_libraries(runAllTest /usr/local/lib/libntl.a /usr/local/lib/libgmp.a OpenSSL::SSL OpenSSL::Crypto)

target_link_libraries(runTest gtest gtest_main)
target_link_libraries(runTest src_stac utils_stac)
target_link_libraries(runTest /usr/local/lib/libntl.a /usr/local/lib/libgmp.a OpenSSL::SSL OpenSSL::Crypto)


target_link_libraries(runPaillierTest src_stac utils_stac)
target_link_libraries(runPaillierTest gtest gtest_main)
target_link_libraries(runPaillierTest /usr/local/lib/libntl.a /usr/local/lib/libgmp.a OpenSSL::SSL OpenSSL::Crypto)


target_link_libraries(runVerifierTest src_stac utils_stac)
target_link_libraries(runVerifierTest gtest gtest_main)
target_link_libraries(runVerifierTest /usr/local/lib/libntl.a /usr/local/lib/libgmp.a OpenSSL::SSL OpenSSL::Crypto)

target_link_libraries(runProverTest src_stac utils_stac)
target_link_libraries(runProverTest gtest gtest_main)
target_link_libraries(runProverTest /usr/local/lib/libntl.a /usr/local/lib/libgmp.a OpenSSL::SSL OpenSSL::Crypto)

target_link_libraries(runAppTest src_stac utils_stac)
target_link_libraries(runAppTest gtest gtest_main)
target_link_libraries(runAppTest /usr/local/lib/libcrypto.a)
target_link_libraries(runAppTest /usr/local/lib/libntl.a /usr/local/lib/libgmp.a OpenSSL::SSL OpenSSL::Crypto)



# add_test(NAME runTest COMMAND runTest)
# add_test(NAME runPaillierTest COMMAND paillierTest)
