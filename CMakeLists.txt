cmake_minimum_required(VERSION 3.1)
set(PROJECTNAME Mine-imator)

project(${PROJECTNAME})

file(GLOB SRCS *.cpp *.h)

add_executable(Mine-imator ${SRCS})