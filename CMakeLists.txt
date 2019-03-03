cmake_minimum_required(VERSION 3.10)

project(blink)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

find_library(
        assimp_LIBRARIES
        NAMES assimp
)

set(VENDOR_SRCS vendor/src/glad.c vendor/includes/stb_image.h src/graphics/VertexBuffer.cpp src/graphics/VertexBuffer.h)

set(
    SOURCES
        src/Game.cpp
        src/graphics/Shader.cpp
        src/graphics/stb_image_setup.cpp
        src/graphics/Mesh.cpp
        src/graphics/Model.cpp
        src/graphics/VertexArray.cpp
        src/graphics/Rendering.cpp
        src/graphics/Texture.cpp
        src/Entity.cpp
        src/World.cpp
        src/components/CameraComponent.cpp
        src/components/TransformComponent.cpp
        src/components/DynamicComponent.h
        src/systems/DynamicSystem.cpp
        src/systems/DynamicSystem.h
        src/components/ModelComponent.cpp
        src/components/ModelComponent.h
        src/systems/ModelSystem.cpp
        src/systems/ModelSystem.h src/components/LightComponent.cpp src/components/LightComponent.h src/systems/ShaderSystem.cpp src/systems/ShaderSystem.h src/graphics/UniformBlock.cpp src/graphics/UniformBlock.h)

#set(
#    HEADERS
#        src/Game.h
#        src/graphics/Shader.h
#        src/Mesh.h
#        src/Model.h
#        src/graphics/Rendering.h
#        src/graphics/Texture.h
#        src/graphics/VertexArray.h
#        src/graphics/VertexBuffer.h
#        src/GameObject.h
#        src/Component.h
#        src/components/TransformComponent.h
#        src/components/CameraComponent.h
#)

add_library(${PROJECT_NAME} ${SOURCES} ${VENDOR_SRCS})

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
