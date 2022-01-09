cmake_minimum_required(VERSION 3.20)

project(opengl-renderer)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} 
    source/main.cpp
    
    source/window.h
    source/window.cpp
    source/context.h
    source/context.cpp
    source/renderer.h
    source/renderer.cpp
    source/shaderprogram.h
    source/shaderprogram.cpp
    source/vertexarray.h
    source/vertexarray.cpp
    source/texture.h
    source/texture.cpp
    source/camera.h
    source/camera.cpp

    source/input.h
    source/utils.h
    source/timer.h
    
    external/stb_image/stb_image.h
    external/stb_image/stb_image.cpp
)

#GLAD
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

#GLFW
add_subdirectory(external/glfw)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)
target_link_directories(${PROJECT_NAME} PUBLIC external/glfw/src)
target_link_libraries(${PROJECT_NAME} glfw)

#GLM
add_subdirectory(external/glm)
target_link_libraries(${PROJECT_NAME} glm)
