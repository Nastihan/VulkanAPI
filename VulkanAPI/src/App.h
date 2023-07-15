#pragma once
#include "Window.h"

class App
{
public:
	void Run();
public: 
	static constexpr int width = 1600;
	static constexpr int height = 900;
private:
	Window window{width,height,"Vulkan"};
};