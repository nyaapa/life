cmake_minimum_required(VERSION 2.8)

project(Life)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2.4 COMPONENTS graphics audio network window system)

file(GLOB SOURCE "include/*.h" "include/*.hpp" "src/*.cpp")

set(SFML_STATIC_LIBRARIES true)
set(CMAKE_CXX_COMPILER "/usr/bin/clang")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -DSFML_STATIC")
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SFML_INCLUDE_DIR})
add_executable(Life ${SOURCE})
target_link_libraries(Life ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} stdc++)

#message(FATAL_ERROR ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}) 