#include "App.h"
#include "Device.h"
void App::Run()
{
	Device d;
	d.CreateInstance();
	while (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}
