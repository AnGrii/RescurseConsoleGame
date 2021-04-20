#include "DataModule.h"

DataModule::DataModule(const std::string dataFileName)
{
	this->loadData(dataFileName);
}

void DataModule::loadData(std::string dataFileName)
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
	
	//RESOURCE_NAME_DATA
	LoadingComponents::loadData<std::string>(resourcesNameData, RESOURCES_COUNT,
		dataFileName, keywordResourcesName,
		LoadingComponents::readName);

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

void DataModule::saveData(const std::string dataFileName)
{
	//Clean data
	std::ofstream clean(dataFileName);
	clean.close();

	//PLAYER_NAME
	SavingComponents::saveData<std::string>(playerNameData,
			dataFileName, keywordPlayerName,
			SavingComponents::prepareStringToSave);

	//PLAYER_DATA
	SavingComponents::saveData<uint64_t>(playerData,
		dataFileName, keywordPlayerData,
		SavingComponents::prepareNumberToSave<uint64_t>);

	//RESOURCE_NAME_DATA
	SavingComponents::saveData<std::string>(resourcesNameData,
		dataFileName, keywordResourcesName,
		SavingComponents::prepareStringToSave);

	//RESOURCE_DATA
	SavingComponents::saveData<uint64_t>(resourcesData,
		dataFileName, keywordResourcesData,
		SavingComponents::prepareNumberToSave<uint64_t>);

	//BUILDING_NAME
	SavingComponents::saveData<std::string>(buildingNameData,
		dataFileName, keywordBuildingsName,
		SavingComponents::prepareStringToSave);

	//BUILDING_DATA
	SavingComponents::saveData<uint64_t>(buildingsData,
		dataFileName, keywordBuildingsData,
		SavingComponents::prepareNumberToSave<uint64_t>);

	//RESOURCE_EXTRACT_DATA
	SavingComponents::saveData<uint64_t>(resourcesExtractData,
		dataFileName, keywordRecourcesExtractData,
		SavingComponents::prepareNumberToSave<uint64_t>);

	//MARKET_DATA
	SavingComponents::saveData<double>(marketData,
		dataFileName, keywordMarketData,
		SavingComponents::prepareNumberToSave<double>);

	//SETTINGS_DATA

}

void DataModule::restoreData(const std::string dataFileName)
{
	Restore restore;
	restore.restoreData(dataFileName);
}


std::vector<std::string> DataModule::getPlayerName()
{
	return playerNameData;
}
std::vector<uint64_t> DataModule::getPlayerData()
{
	return playerData;
}


std::vector<std::string> DataModule::getRecourcesNameData()
{
	return resourcesNameData;
}
std::vector<std::vector< uint64_t>> DataModule::getRecourcesData()
{
	return resourcesData;
}

std::vector<std::vector<uint64_t>> DataModule::getBuildingsData()
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

void DataModule::setPlayerName(std::vector<std::string> dataVector)
{
	playerNameData.swap(dataVector);
}

void DataModule::setPlayerData(std::vector<uint64_t> dataVector)
{
	playerData.swap(dataVector);
}

void DataModule::setRecourcesData(std::vector<std::vector<uint64_t>> dataVector)
{
	resourcesData.swap(dataVector);
}

void DataModule::setBuildingsData(std::vector<std::vector<uint64_t>> dataVector)
{
	buildingsData.swap(dataVector);
}

void DataModule::getResourcesExtractData(std::vector<uint64_t> dataVector)
{
	resourcesExtractData.swap(dataVector);
}

void DataModule::getMarketData(std::vector<double> dataVector)
{
	marketData.swap(dataVector);
}
