cmake_minimum_required (VERSION 3.9)

project (learnopengl)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

set(SRCS src/main.cpp src/main.cpp)

set(VENDOR_SRCS vendor/src/glad.c)

add_executable(${PROJECT_NAME} ${SRCS} ${VENDOR_SRCS})

include_directories(src/)
include_directories(vendor/includes)

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${OPENGL_gl_LIBRARY})

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC glfw)