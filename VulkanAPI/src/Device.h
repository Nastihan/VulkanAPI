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
	bool CheckValidationLayerSupport();

private:
	VkInstance instance;

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

};