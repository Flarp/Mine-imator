#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include <GLFW/glfw3.h>
//#include <glew.h>
#include <SOIL.h>
#include "filedialog.h"
#include "zlib.h"
#include "zip.h"

#include "draw/draw.h"
#include "draw/color.h"
#include "draw/image.h"
#include "project/project.h"

using namespace std;

// GLFW
void errorCallback(int error, const char* description);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow* window, int button, int action, int mods);

// Window
void windowMaximize(GLFWwindow* window);