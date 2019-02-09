cmake_minimum_required(VERSION 3.9)

project(learnopengl)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)
#find_package(assimp REQUIRED)

find_library(
        assimp_LIBRARIES
        NAMES assimp
)

set(SRCS src/main.cpp src/main.cpp src/Shader.cpp src/Shader.h src/stb_image_setup.cpp src/Camera.cpp src/Camera.h src/Mesh.cpp src/Mesh.h src/Model.cpp src/Model.h)

set(VENDOR_SRCS vendor/src/glad.c vendor/includes/stb_image.h)

add_executable(${PROJECT_NAME} ${SRCS} ${VENDOR_SRCS})

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
#link_libraries(${PROJECT_NAME} ${ASSIMP_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ${assimp_LIBRARIES})

add_custom_target(
        copy_assets
        ${CMAKE_COMMAND}
        -D SOURCE_DIR=${CMAKE_SOURCE_DIR}
        -D DESTINATION_DIR=${CMAKE_BINARY_DIR}
        -P ${CMAKE_SOURCE_DIR}/CopyAssets.cmake
        COMMENT "Copying Files for target: ${PROJECT_NAME}" VERBATIM
)

add_dependencies(${PROJECT_NAME} copy_assets)