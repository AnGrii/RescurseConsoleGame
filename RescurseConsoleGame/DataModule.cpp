#include "DataModule.h"

DataModule::DataModule(const std::string dataFileName)
{
	this->loadData(dataFileName);
}

void DataModule::loadData(std::string dataFileName)
{
	// PLAYER_NAME
	LoadingComponents::loadData<std::string>(playerNameData,
		PLAYER_NAME_DATA_COUNT,
		dataFileName, keywordPlayerName,
		LoadingComponents::readName);

	// PLAYER_DATA
	LoadingComponents::loadData<uint64_t>(playerData,
		PLAYER_DATA_COUNT,
		dataFileName, keywordPlayerData,
		LoadingComponents::readNumber<uint64_t>);
	
	// RESOURCE_NAME_DATA
	LoadingComponents::loadData<std::string>(resourcesNameData, RESOURCES_COUNT,
		dataFileName, keywordResourcesName,
		LoadingComponents::readName);

	// LEVELING_OF_RESOURCES_NAMES
	WorkWithString::stringLeveling(resourcesNameData);

	// RESOURCE_DATA
	LoadingComponents::loadData<uint64_t>(resourcesData,
		RESOURCES_COUNT, RESOURCES_DATA_COUNT,
		dataFileName, keywordResourcesData,
		LoadingComponents::readNumber<uint64_t>);

	// BUILDING_NAME
	LoadingComponents::loadData<std::string>(buildingNameData,
		BUILDING_COUNT,
		dataFileName, keywordBuildingsName,
		LoadingComponents::readName);
	
	// LEVELING_OF_BUILDINGS_NAMES
	WorkWithString::stringLeveling(buildingNameData);

	// BUILDING_DATA
	LoadingComponents::loadData<uint64_t>(buildingsData,
		BUILDING_COUNT, BUILDING_DATA_COUNT,
		dataFileName, keywordBuildingsData,
		LoadingComponents::readNumber<uint64_t>);

	//RESOURCE_EXTRACT_DATA
	LoadingComponents::loadData<uint64_t>(resourcesExtractData,
		RESOURCES_EXTRACT_DATA_COUNT,
		dataFileName, keywordRecourcesExtractData,
		LoadingComponents::readNumber<uint64_t>);

	// MARKET_DATA
	LoadingComponents::loadData<uint64_t>(marketData,
		MARKET_DATA_COUNT,
		dataFileName, keywordMarketData,
		LoadingComponents::readNumber<uint64_t>);

	//SETTINGS_DATA
	LoadingComponents::loadData<uint16_t>(settingsData,
		SETTINGS_DATA_COUNT,
		dataFileName,
		keywordSettingsData,
		LoadingComponents::readNumber<uint16_t>);
	//bool type is unsafe for read number operation

	// AUTO_SELL 
	LoadingComponents::loadData<uint16_t>(resAutoSellData,
		RESOURCES_AUTO_SELL_DATA_COUNT,
		dataFileName,
		keywordAutoSellData,
		LoadingComponents::readNumber<uint16_t>);

	// AUTO_BUY
	LoadingComponents::loadData<uint64_t>(resAutoBuyData,
		RESOURCES_AUTO_BUY_COUNT,
		RESOURCES_AUTO_BUY_DATA_COUNT,
		dataFileName,
		keywordAutoBuyData,
		LoadingComponents::readNumber<uint64_t>);

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
	SavingComponents::saveData<uint64_t>(marketData,
		dataFileName, keywordMarketData,
		SavingComponents::prepareNumberToSave<uint64_t>);

	//SETTINGS_DATA
	SavingComponents::saveData<uint16_t>(settingsData,
		dataFileName,
		keywordSettingsData,
		SavingComponents::prepareNumberToSave<uint16_t>);
	//bool type is unsafe for prepare number to save operation

	// AUTO_SELL 
	SavingComponents::saveData<uint16_t>(resAutoSellData,
		dataFileName, keywordAutoSellData,
		SavingComponents::prepareNumberToSave<uint16_t>);

	// AUTO_BUY
	SavingComponents::saveData<uint64_t>(resAutoBuyData,
		dataFileName, keywordAutoBuyData,
		SavingComponents::prepareNumberToSave<uint64_t>);
}

void DataModule::resetData(const std::string dataFileName)
{
	Reset reset;
	reset.resetData(dataFileName);
}

void DataModule::resetDataWithSecurity(const std::string dataFileName)
{
	Reset resetDataWithSecurity;
	resetDataWithSecurity.resetDataWithSecurity(dataFileName);
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

std::vector<uint64_t> DataModule::getMarketData()
{
	return marketData;
}

std::vector<uint16_t> DataModule::getSettingsData()
{
	return settingsData;
}

std::vector<uint16_t> DataModule::getResAutoSellData()
{
	return resAutoSellData;
}

std::vector<std::vector<uint64_t>> DataModule::getResAutoBuyData()
{
	return resAutoBuyData;
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

void DataModule::setMarketData(std::vector<uint64_t> dataVector)
{
	bool dataCountBiggerNULL = (dataVector.size() > 0);
	uint16_t marketDataSize = PLAYER_DATA_COUNT + (BUILDING_COUNT * 2);

	if (dataCountBiggerNULL and dataVector.size() == marketDataSize) {
		marketData.swap(dataVector);
	}
	else {
		throw std::exception("Wrong market data data list size (Wrong data)!");
	}
}

void DataModule::setSettingsData(std::vector<uint16_t> dataVector)
{
	settingsData.swap(dataVector);
}

void DataModule::getResAutoSellData(std::vector<uint16_t> dataVector)
{
	resAutoSellData.swap(dataVector);
}

void DataModule::getResAutoBuyData(std::vector<std::vector<uint64_t>> dataVector)
{
	resAutoBuyData.swap(dataVector);
}

void DataModule::Reset::checkExistenceFileOrAskForCreate(const std::string dataFileName)
{
	std::ofstream dataFile(dataFileName);

	if (not dataFile.is_open()) {
		std::cout << "Data file damaged or nonexistent!" << std::endl
			<< "Correct data file" << std::endl
			<< "Or input - y to reset";

		char select = '0';
		std::cin >> select;
		std::cout << std::endl;

		if (select == 'y') {
			resetData(dataFileName);
		}
		exit(1);
	}
}

void DataModule::WorkWithString::stringLeveling(std::vector<std::string>& strVc)
{
	size_t maxStrSize = 0;

	if (strVc.size() > 1) {
		for (auto& str : strVc) {
			if (str.length() > maxStrSize) {
				maxStrSize = str.length();
			}
		}

		for (auto& str : strVc)
		{
			size_t addSpaceCount = maxStrSize - str.length();
			std::string spaces;

			while (spaces.length() < addSpaceCount) {
				spaces = spaces + ' ';
			}

			str = str + spaces;
		}

	}
	else {
		throw std::exception("Uncorrect data! Wrong count of strings!");
	}
}
