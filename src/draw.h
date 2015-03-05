#pragma once
#include "mineimator.h"

// Draws a box at a position with the given dimensions and color.
// If fill is false, the box is outlined.
void drawBox(int x, int y, int width, int height, bool fill, int color, double alpha);

// Draws a gradient effect at a position with the given dimensions and color.
void drawGradient(int x, int y, int width, int height, int color, double alphaTopLeft, double alphaTopRight, double alphaBottomRight, double alphaBottomLeft);