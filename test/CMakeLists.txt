include(CTest)
include(Catch)

add_library(main OBJECT main.cpp)
target_link_libraries(main PUBLIC Catch2::Catch2)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE project_options project_warnings main libsorting)

catch_discover_tests(tests)
