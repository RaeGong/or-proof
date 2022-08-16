include_directories(/usr/local/include)

set(UTILS_FILES ConvertUtils.cpp Timer.cpp)

add_library(utils_stac STATIC ${UTILS_FILES})

