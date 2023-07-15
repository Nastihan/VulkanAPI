#pragma once
#include "Window.h"
#include "Pipieline.h"
#include <string>
#include "Device.h"

class App
{
public:
	void Run();
public: 
	static constexpr int width = 1600;
	static constexpr int height = 900;
private:
	Pipeline p{ "Shaders/VS.vert.spv","Shaders/FS.frag.spv" };
	Device d;
	Window window{width,height,"Vulkan"};
};