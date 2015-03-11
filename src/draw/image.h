#pragma once
#include "../mineimator.h"
using namespace std;

class Image {
public:
	Image(wstring filename);
	Image(void *data);
	GLuint texture;
	int width, height;
};