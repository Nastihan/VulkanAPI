#pragma once
#include "Window.h"

class Device
{
public:
	~Device();

public:
	void CreateInstance();

private:
	VkInstance instance;

};