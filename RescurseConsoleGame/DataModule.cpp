#include "DataModule.h"



void DataModule::loadPlayer(std::ifstream& loadDataFile)
{
	std::string nameBuffer;
	uint64_t numberBuffer;

	loadDataFile >> nameBuffer;
	loadDataFile >> numberBuffer;
	
	std::vector<std::string> playeName;
	playeName.push_back(nameBuffer);

	nameList.push_back(playeName);


	std::vector<uint64_t> playerData;
	playerData.push_back(numberBuffer);

	dataMatrix.push_back(playerData);
}

void DataModule::loadResources(std::ifstream& loadDataFile)
{
	uint64_t buffer;
	std::vector<uint64_t> resourcesData;

	resourcesData.resize((static_cast<uint64_t>(RESOURCES_COUNT) * 2));


	for (size_t i = 0; i < (static_cast<uint64_t>(RESOURCES_COUNT) * 2); i++)
	{
		loadDataFile >> buffer;
		resourcesData[i] = buffer;
	}

	dataMatrix.push_back(resourcesData);
}


DataModule::DataModule(std::string dataFileName)
{
	std::ifstream loadDataFile(dataFileName);

	loadPlayer(loadDataFile);
	loadResources(loadDataFile);
}

std::vector < std::string> DataModule::getPlayerName()
{
	return nameList[0];
}

std::vector<uint64_t> DataModule::getPlayerData()
{
	return dataMatrix[0];
}

std::vector<uint64_t> DataModule::getRecourcesData()
{
	return dataMatrix[1];
}
