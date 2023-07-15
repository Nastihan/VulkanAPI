#include "App.h"

void App::Run()
{
	while (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}
