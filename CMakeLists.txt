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

# Add SOIL
include_directories(dep/soil)
add_library(soil STATIC
	dep/soil/image_helper.c
	dep/soil/stb_image_aug.c
	dep/soil/image_DXT.c
	dep/soil/SOIL.c
)
  
# Finally, link the libraries
target_link_libraries(Mine-imator soil glfw ${GLFW_LIBRARIES})