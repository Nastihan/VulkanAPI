#pragma once
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <string>

class Window
{
public:
	Window(int width, int height, std::string name);
	Window(const Window& ) = delete;
	Window& operator=(const Window&) = delete;
	bool ShouldClose()
	{
		return glfwWindowShouldClose(pWindow);
	}
	void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
	~Window();

private:
	void InitWindow();

private:
	std::string name;
	const int width;
	const int height;
	GLFWwindow* pWindow;
};