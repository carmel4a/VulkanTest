cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
enable_testing()

add_subdirectory(Application)
add_subdirectory(WindowsManager)

set(SRC
    main.cpp)

include(${CMAKE_SOURCE_DIR}/cmake/Utils.cmake)
default_exe(${PROJECT_NAME} "" "${SRC}")

# Define the libraries this project depends upon
target_link_libraries(
    ${PROJECT_NAME}
    VulkanTest_Application
    )
