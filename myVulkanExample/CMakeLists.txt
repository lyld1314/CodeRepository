cmake_minimum_required(VERSION 3.12)

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

set(TRIANGLE_SRC_FILE triangle.cpp)

include_directories(${Vulkan_INCLUDE_DIR})

include_directories("./glfw-3.3.9.bin.WIN64/include/")
link_directories("./glfw-3.3.9.bin.WIN64/lib-mingw-w64/")

add_executable(triangle_exe ${TRIANGLE_SRC_FILE})
target_link_libraries(triangle_exe ${Vulkan_LIBRARY} glfw3)
