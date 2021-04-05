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
		data = LoadingComponents::loadName(loadDataFile);
	}
}

void DataModule::loadMarketData(std::ifstream& loadDataFile)
{
	double buffer;

	marketData.resize(MARKET_DATA_COUNT);

	loadDataFile >> buffer;

	marketData[0] = buffer;
}

void DataModule::loadResourcesExtract(std::ifstream& loadDataFile)
{
	resourcesExtractData.resize(RESOURCES_EXTRACT_DATA_COUNT);

	for (auto& data : resourcesExtractData)
	{
		uint64_t buffer;
		loadDataFile >> buffer;
		data = buffer;
	}
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


DataModule::DataModule(const std::string dataFileName)
{
	/*LoadingComponents::loadData<uint64_t>(resourcesData,
		RESOURCES_COUNT, RESOURCES_DATA_COUNT,
		dataFileName, keywordResourcesData,
		LoadingComponents::loadNumber<uint64_t>);*/

	std::ifstream loadDataFile(dataFileName);

	loadPlayer(loadDataFile);
	
	loadResources(loadDataFile);
	
	loadBuildingsName(loadDataFile);
	loadBuildings(loadDataFile);

	loadResourcesExtract(loadDataFile);

	loadMarketData(loadDataFile);
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

std::vector<uint64_t> DataModule::getResourcesExtractData()
{
	return resourcesExtractData;
}

std::vector<double> DataModule::getMarketData()
{
	return marketData;
}

















