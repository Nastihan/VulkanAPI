#include "Pipieline.h"
#include <fstream>
#include <iostream>

Pipeline::Pipeline(const std::string& VSFilePath,const std::string& FSFilePath)
{
	CreateGraphicsPipeline(VSFilePath, FSFilePath);
}

std::vector<char> Pipeline::ReadFile(const std::string& filepath)
{
	std::ifstream file{filepath, std::ios::ate | std::ios::binary};
	if (!file.is_open())
	{
		throw std::runtime_error("failed to open file : " + filepath);
	}

	size_t fileSize = static_cast<size_t>(file.tellg());

	std::vector<char> buffer(fileSize);
	file.seekg(0);
	file.read( buffer.data(), fileSize);

	file.close();

	return buffer;

}

void Pipeline::CreateGraphicsPipeline(const std::string& VSFilePath,const std::string& FSFilePath)
{
	auto test = ReadFile(VSFilePath);
	auto testt = ReadFile(FSFilePath);

	std::cout <<test.size() << std::endl;
}
