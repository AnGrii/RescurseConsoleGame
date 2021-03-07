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

	std::vector<uint64_t>* dataLists = new std::vector<uint64_t>[RESOURCES_COUNT];

	for (size_t i = 0; i < RESOURCES_COUNT; i++){
		dataLists[i].resize(RESOURCES_DATA_COUNT);
	}

	//Dynamic loading (count) and (value) for resource
	for (size_t row = 0; row < RESOURCES_COUNT; row++) {
		for (size_t collumn = 0; collumn < RESOURCES_DATA_COUNT; collumn++) {
			loadDataFile >> buffer;
			dataLists[row][collumn] = buffer;
		}
	}
	
	for (size_t i = 0; i < RESOURCES_COUNT; i++){
		resourcesData.push_back(dataLists[i]);
	}
}

void DataModule::loadBuildings(std::ifstream& loadDataFile)
{
	uint64_t buffer;

	std::vector<uint64_t>* dataLists = new std::vector<uint64_t>[BUILDING_COUNT];

	for (size_t i = 0; i < BUILDING_COUNT; i++) {
		dataLists[i].resize(BUILDING_DATA_COUNT);
	}

	//Dynamic loading (count) and (value) for resource
	for (size_t row = 0; row < BUILDING_COUNT; row++) {
		for (size_t collumn = 0; collumn < BUILDING_DATA_COUNT; collumn++) {
			loadDataFile >> buffer;
			dataLists[row][collumn] = buffer;
		}
	}

	for (size_t i = 0; i < BUILDING_COUNT; i++) {
		buildingsData.push_back(dataLists[i]);
	}
}


DataModule::DataModule(std::string dataFileName)
{
	std::ifstream loadDataFile(dataFileName);

	loadPlayer(loadDataFile);
	loadResources(loadDataFile);
	loadBuildings(loadDataFile);
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

std::vector< std::vector< uint64_t>> DataModule::getBuildingsData()
{
	return buildingsData;
}

















