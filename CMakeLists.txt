cmake_minimum_required(VERSION 3.25.1)

project("open_maker" LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)

file(GLOB SRC ${CMAKE_SOURCE_DIR}/src/*.c)
set(INC ${CMAKE_SOURCE_DIR}/inc)

add_library(${PROJECT_NAME} STATIC)
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_compile_options(${PROJECT_NAME} BEFORE PRIVATE -Wall -Werror -Wextra)
target_sources(${PROJECT_NAME} PRIVATE ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC})
