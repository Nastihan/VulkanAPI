#pragma once

#include "Device.h"
#include <string>
#include <vector>


struct PipelineConfigInfo
{
	VkViewport viewport;
	VkRect2D scissor;
	VkPipelineViewportStateCreateInfo viewportInfo;
	VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
	VkPipelineRasterizationStateCreateInfo rasterizationInfo;
	VkPipelineMultisampleStateCreateInfo multisampleInfo;
	VkPipelineColorBlendAttachmentState colorBlendAttachment;
	VkPipelineColorBlendStateCreateInfo colorBlendInfo;
	VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
	VkPipelineLayout pipelineLayout = nullptr;
	VkRenderPass renderPass = nullptr;
	uint32_t subpass = 0;
};
class Pipeline
{
public:
	Pipeline(Device& device, const PipelineConfigInfo& configInfo, const std::string& vertFilepath, const std::string& fragFilepath);
	~Pipeline();
	Pipeline(const Pipeline&) = delete;
	Pipeline& operator=(const Pipeline&) = delete;
	static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
private:
	static std::vector<char> readFile(const std::string& filepath);
	void createGraphicsPipeline(const PipelineConfigInfo& configInfo, const std::string& vertFilepath, const std::string& fragFilepath);
	void createShaderModule(const std::vector<char>& code, VkShaderModule* pShaderModule);
private:
	Device& device;
	VkPipeline graphicsPipeline;
	VkShaderModule vertShaderModule;
	VkShaderModule fragShaderModule;
};
