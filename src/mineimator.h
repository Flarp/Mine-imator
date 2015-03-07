#pragma once

#include <iostream>
#include <stdlib.h>

#include <GLFW/glfw3.h>
//#include <glew.h>
#include <SOIL.h>

#include "draw/draw.h"
#include "draw/color.h"
#include "project/project.h"

// GLFW
void errorCallback(int error, const char* description);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow* window, int button, int action, int mods);

// Window
void windowMaximize(GLFWwindow* window);