#include "Window.h"

Window::Window(int width, int height, std::string name)
	: width{ width }, height(height), name(name)
{
	InitWindow();
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
