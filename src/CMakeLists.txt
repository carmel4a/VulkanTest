# CMake files based on:
# https://rix0r.nl/blog/2015/08/13/cmake-guide/

cmake_minimum_required(
    VERSION 3.2
    FATAL_ERROR)

set(MAIN_PROJECT_VERSION "0.0.1")
project(
    "VulkanTest"
    VERSION
        0.0.1
    DESCRIPTION
        ""
    HOMEPAGE_URL
        ""
    LANGUAGES
        CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

option(TEST_DEPENDENCES "Build tests for dependences?" NO)
option(VULKAN_SDK_PATH"Absolute path to VulkanSDK" "")
        
# Must use GNUInstallDirs to install libraries into correct locations on all
# platforms.
include(GNUInstallDirs)

# Main project
add_subdirectory(VulkanTest)

# Required no-project libs.
add_subdirectory(VulkanTestDependences)
