# List all headers here
set(HEADER_LIST ${PROJECT_SOURCE_DIR}/include/sorting/sorting.h)

# List all source here
set(SOURCE_LIST sorting.cpp)

add_library(libsorting STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(libsorting PRIVATE project_options project_warnings)

# We need this directory, and users of our library will need it too
target_include_directories(libsorting PUBLIC ${PROJECT_SOURCE_DIR}/include)
