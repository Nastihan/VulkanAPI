#include "App.h"
#include "Device.h"
void App::Run()
{
	
	while (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}
