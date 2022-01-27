cmake_minimum_required(VERSION 3.18)

project(aoc_helper)

set(SRC_FILES
    src/aoch/AOCSolutionsManager.cpp
    src/aoch/fileio.cpp
    src/aoch/math.cpp
    src/aoch/string.cpp
)

add_library(
    ${PROJECT_NAME}
    ${SRC_FILES}
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/includes")

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
