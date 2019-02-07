cmake_minimum_required (VERSION 3.9)

project (learnopengl)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

set(SRCS src/main.cpp src/main.cpp)

set(VENDOR_SRCS vendor/src/glad.c src/Shader.cpp src/Shader.h)

add_executable(${PROJECT_NAME} ${SRCS} ${VENDOR_SRCS})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        )

include_directories(src/)
include_directories(vendor/includes)

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${OPENGL_gl_LIBRARY})

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC glfw)

add_custom_target(
        copy_assets
        ${CMAKE_COMMAND}
        -D SOURCE_DIR=${CMAKE_SOURCE_DIR}
        -D DESTINATION_DIR=${CMAKE_BINARY_DIR}
        -P ${CMAKE_SOURCE_DIR}/CopyAssets.cmake
        COMMENT "Copying Files for target: ${PROJECT_NAME}" VERBATIM
)

add_dependencies(${PROJECT_NAME} copy_assets)