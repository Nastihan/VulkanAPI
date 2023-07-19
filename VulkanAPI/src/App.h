#pragma once
#include "Window.h"
#include "Pipeline.h"
#include <string>
#include "Device.h"
#include "SwapChain.h"
#include <memory>

class App
{
public:
	App();
	~App();
	void Run();
private:
	void CreatePipelineLayout();
	void CreatePipeline();
	void CreateCommandBuffers();
	

public: 
	static constexpr int width = 1600;
	static constexpr int height = 900;
private:
	Window window{ width,height,"Vulkan" };
	Device device{ window };
	SwapChain swapChain{ device, window.GetExtent() };
	std::unique_ptr<Pipeline> pipeline;
	VkPipelineLayout pipelineLayout;
	std::vector<VkCommandBuffer> commandBuffers;
};