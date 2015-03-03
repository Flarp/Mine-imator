cmake_minimum_required(VERSION 3.1)

# Set project
set(PROJECTNAME Mine-imator)
project(${PROJECTNAME})

# Add files
file(GLOB SRCS *.cpp *.h)
add_executable(${PROJECTNAME} ${SRCS})

# Add GLFW
add_subdirectory(glfw)
include_directories(glfw/include)
target_link_libraries(${PROJECTNAME} glfw ${GLFW_LIBRARIES})