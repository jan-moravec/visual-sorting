# Enable doxygen doc builds of source
function(enable_doxygen)
    # If not specified, use the top readme file as the first page
    if((NOT DOXYGEN_USE_MDFILE_AS_MAINPAGE) AND EXISTS "${PROJECT_SOURCE_DIR}/README.md")
        set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/README.md")
    endif()

    # set better defaults for doxygen
    set(DOXYGEN_CALLER_GRAPH YES)
    set(DOXYGEN_CALL_GRAPH YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    # svg files are much smaller than jpeg and png, and yet they have higher quality
    set(DOXYGEN_DOT_IMAGE_FORMAT svg)
    set(DOXYGEN_DOT_TRANSPARENT YES)

    # If not specified, exclude the vcpkg files and the files CMake downloads under _deps (like project_options)
    if(NOT DOXYGEN_EXCLUDE_PATTERNS)
        set(DOXYGEN_EXCLUDE_PATTERNS "${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/*" "${CMAKE_CURRENT_BINARY_DIR}/_deps/*")
    endif()

    # find doxygen and dot if available
    find_package(Doxygen REQUIRED OPTIONAL_COMPONENTS dot)

    # add doxygen-docs target
    message(STATUS "Adding `doxygen-docs` target that builds the documentation.")
    doxygen_add_docs(doxygen-docs ALL ${PROJECT_SOURCE_DIR} COMMENT "Generating documentation - entry file: ${CMAKE_CURRENT_BINARY_DIR}/html/index.html")
endfunction()
