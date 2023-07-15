#pragma once
#include "Window.h"
#include "Pipieline.h"
#include <string>

class App
{
public:
	void Run();
public: 
	static constexpr int width = 1600;
	static constexpr int height = 900;
private:
	Pipeline p{ "Shaders/VS.vert.spv","Shaders/FS.frag.spv" };
	Window window{width,height,"Vulkan"};
};