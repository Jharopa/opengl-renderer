cmake_minimum_required(VERSION 3.20)

project(opengl-renderer)

set(CMAKE_CXX_STANDARD 17)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

include_directories(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/external/stb_image
    
    ${PROJECT_SOURCE_DIR}/source/engine/
    ${PROJECT_SOURCE_DIR}/source/engine/events
    ${PROJECT_SOURCE_DIR}/source/engine/input
    ${PROJECT_SOURCE_DIR}/source/engine/renderer
    ${PROJECT_SOURCE_DIR}/source/engine/utilities
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

target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_CURRENT_LIST_DIR}/source"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glad::glad
    glfw
    imgui::imgui
    glm::glm
    fmt::fmt
)
