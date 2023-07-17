#pragma once
#include "Window.h"
#include "Pipeline.h"
#include <string>
#include "Device.h"
#include "SwapChain.h"

class App
{
public:
	void Run();
public: 
	static constexpr int width = 1600;
	static constexpr int height = 900;
private:
	Window window{ width,height,"Vulkan" };
	Device device{ window };
	SwapChain swapChain{ device, window.GetExtent() };
	//Pipeline pipeline{ device, Pipeline::defaultPipelineConfigInfo(width, height), "shaders/simple_vertex_shader.vert.spv", "shaders/simple_fragment_shader.frag.spv" };

};