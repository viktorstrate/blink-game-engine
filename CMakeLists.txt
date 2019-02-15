cmake_minimum_required(VERSION 3.9)

project(blink)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

find_library(
        assimp_LIBRARIES
        NAMES assimp
)

set(VENDOR_SRCS vendor/src/glad.c vendor/includes/stb_image.h src/VertexBuffer.cpp src/VertexBuffer.h)

set(
    SOURCES
        src/Game.cpp
        src/Shader.cpp
        src/stb_image_setup.cpp
        src/components/CameraComponent.cpp
        src/Mesh.cpp
        src/Model.cpp
        src/VertexArray.cpp
        src/Rendering.cpp
        src/Texture.cpp
        src/GameObject.cpp
        src/components/TransformComponent.cpp
)

set(
    HEADERS
        src/Game.h
        src/Shader.h
        src/Mesh.h
        src/Model.h
        src/Rendering.h
        src/Texture.h
        src/VertexArray.h
        src/VertexBuffer.h
        src/GameObject.h
        src/Component.h
        src/components/TransformComponent.h
        src/components/CameraComponent.h
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${VENDOR_SRCS})

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
)

include_directories(src/)
include_directories(vendor/includes)

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})

target_link_libraries(${PROJECT_NAME} glfw)

target_include_directories(${PROJECT_NAME} PUBLIC ${ASSIMP_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${assimp_LIBRARIES})

set(BLINK_LIBRARIES blink PARENT_SCOPE)
set(BLINK_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/src/ ${CMAKE_CURRENT_LIST_DIR}/vendor/includes/ PARENT_SCOPE)
