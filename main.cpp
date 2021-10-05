#define GLFW_INCLUDE_VULKAN // will include vulkan/vulkan.h
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>          // EXIT_SUCCESS and EXIT_FAILURE

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class TriSoHard {
private:
	GLFWwindow* window;

public:
	void run()
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	void initWindow()
	{
		glfwInit();

		// Need to tell it not to do a bunch of
		// OpenGL related shit, since we ain't using it.
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		// Window resizing iz hard, disable for now
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		// Create the window!
		// Width, height, title, monitor to open on (openGL only), 
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	void initVulkan()
	{

	}

	void mainLoop()
	{
		while(!glfwWindowShouldClose(window)){
			glfwPollEvents();
		}
	}

	void cleanup()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
};

int main()
{
	TriSoHard app;

	try {
		app.run();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
