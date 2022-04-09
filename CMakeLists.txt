cmake_minimum_required(VERSION 3.20)

project(opengl-renderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/external/stb_image

    ${PROJECT_SOURCE_DIR}/source/engine/
    ${PROJECT_SOURCE_DIR}/source/engine/events
    ${PROJECT_SOURCE_DIR}/source/engine/input
    ${PROJECT_SOURCE_DIR}/source/engine/renderer
    ${PROJECT_SOURCE_DIR}/source/engine/utils
)

add_executable(${PROJECT_NAME} 
    external/stb_image/stb_image.cpp
    
    source/engine/main.cpp
    source/engine/application.cpp
    source/engine/input/keys.cpp
    source/engine/renderer/camera.cpp
    source/engine/renderer/context.cpp
    source/engine/renderer/renderer.cpp
    source/engine/renderer/shaderprogram.cpp
    source/engine/renderer/texture.cpp
    source/engine/renderer/vertexarray.cpp
    source/engine/renderer/window.cpp
)

# GLAD
add_subdirectory(external/glad)

set(GLAD_ALL_EXTENSIONS ON CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} glad)

# GLFW
add_subdirectory(external/glfw)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)
target_link_directories(${PROJECT_NAME} PUBLIC external/glfw/src)
target_link_libraries(${PROJECT_NAME} glfw)

# GLM
add_subdirectory(external/glm)
target_link_libraries(${PROJECT_NAME} glm)

# FMT
add_subdirectory(external/fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
