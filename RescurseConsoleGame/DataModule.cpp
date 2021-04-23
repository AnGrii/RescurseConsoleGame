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

void DataModule::resetData(const std::string dataFileName)
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
	bool dataCountBiggerNULL = (dataVector.size() > 0);

	if (dataCountBiggerNULL and dataVector.size() == PLAYER_DATA_COUNT) {
		playerNameData.swap(dataVector);
	}
	else {
		throw std::exception("Wrong player name data size (Wrong data)!");
	}
}

void DataModule::setPlayerData(std::vector<uint64_t> dataVector)
{
	bool dataCountBiggerNULL = (dataVector.size() > 0);

	if (dataCountBiggerNULL and dataVector.size() == PLAYER_DATA_COUNT) {
		playerData.swap(dataVector);
	}
	else {
		throw std::exception("Wrong player data list size (Wrong data)!");
	}
}

void DataModule::setRecourcesData(std::vector<std::vector<uint64_t>> dataVector)
{
	bool dataCountBiggerNULL = (dataVector.size() > 0);

	if (dataCountBiggerNULL and (dataVector.size() == RESOURCES_COUNT)) {
		if (dataVector[0].size() == RESOURCES_DATA_COUNT) {
			resourcesData.swap(dataVector);
		}
		else {
			throw std::exception("Wrong recources data list size (Wrong data)!");
		}
	}
	else {
		throw std::exception("Wrong recources data list size (Wrong data)!");
	}
}

void DataModule::setBuildingsData(std::vector<std::vector<uint64_t>> dataVector)
{
	bool dataCountBiggerNULL = (dataVector.size() > 0); //To prevent error .size() on data_count
	bool securityOfSwapData = (dataVector.size() == BUILDING_COUNT);

	if (dataCountBiggerNULL and securityOfSwapData) {
		if (dataVector[0].size() == BUILDING_DATA_COUNT) {
			buildingsData.swap(dataVector);
		}
		else {
			throw std::exception("Wrong buildings data list size (Wrong data)!");
		}
	}
	else {
		throw std::exception("Wrong buildings data list size (Wrong data)!");
	}
}

void DataModule::setResourcesExtractData(std::vector<uint64_t> dataVector)
{
	bool dataCountBiggerNULL = (dataVector.size() > 0);

	if (dataCountBiggerNULL and dataVector.size() == RESOURCES_EXTRACT_DATA_COUNT) {
		resourcesExtractData.swap(dataVector);
	}
	else {
		throw std::exception("Wrong resource extract list size (Wrong data)!");
	}
}

void DataModule::setMarketData(std::vector<double> dataVector)
{
	bool dataCountBiggerNULL = (dataVector.size() > 0);

	if (dataCountBiggerNULL and dataVector.size() == PLAYER_DATA_COUNT) {
		marketData.swap(dataVector);
	}
	else {
		throw std::exception("Wrong market data data list size (Wrong data)!");
	}
}
