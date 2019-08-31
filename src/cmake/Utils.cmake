cmake_minimum_required(
    VERSION 3.2
    FATAL_ERROR)

macro(default_exe NAME_OF_TARGET MODULE_NAME SRC_LIST)
    cmake_policy(SET CMP0076 NEW)
    # Generate relative path from given list of filenames.
    set(NEW_SRC "")
    foreach(FILE_NAME ${SRC_LIST})
        list(APPEND NEW_SRC src/${MODULE_NAME}/${FILE_NAME})
    endforeach()

    add_executable(${NAME_OF_TARGET})
    target_sources(${PROJECT_NAME}
        PUBLIC
            ${NEW_SRC})
    set_target_properties(
        ${NAME_OF_TARGET}
        PROPERTIES
            CXX_STANDARD 20)

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    target_include_directories(
        ${PROJECT_NAME}
        PUBLIC 
            $<INSTALL_INTERFACE:include>    
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src)
        # INTERFACE
        #     include
        #     include/${MODULE_NAME}
        # PUBLIC
        #     include
        # PRIVATE
        #     include/${MODULE_NAME}
        #     src/${MODULE_NAME})
    cmake_policy(SET CMP0076 OLD)
endmacro()

macro(default_lib NAME_OF_TARGET MODULE_NAME SRC_LIST)
    cmake_policy(SET CMP0076 NEW)
    # Generate relative path from given list of filenames.
    set(NEW_SRC "")
    foreach(FILE_NAME ${SRC_LIST})
        list(APPEND NEW_SRC src/${MODULE_NAME}/${FILE_NAME})
    endforeach()

    add_library(${NAME_OF_TARGET})
    target_sources(${PROJECT_NAME}
        PUBLIC
            ${NEW_SRC})
    set_target_properties(
        ${NAME_OF_TARGET}
        PROPERTIES
            CXX_STANDARD 20)

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    message(STATUS "Module name: ${MODULE_NAME}")
    target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
            include
        PRIVATE
            include/${MODULE_NAME}
            src/${MODULE_NAME})
    cmake_policy(SET CMP0076 OLD)
endmacro()
