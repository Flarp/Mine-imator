#include "color.h"

int colorMake(int r, int g, int b) {
	return (
		(r << 24) +
		(g << 16) +
		(b << 8)
	);
}

int colorGetRed(int color) {
	return (color >> 24) & 0xFF;
}

int colorGetGreen(int color) {
	return (color >> 16) & 0xFF;
}

int colorGetBlue(int color) {
	return (color >> 8) & 0xFF;
}