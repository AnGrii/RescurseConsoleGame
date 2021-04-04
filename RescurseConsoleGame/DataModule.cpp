#include "DataModule.h"

/// <summary>
/// If keyword not finded, function will throw exception
/// </summary>
void DataModule::goToStringInFile(std::ifstream& dataFile, std::string keyword)
{
	std::string buffer = "0";
	uint32_t dataCounter = 0;

	while (buffer != keyword) {
		dataFile >> buffer;

		dataCounter++;
		if (dataCounter >= COUNT_DATA_UNIT_LOADING_TO_ERROR_THROW) {
			std::string errorMSG = "Data count overflow\t!" + keyword + \
				"\t - that keyword data not finded!!!";
			throw std::exception(errorMSG.data());
		}
	}
}


template<typename dataType>
dataType DataModule::loadNumber(std::ifstream& dataFile)
{
	dataType buffer = 0;

	dataFile >> buffer;

	//Warning for future save data loading (in this place);

	return buffer;
}
std::string DataModule::loadName(std::ifstream& dataFile)
{
	//Warning fo future realization for save data loading

	std::string Buffer, Result;

	dataFile >> Buffer;

	while (Buffer.at(Buffer.length() - 1) != '/') {
		Result += Buffer + ' ';
		dataFile >> Buffer;
	}

	Result += Buffer;

	Result.erase(Result.end() - 1);

	return Result;
}


template<typename dataType>
void DataModule::loadData(std::vector<dataType>& stroage, size_t dataCount,
	std::string dataFileName, std::string dataKeyword,
	std::function<dataType(std::ifstream& dataFile)> function)
{
	std::ifstream dataFile;
	dataFile.open(dataFileName);

	try
	{
		goToStringInFile(dataFile, dataKeyword);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		system("pause");
		exit(1);
	}

	//Stroage initialization 
	stroage.resize(dataCount);
	
	//Data loading
	for (auto& item : stroage) {
		item = function(dataFile);
	}
}

template<typename dataType>
void DataModule::loadData(std::vector<std::vector<dataType>>& stroage,
	size_t listsCount, size_t dataCount,
	std::string dataFileName, std::string dataKeyword,
	std::function<dataType(std::ifstream& dataFile)> function)
{
	std::ifstream dataFile;
	dataFile.open(dataFileName);

	try
	{
		goToStringInFile(dataFile, dataKeyword);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		system("pause");
		exit(1);
	}

	//Stroage initialization 
	stroage.resize(listsCount);

	for (auto& list : stroage) {
		list.resize(dataCount);
	}

	//Data loading
	for (auto& list : stroage)
	{
		for (auto& item : list)
		{
			item = function(dataFile);
		}
	}
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
		data = loadName(loadDataFile);
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


DataModule::DataModule(std::string dataFileName)
{
	/*loadData<uint64_t>(resourcesData, RESOURCES_COUNT, RESOURCES_DATA_COUNT,
		dataFileName, keywordResourcesData, loadNumber<uint64_t>);*/

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

















