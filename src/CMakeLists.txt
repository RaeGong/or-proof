include_directories(/usr/local/include)


set(SOURCE_FILES PaillierEncryption.cpp Prover.cpp Verifier.cpp)

add_library(src_stac STATIC ${SOURCE_FILES})

add_subdirectory(utils)

add_executable(main main.cpp)




