#include "DataModule.h"



void DataModule::loadPlayer(std::ifstream& loadDataFile)
{
	uint64_t buffer;
	loadDataFile >> playerName;
	loadDataFile >> buffer;
	
	std::vector<uint64_t> playerData;
	playerData.push_back(buffer);

	dataMatrix.push_back(playerData);
}

void DataModule::loadResources(std::ifstream& loadDataFile)
{
	uint64_t buffer;
	std::vector<uint64_t> resourcesData;
	resourcesData.resize(RESOURCES_COUNT);


	for (size_t i = 0; i < RESOURCES_COUNT; i++)
	{
		loadDataFile >> buffer;
		resourcesData[i] = buffer;
	}

	dataMatrix.push_back(resourcesData);
}


std::string DataModule::getPlayerName()
{
	return playerName;
}

std::vector<uint64_t> DataModule::getPlayerData()
{
	return dataMatrix[0];
}

std::vector<uint64_t> DataModule::getRecourcesData()
{
	return dataMatrix[1];
}
