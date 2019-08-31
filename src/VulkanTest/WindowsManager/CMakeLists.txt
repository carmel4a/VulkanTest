cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
enable_testing()

project(VulkanTest_WindowsManager)

include(${CMAKE_SOURCE_DIR}/cmake/Utils.cmake)

set(SRC WindowsManager.cpp
        GlfwWindowsManager.cpp
        GlfwWindowHandler.cpp)

default_lib(${PROJECT_NAME} WindowsManager "${SRC}")

# Define the libraries this project depends upon
target_link_libraries(
    ${PROJECT_NAME}
    glfw
    vulkan)
