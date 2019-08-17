cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
enable_testing()

find_package(glm REQUIRED)
find_library(VULKAN_PATH vulkan REQUIRED)
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

# Define the libraries this project depends upon
target_link_libraries(
    ${PROJECT_NAME}
    glm
    glfw
    vulkan)
