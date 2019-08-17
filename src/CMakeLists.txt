# CMake files based on:
# https://rix0r.nl/blog/2015/08/13/cmake-guide/

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(MAIN_PROJECT_NAME "VulkanTest") # Equals to ${PROJECT_NAME} in this scope.
set(MAIN_PROJECT_VERSION "0.0.1")
project(
    ${MAIN_PROJECT_NAME}
    VERSION
        ${MAIN_PROJECT_VERSION}
    DESCRIPTION
        ""
    HOMEPAGE_URL
        ""
    LANGUAGES
        CXX)

option(TEST_DEPENDENCES "Build tests for dependences?" NO)
option(VULKAN_SDK_PATH"Absolute path to VulkanSDK" "")
        
# Must use GNUInstallDirs to install libraries into correct locations on all
# platforms.
include(GNUInstallDirs)

# Main project
add_subdirectory(VulkanTest)

# Required no-project libs.
add_subdirectory(VulkanTestDependences)
