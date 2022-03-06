include(FetchContent)

set(ENABLE_VCPKG_UPDATE TRUE)

if(DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "Use system vcpkg at ${CMAKE_TOOLCHAIN_FILE}")
else()
    message(STATUS "Use local vcpkg")
    # Default vcpkg installation directory
    set(VCPKG_PARENT_DIR ${CMAKE_SOURCE_DIR})
    set(VCPKG_DIR_NAME .vcpkg)
    set(VCPKG_DIR ${VCPKG_PARENT_DIR}/${VCPKG_DIR_NAME})

    # check if vcpkg is installed
    if(WIN32 AND "${CMAKE_EXECUTABLE_SUFFIX}" STREQUAL "")
        set(CMAKE_EXECUTABLE_SUFFIX ".exe")
    endif()
    if(EXISTS "${VCPKG_DIR}" AND EXISTS "${VCPKG_DIR}/vcpkg${CMAKE_EXECUTABLE_SUFFIX}")
        message(STATUS "vcpkg is already installed at ${VCPKG_DIR}.")
        if(${ENABLE_VCPKG_UPDATE})
            message(STATUS "Updating the repository...")
            execute_process(COMMAND "git" "pull" WORKING_DIRECTORY ${VCPKG_DIR})
        endif()
    else()
        message(STATUS "Installing vcpkg at ${VCPKG_DIR}")
        # clone vcpkg from Github
        set(VCPKG_URL "https://github.com/microsoft/vcpkg.git")
        find_program(GIT_EXECUTABLE "git" REQUIRED)
        execute_process(COMMAND "${GIT_EXECUTABLE}" "clone" "${VCPKG_URL}" "${VCPKG_DIR_NAME}" WORKING_DIRECTORY ${VCPKG_PARENT_DIR} COMMAND_ERROR_IS_FATAL
                                                                                                                 LAST)
        # Run vcpkg bootstrap
        if(WIN32)
            execute_process(COMMAND "bootstrap-vcpkg.bat" "-disableMetrics" WORKING_DIRECTORY "${VCPKG_DIR}" COMMAND_ERROR_IS_FATAL LAST)
        else()
            execute_process(COMMAND "./bootstrap-vcpkg.sh" "-disableMetrics" WORKING_DIRECTORY "${VCPKG_DIR}" COMMAND_ERROR_IS_FATAL LAST)
        endif()
    endif()

    # Setting up vcpkg toolchain
    set(CMAKE_TOOLCHAIN_FILE
        ${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "vcpkg toolchain file")
endif()
