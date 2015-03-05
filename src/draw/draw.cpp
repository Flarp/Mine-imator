#include "draw.h"

void drawBox(int x, int y, int width, int height, bool fill, int color, double alpha) {
	glColor4d(
		colorGetRed(color) / 255.0,
		colorGetGreen(color) / 255.0,
		colorGetBlue(color) / 255.0,
		alpha
	);

	if (fill)
		glBegin(GL_QUADS);
	else
		glBegin(GL_LINE_LOOP);
		
	glVertex2d(x, y);
	glVertex2d(x + width, y);
	glVertex2d(x + width, y + height);
	glVertex2d(x, y + height);

	glEnd();
}

void drawGradient(int x, int y, int width, int height, int color, double alphaTopLeft, double alphaTopRight, double alphaBottomRight, double alphaBottomLeft) {
	double r, g, b;

	r = colorGetRed(color) / 255.0;
	g = colorGetGreen(color) / 255.0;
	b = colorGetBlue(color) / 255.0;

	glBegin(GL_QUADS);

	glColor4d(r, g, b, alphaTopLeft);
	glVertex2d(x, y);
	glColor4d(r, g, b, alphaTopRight);
	glVertex2d(x + width, y);
	glColor4d(r, g, b, alphaBottomRight);
	glVertex2d(x + width, y + height);
	glColor4d(r, g, b, alphaBottomLeft);
	glVertex2d(x, y + height);

	glEnd();
}

void drawLine(int x1, int y1, int x2, int y2, int color, double alpha) {
	glColor4d(
		colorGetRed(color) / 255.0,
		colorGetGreen(color) / 255.0,
		colorGetBlue(color) / 255.0,
		alpha
	);

	glBegin(GL_LINES);

	glVertex2d(x1, y1);
	glVertex2d(x2, y2);

	glEnd();
}