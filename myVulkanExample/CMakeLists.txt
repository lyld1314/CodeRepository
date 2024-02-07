cmake_minimum_required(VERSION 3.21)

project(vulkan_main CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NoDebugCase "Release" "MinSizeRel")
if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE IN_LIST NoDebugCase))
    add_compile_definitions(NO_DEBUG)
endif()

find_package(Vulkan REQUIRED)

if(NOT Vulkan_FOUND)
    MESSAGE(FATAL_ERROR "Can't find Vulkan package")
endif()

if (NOT TARGET Vulkan::glslangValidator)
    message(FATAL_ERROR "Could not find glslangValidator")
endif ()

set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/glfw-3.3.9.bin.WIN64/include/")
set(GLFW_LIB_DIR "${CMAKE_SOURCE_DIR}/glfw-3.3.9.bin.WIN64/lib-mingw-w64/")
set(GLFW_LIBS "glfw3")

add_subdirectory(HelloTriangle)