#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include "Device.h"

class SwapChain
{
public:
	SwapChain(Device& device, VkExtent2D windowExtent);
	~SwapChain();

private:

private:
	void CreateSwapChain();
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availabeFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

private:
	Device& device;
	VkExtent2D windowExtent;
	VkSwapchainKHR swapChain;


};