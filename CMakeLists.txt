cmake_minimum_required(VERSION 3.20)

project(opengl-renderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/external/stb_image

    ${PROJECT_SOURCE_DIR}/source
    ${PROJECT_SOURCE_DIR}/source/utils
    ${PROJECT_SOURCE_DIR}/source/events
    ${PROJECT_SOURCE_DIR}/source/input
    ${PROJECT_SOURCE_DIR}/source/platform
    ${PROJECT_SOURCE_DIR}/source/platform/platformwin32
    ${PROJECT_SOURCE_DIR}/source/platform/platformlinux
    ${PROJECT_SOURCE_DIR}/source/platform/renderer
)

add_executable(${PROJECT_NAME} 
    external/stb_image/stb_image.cpp
    
    source/pch.cpp
    source/main.cpp
    source/application.cpp
    source/window.cpp
    source/input/keys.cpp
    source/platform/platformwin32/windowwin32.cpp
    source/renderer/camera.cpp
    source/renderer/context.cpp
    source/renderer/renderer.cpp
    source/renderer/shaderprogram.cpp
    source/renderer/texture.cpp
    source/renderer/vertexarray.cpp
)

# PCH
target_precompile_headers(${PROJECT_NAME} 
    PRIVATE
        ${PROJECT_SOURCE_DIR}/source/pch.h
)

# GLAD
add_subdirectory(external/glad)
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
