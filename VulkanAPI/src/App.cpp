#include "App.h"
#include "Device.h"
void App::Run()
{
	Device d{};
	
	while (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}
