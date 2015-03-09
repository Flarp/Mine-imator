#pragma once
#include "../mineimator.h"

class Image {
public:
	Image(const char *filename);
	Image(void *data);
	GLuint texture;
	int width, height;
};