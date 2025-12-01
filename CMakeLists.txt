cmake_minimum_required(VERSION 3.15)
project(AdventOfCode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ================================
# Build shared utils library
# ================================
set(UTILS_DIR "${CMAKE_SOURCE_DIR}/utils")

if(EXISTS "${UTILS_DIR}")
    file(GLOB_RECURSE UTILS_SOURCES
        "${UTILS_DIR}/*.cpp"
        "${UTILS_DIR}/*.hpp"
        "${UTILS_DIR}/*.h"
    )

    add_library(utils STATIC ${UTILS_SOURCES})

    # Put utils into its own VS folder
    set_target_properties(utils PROPERTIES
        FOLDER "utils"
    )
endif()

# ================================
# Build each Advent of Code day
# ================================
foreach(day RANGE 1 12)
    set(DAY_FOLDER "day${day}")
    set(DAY_PATH "${CMAKE_SOURCE_DIR}/${DAY_FOLDER}")

    if(EXISTS "${DAY_PATH}")
        # Glob all source/header files for the day
        file(GLOB_RECURSE DAY_SOURCES
            "${DAY_PATH}/*.cpp"
            "${DAY_PATH}/*.hpp"
            "${DAY_PATH}/*.h"
        )

        # Skip the day if no .cpp files exist
        if(DAY_SOURCES)
            add_executable(${DAY_FOLDER} ${DAY_SOURCES})

            # Link utils if available
            if(TARGET utils)
                target_link_libraries(${DAY_FOLDER} PRIVATE utils)
            endif()

            # Place in its own Visual Studio folder
            set_target_properties(${DAY_FOLDER} PROPERTIES
                FOLDER ${DAY_FOLDER}
            )

            # Add include path so day code can do: #include "utils/something.hpp"
            if(EXISTS "${UTILS_DIR}")
                target_include_directories(${DAY_FOLDER} PRIVATE ${UTILS_DIR})
            endif()
        endif()
    endif()
endforeach()
