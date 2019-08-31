cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
enable_testing()

project(VulkanTest_Application)

find_package(glm REQUIRED)

include(${CMAKE_SOURCE_DIR}/cmake/Utils.cmake)
set(SRC
    Application.cpp)

default_lib(${PROJECT_NAME} Application "${SRC}")

# Define the libraries this project depends upon
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    glfw
    vulkan
    VulkanTest_WindowsManager)
