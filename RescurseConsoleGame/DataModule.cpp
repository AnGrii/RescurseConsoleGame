#include "DataModule.h"

std::string getFullNameDataUnit(std::ifstream& DataFile)
{
	std::string Buffer, Result;

	DataFile >> Buffer;

	while (Buffer.at(Buffer.length() - 1) != '/') {
		Result += Buffer + ' ';
		DataFile >> Buffer;
	}

	Result += Buffer;

	Result.erase(Result.end() - 1);

	return Result;
}



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

	resourcesData.resize(RESOURCES_COUNT);

	for (size_t i = 0; i < RESOURCES_COUNT; i++){
		resourcesData[i].resize(RESOURCES_DATA_COUNT);
	}

	//Dynamic loading (count) and (value) for resource
	for (size_t row = 0; row < RESOURCES_COUNT; row++) {
		for (size_t collumn = 0; collumn < RESOURCES_DATA_COUNT; collumn++) {
			loadDataFile >> buffer;
			resourcesData[row][collumn] = buffer;
		}
	}
}

void DataModule::loadBuildingsName(std::ifstream& loadDataFile)
{
	buildingNameData.resize(BUILDING_COUNT);

	for (std::string& data : buildingNameData)
	{
		data = getFullNameDataUnit(loadDataFile);
	}
}

void DataModule::loadSellCoeficient(std::ifstream& loadDataFile)
{
	loadDataFile >> sellCoeficient;
}

void DataModule::loadBuildings(std::ifstream& loadDataFile)
{
	uint64_t buffer;

	buildingsData.resize(BUILDING_COUNT);

	for (std::vector<uint64_t>& dataMatrix : buildingsData) {
		dataMatrix.resize(BUILDING_DATA_COUNT);
	}

	//Dynamic loading (count) and (value) for resource
	for (std::vector<uint64_t>& list : buildingsData) {
		for (uint64_t& data : list) {
			loadDataFile >> buffer;
			data = buffer;
		}
	}
}


DataModule::DataModule(std::string dataFileName)
{
	std::ifstream loadDataFile(dataFileName);

	loadPlayer(loadDataFile);
	
	loadResources(loadDataFile);
	
	loadBuildingsName(loadDataFile);
	loadBuildings(loadDataFile);

	loadSellCoeficient(loadDataFile);
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

std::vector<std::string> DataModule::getBuildingsNameData()
{
	return buildingNameData;
}

uint64_t DataModule::getSellCoeficient()
{
	return sellCoeficient;
}
















