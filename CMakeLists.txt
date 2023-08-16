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
    ${PROJECT_SOURCE_DIR}/source/engine/memory
    ${PROJECT_SOURCE_DIR}/source/engine/math
    ${PROJECT_SOURCE_DIR}/source/engine/input
    ${PROJECT_SOURCE_DIR}/source/engine/renderer
    ${PROJECT_SOURCE_DIR}/source/engine/core
)

file(GLOB_RECURSE PROJECT_SOURCE CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(${PROJECT_NAME}  
    external/stb_image/stb_image.cpp
    ${PROJECT_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/source
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glad::glad
    glfw
    imgui::imgui
    glm::glm
    fmt::fmt
)
