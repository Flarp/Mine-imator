#include "mineimator.h"

int main() {
	GLFWwindow* window;
	glfwSetErrorCallback(errorCallback);
	
	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(640, 480, "Mine-imator", NULL, NULL);
	windowMaximize(window);

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseCallback);


	GLuint texture1;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("image.png", &width, &height, 0, SOIL_LOAD_RGBA);

	std::cout << width << "x" << height << std::endl; 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	//glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.



	while (!glfwWindowShouldClose(window)) {
		int width, height;

		glfwGetWindowSize(window, &width, &height);

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, 0, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glBegin(GL_QUADS);
		glColor3d(1, 1, 1);
		glTexCoord2d(0, 0);
		glVertex2d(50, 50);
		glTexCoord2d(1, 0);
		glVertex2d(width - 50, 50);
		glTexCoord2d(1, 1);
		glVertex2d(width - 50, height - 50);
		glTexCoord2d(0, 1);
		glVertex2d(50, height - 50);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glLoadIdentity();

		drawBox(100, 100, 200, 200, true, colorMake(255, 152, 173), 1);
		drawBox(400, 50, 100, 200, true, colorMake(66, 34, 114), 1);
		drawGradient(0, height / 2, width, height / 2, colorMake(255, 255, 0), 0, 0, 1, 1);
		drawLine(0, 0, 100, 100, colorMake(80, 80, 80), 1);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void errorCallback(int error, const char* description) {
	std::cout << "Error " << error << ": " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void mouseCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		std::cout << "Click!" << std::endl;
}

void windowMaximize(GLFWwindow* window) {
#ifdef _WIN32
	glfwMaximizeWindow(window);
#else
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, 25, 25);
	glfwSetWindowSize(window, mode->width - 50, mode->height - 100);
#endif
}