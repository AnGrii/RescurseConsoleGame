#include "DataModule.h"



void DataModule::loadPlayer(std::ifstream& loadDataFile)
{
	std::string nameBuffer;
	uint64_t numberBuffer;

	loadDataFile >> nameBuffer;
	loadDataFile >> numberBuffer;
	
	//Data name
	playerNameData.push_back(nameBuffer);

	//Data number
	playerData.push_back(numberBuffer);
}

void DataModule::loadResources(std::ifstream& loadDataFile)
{
	uint64_t buffer;
	std::vector<uint64_t> logData, woodData, stoneData;


	logData.resize(RESOURCES_COUNT);
	woodData.resize(RESOURCES_COUNT);
	stoneData.resize(RESOURCES_COUNT);


	for (size_t i = 0; i < RESOURCES_COUNT; i++)
	{
		loadDataFile >> buffer;
		logData[i] = buffer;

		loadDataFile >> buffer;
		woodData[i] = buffer;

		loadDataFile >> buffer;
		stoneData[i] = buffer;
	}

	resourcesData.push_back(logData);
	resourcesData.push_back(woodData);
	resourcesData.push_back(stoneData);
}


DataModule::DataModule(std::string dataFileName)
{
	std::ifstream loadDataFile(dataFileName);

	loadPlayer(loadDataFile);
	loadResources(loadDataFile);
}

std::vector < std::string> DataModule::getPlayerName()
{
	return playerNameData;
}

std::vector<uint64_t> DataModule::getPlayerData()
{
	return playerData;
}

std::vector< std::vector< uint64_t>> DataModule::getRecourcesData()
{
	return resourcesData;
}
