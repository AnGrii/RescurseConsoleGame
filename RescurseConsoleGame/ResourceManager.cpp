#include "ResourceManager.h"

ResourceManager::ResourceManager(std::vector<std::string> nameList,
	std::vector< std::vector<uint64_t>> dataList)
{
	uint16_t counter = 0;

	for (size_t i = 0; i < RESOURCES_COUNT; i++) {
		ReosourcesVector[i]->Reinitialisate \
			(nameList[counter], dataList[counter]); counter++;
	}
}


void ResourceManager::printResourcesCount()
{
	for (size_t i = 0; i < RESOURCES_COUNT; i++)
	{
		if (i % 2 == 1) {
			std::cout << ReosourcesVector[i]->getNameAndCountInfo() << "\t" << std::endl;
		}
		else {
			std::cout << ReosourcesVector[i]->getNameAndCountInfo() << "\t";
		}
	}
	std::cout << std::endl;
}


std::vector<std::vector<uint64_t>> ResourceManager::UploadData()
{
	std::vector<std::vector<uint64_t>> dataVector;

	dataVector.reserve(RESOURCES_COUNT);

	for (auto& resource : ReosourcesVector)
	{
		dataVector.push_back(resource->UploadData());
	}

	return dataVector;
}
