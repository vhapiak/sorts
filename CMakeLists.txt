cmake_minimum_required(VERSION 2.8)

project(sorts)
file(GLOB_RECURSE SOURCES *.cpp)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}
)
