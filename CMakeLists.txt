cmake_minimum_required(VERSION 2.9)

project(TRI)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(TRI src/main.cpp includes/glad/src/glad.c "includes/settings/settings.hpp")

include_directories("includes" "includes/glad/include" "includes/glfw")

add_subdirectory("includes/glfw/glfw-3.3.4")
target_link_libraries(TRI glfw)