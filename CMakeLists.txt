cmake_minimum_required(VERSION 3.20)

# Determine if this is built as a subproject (using add_subdirectory) or if it is the master project.
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(IS_MASTER_PROJECT ON)
endif()

# Add Vcpkg support - it's the package manager of my choice
if(IS_MASTER_PROJECT)
    include(cmake/Vcpkg.cmake)
endif()

project(
    VisualSorting
    VERSION 0.2.2
    DESCRIPTION "Sorting Algorithms"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Additional scripts and functions
include(cmake/StandardProjectSettings.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/PreventInSourceBuilds.cmake)
include(cmake/Cache.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/Doxygen.cmake)

# Enable desired functionality
enable_cppcheck()
enable_clang_tidy()
enable_cache()
enable_testing()

# Create header with project version
configure_file(cmake/version.h.in ${CMAKE_SOURCE_DIR}/include/sorting/version.h @ONLY)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# Set compiler warnings and enable warnings as error
if(IS_MASTER_PROJECT)
    set(WARNINGS_AS_ERRORS ON)
    set_project_warnings(project_warnings ${WARNINGS_AS_ERRORS})
endif()

# Additional libraries
find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

# The compiled library code is here
add_subdirectory(src)
# The executable code is here
add_subdirectory(app)
# The unit tests code is here
add_subdirectory(test)
