cmake_minimum_required(VERSION 3.13.4)
project(Math)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES Math/*.h Math/*.cpp Math/*.c)

if (WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Windows/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Windows/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Windows/bin)
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Linux/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Linux/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Linux/bin)
endif()

add_compile_options(-DBUILD_DLL)

if (WIN32)
    install(FILES ${CMAKE_BINARY_DIR}/Windows/bin/Math.dll DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/Export/Math/Windows)
else()
    install(FILES ${CMAKE_BINARY_DIR}/Linux/lib/Math.so DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/Export/Math/Linux)
endif()

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Math"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/Export/Math/Include"
        FILES_MATCHING PATTERN "*.h")

add_library(Math SHARED ${SOURCE_FILES})

set_target_properties(Math PROPERTIES PREFIX "")
set_target_properties(Math PROPERTIES OUTPUT_NAME "Math")
if (WIN32)
    set_target_properties(Math PROPERTIES SUFFIX ".dll")
else()
    set_target_properties(Math PROPERTIES SUFFIX ".so")
endif()


