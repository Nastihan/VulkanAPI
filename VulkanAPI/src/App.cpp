#include "App.h"
#include "Device.h"
#include <stdexcept>


App::App()
{
	CreatePipelineLayout();
	CreatePipeline();
}

App::~App()
{
	vkDestroyPipelineLayout(device.device(),pipelineLayout,nullptr);
}

void App::Run()
{
	
	while (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}

void App::CreatePipelineLayout()
{
	VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipelineLayoutInfo.setLayoutCount = 0;
	pipelineLayoutInfo.pSetLayouts = nullptr;
	pipelineLayoutInfo.pushConstantRangeCount = 0;
	pipelineLayoutInfo.pPushConstantRanges = nullptr;
	if (vkCreatePipelineLayout(device.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create pipeline layout");
	}
}

void App::CreatePipeline()
{
	auto config = Pipeline::defaultPipelineConfigInfo(swapChain.width(), swapChain.height());
	config.pipelineLayout = pipelineLayout;
	
	pipeline = std::make_unique<Pipeline>(device, config, "Shaders/VS.vert.spv", "Shaders/FS.frag.spv");
}


