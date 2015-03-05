#pragma once
#include "../color.h"

// Creates a new color with the given red, green and blue values between 0-255.
int colorMake(int r, int g, int b);

// Returns the red value of the given color (0-255).
int colorGetRed(int color);

// Returns the green value of the given color (0-255).
int colorGetGreen(int color);

// Returns the blue value of the given color (0-255).
int colorGetBlue(int color);