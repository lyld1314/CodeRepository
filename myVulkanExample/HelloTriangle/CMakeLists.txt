set(TRIANGLE_SRC_FILE HelloTriangle.cpp)

include_directories(${Vulkan_INCLUDE_DIR})

include_directories(${GLFW_INCLUDE_DIR})
link_directories(${GLFW_LIB_DIR})

add_executable(triangle_exe ${TRIANGLE_SRC_FILE})
target_link_libraries(triangle_exe ${Vulkan_LIBRARY} ${GLFW_LIBS})

add_custom_target(complier_shader_HelloTriangle
    COMMAND glslc ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.vert -o ${CMAKE_CURRENT_BINARY_DIR}/vert.spv
    COMMAND glslc ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.frag -o ${CMAKE_CURRENT_BINARY_DIR}/frag.spv
    COMMENT "Compile shader used in triangle project"
    )

add_dependencies(triangle_exe complier_shader_HelloTriangle)
