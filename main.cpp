#define GLFW_INCLUDE_VULKAN // will include vulkan/vulkan.h
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>          // EXIT_SUCCESS and EXIT_FAILURE

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class TriSoHard {
private:
	VkInstance instance;
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
		createInstance();
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

	void createInstance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "TriSoHard";
		appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
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
