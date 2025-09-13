cmake_minimum_required(VERSION 3.25.1)

project("open_maker" LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)

file(GLOB SRC ${CMAKE_SOURCE_DIR}/src/*.c)
set(INC ${CMAKE_SOURCE_DIR}/inc)
set(LIB ${CMAKE_SOURCE_DIR}/lib)

file(MAKE_DIRECTORY ${LIB})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB})

add_subdirectory(${CMAKE_SOURCE_DIR}/raylib)

add_library(${PROJECT_NAME} STATIC)

target_compile_options(${PROJECT_NAME} BEFORE PRIVATE -Wall -Werror -Wextra)
target_sources(${PROJECT_NAME} PRIVATE ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC})
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
