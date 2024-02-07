set(TRIANGLE_SRC_FILE HelloTriangle.cpp)
set(SUB_PROJECT_NAME "HelloTriangle")

include_directories(${Vulkan_INCLUDE_DIR})

include_directories(${GLFW_INCLUDE_DIR})
link_directories(${GLFW_LIB_DIR})

add_executable(${SUB_PROJECT_NAME} ${TRIANGLE_SRC_FILE})
target_link_libraries(${SUB_PROJECT_NAME} ${Vulkan_LIBRARY} ${GLFW_LIBS})

add_custom_command(TARGET ${SUB_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "The executable file for ${SUB_PROJECT_NAME} project at: $<TARGET_FILE:${SUB_PROJECT_NAME}>"        
)

add_custom_target("__complier_shader_${SUB_PROJECT_NAME}"
    COMMAND Vulkan::glslangValidator -V ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.vert -o ${CMAKE_CURRENT_BINARY_DIR}/vert.spv
    COMMAND Vulkan::glslangValidator -V ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.frag -o ${CMAKE_CURRENT_BINARY_DIR}/frag.spv
    COMMENT "--Compile shader used in ${SUB_PROJECT_NAME} project--"
    )

add_dependencies(${SUB_PROJECT_NAME} "__complier_shader_${SUB_PROJECT_NAME}")
