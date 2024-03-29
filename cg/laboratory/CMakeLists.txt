cmake_minimum_required(VERSION 3.27)
project(laboratory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


# glfw, glm, assimp
# these are installed via homebrew
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(assimp REQUIRED)
set(LIBS ${LIBS} GLEW::GLEW glfw assimp::assimp)

# glad
#set(GLAD_DIR ${CMAKE_SOURCE_DIR}/glad)
#include_directories(${GLAD_DIR}/include)
#add_library(GLAD "${GLAD_DIR}/src/glad.c")
#set(LIBS ${LIBS} GLAD)

# stb_image
set(STB_IMAGE_DIR ${CMAKE_SOURCE_DIR}/stb_image)
include_directories(${STB_IMAGE_DIR})
add_library(STB_IMAGE "${STB_IMAGE_DIR}/stb_image.cpp")
set(LIBS ${LIBS} STB_IMAGE)

# imgui
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)
set(IMGUI
		${IMGUI_DIR}/imgui.cpp
		${IMGUI_DIR}/imgui_demo.cpp
		${IMGUI_DIR}/imgui_draw.cpp
		${IMGUI_DIR}/imgui_tables.cpp
		${IMGUI_DIR}/imgui_widgets.cpp
		${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
		${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)
set(SRCS ${SRCS} ${IMGUI})

# main
set(SRCS ${SRCS} main.cpp)

# link and build
add_executable(laboratory ${SRCS})
target_link_libraries(laboratory ${LIBS})