#include "DataModule.h"

DataModule::DataModule(const std::string dataFileName)
{
	//PLAYER_NAME
	LoadingComponents::loadData<std::string>(playerNameData,
		PLAYER_NAME_DATA_COUNT,
		dataFileName, keywordPlayerName,
		LoadingComponents::readName);

	//PLAYER_DATA
	LoadingComponents::loadData<uint64_t>(playerData,
		PLAYER_DATA_COUNT,
		dataFileName, keywordPlayerData,
		LoadingComponents::readNumber<uint64_t>);

	//RESOURCE_DATA
	LoadingComponents::loadData<uint64_t>(resourcesData,
		RESOURCES_COUNT, RESOURCES_DATA_COUNT,
		dataFileName, keywordResourcesData,
		LoadingComponents::readNumber<uint64_t>);

	//BUILDING_NAME
	LoadingComponents::loadData<std::string>(buildingNameData,
		BUILDING_COUNT,
		dataFileName, keywordBuildingsName,
		LoadingComponents::readName);

	//BUILDING_DATA
	LoadingComponents::loadData<uint64_t>(buildingsData,
		BUILDING_COUNT, BUILDING_DATA_COUNT,
		dataFileName, keywordBuildingsData,
		LoadingComponents::readNumber<uint64_t>);

	//RESOURCE_EXTRACT_DATA
	LoadingComponents::loadData<uint64_t>(resourcesExtractData,
		RESOURCES_EXTRACT_DATA_COUNT,
		dataFileName, keywordRecourcesExtractData,
		LoadingComponents::readNumber<uint64_t>);

	//MARKET_DATA
	LoadingComponents::loadData<double>(marketData,
		MARKET_DATA_COUNT,
		dataFileName, keywordMarketData,
		LoadingComponents::readNumber<double>);

	//SETTINGS_DATA

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

















