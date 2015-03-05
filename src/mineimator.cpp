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


	while (!glfwWindowShouldClose(window)) {
		float ratio;
		int width, height;

		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, 0, 1);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();

		drawBox(100, 100, 200, 200, true, colorMake(33, 152, 173), 1);
		drawBox(300, 50, 100, 200, true, colorMake(66, 34, 114), 1);

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