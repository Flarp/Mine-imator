#pragma once
#include "mineimator.h"

// Draws a box at a position with the given dimensions and color.
// If fill is false, the box is outlined.
void drawBox(int x, int y, int width, int height, bool fill, int color, double alpha);