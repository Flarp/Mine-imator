#include "draw.h"

void drawBox(int x, int y, int width, int height, bool fill, int color, double alpha) {
	glLoadIdentity();
	glTranslated(x, y, 0);

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
		
	glVertex3d(x, y, 0);
	glVertex3d(x + width, y, 0);
	glVertex3d(x + width, y + height, 0);
	glVertex3d(x, y + height, 0);

	glEnd();
}