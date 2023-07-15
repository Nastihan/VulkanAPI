#pragma once
#include <string>
#include <vector>

class Pipeline
{
public:
	Pipeline(const std::string& VSFilePath,const std::string& FSFilePath);
	
private:
	static std::vector<char> ReadFile(const std::string& filePath);
	void CreateGraphicsPipeline(const std::string& VSFilePath,const std::string& FSFilePath);
};