cmake_minimum_required(VERSION 3.1)

# Set project
project(Mine-imator)

# Add files
file(GLOB_RECURSE SRCS
	${CMAKE_SOURCE_DIR}/src/*.cpp
	${CMAKE_SOURCE_DIR}/src/*.h
)
add_executable(Mine-imator ${SRCS})

# Add GLFW
add_subdirectory(dep/glfw)
include_directories(dep/glfw/include)
target_link_libraries(Mine-imator glfw ${GLFW_LIBRARIES})