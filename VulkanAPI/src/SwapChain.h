#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include "Device.h"

class SwapChain
{
public:
	SwapChain(Device& device, VkExtent2D windowExtent);
	~SwapChain();
	SwapChain(const SwapChain&) = delete;
	void operator=(const SwapChain&) = delete;

	uint32_t width() { return swapChainExtent.width; }
	uint32_t height() { return swapChainExtent.height; }

private:

private:
	void CreateSwapChain();
	void CreateImageViews();
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availabeFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

private:
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImage> swapChainImages;
	std::vector<VkImageView> swapChainImageViews;

	Device& device;
	VkExtent2D windowExtent;
	VkSwapchainKHR swapChain;


};