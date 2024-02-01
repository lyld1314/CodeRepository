set(TRIANGLE_SRC_FILE HelloTriangle.cpp)
set(SUB_PROJECT_NAME "HelloTriangle")

include_directories(${Vulkan_INCLUDE_DIR})

include_directories(${GLFW_INCLUDE_DIR})
link_directories(${GLFW_LIB_DIR})

add_executable(${SUB_PROJECT_NAME} ${TRIANGLE_SRC_FILE})
target_link_libraries(${SUB_PROJECT_NAME} ${Vulkan_LIBRARY} ${GLFW_LIBS})

add_custom_target(__complier_shader_HelloTriangle
    COMMAND Vulkan::glslc ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.vert -o ${CMAKE_CURRENT_BINARY_DIR}/vert.spv
    COMMAND Vulkan::glslc ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.frag -o ${CMAKE_CURRENT_BINARY_DIR}/frag.spv
    COMMENT "--Compile shader used in triangle project--"
    )

add_dependencies(${SUB_PROJECT_NAME} __complier_shader_HelloTriangle)
