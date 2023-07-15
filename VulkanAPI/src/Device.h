#pragma once
#include "Window.h"
#include <vector>

class Device
{
public:
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif
	Device();
	~Device();

private:
	void CreateInstance();
	void SetupDebugMessenger();
	void PickPhysicalDevice();

	bool IsDeviceSuitable(VkPhysicalDevice device);
	std::vector<const char*> getRequiredExtensions();
	bool CheckValidationLayerSupport();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);


private:
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

};