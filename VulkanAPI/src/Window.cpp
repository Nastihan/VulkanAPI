#include "Window.h"
#include <stdexcept>

Window::Window(int width, int height, std::string name)
	: width{ width }, height(height), name(name)
{
	InitWindow();
}

void Window::CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
{
	if (glfwCreateWindowSurface(instance, pWindow, nullptr, surface) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create window surface");
	}
}

Window::~Window()
{
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}

void Window::InitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	pWindow = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}
