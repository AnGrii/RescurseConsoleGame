#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>

/// <summary>
///  Loading, initialisation and checking game data
/// </summary>
class DataModule
{
public:
	DataModule(std::string dataFileName);

	std::vector< std::string> getPlayerName();
	std::vector< uint64_t> getPlayerData();
	
	std::vector< std::vector< uint64_t>> getRecourcesData();

	std::vector< std::vector< uint64_t>> getBuildingsData();
	std::vector<std::string> getBuildingsNameData();

	std::vector< uint64_t> getResourcesExtractData();

	std::vector< double> getMarketData();

private:
	const std::string dataFileName = "Data.txt",
		keywordPlayerName = "playerName:",
		keywordPlayerData = "playerData:",
		keywordResourcesData = "resourcesData:",
		keywordBuildingsName = "buildingsName:",
		keywordBuildingsData = "buildingsData:",
		keywordRecourcesExtractData = "resourcesExtract:",
		keywordSellCoeficientData = "sellCoeficient:",
		keywordSettingsData = "setting:";

	const uint16_t
		COUNT_DATA_UNIT_LOADING_TO_ERROR_THROW = 1000,
		//function will find "key word" of data if it's word will be don't finded function will throw error
		PLAYER_DATA_COUNT = 1,
		PLAYER_NAME_DATA_COUNT = 1,
		RESOURCES_COUNT = 11,
		RESOURCES_DATA_COUNT = 2,
		BUILDING_COUNT = 11,
		BUILDING_DATA_COUNT = 11,
		RESOURCES_EXTRACT_DATA_COUNT = 6,
		MARKET_DATA_COUNT = 1;

	std::vector<uint64_t> playerData;
	std::vector<std::string> playerNameData;

	std::vector< std::vector< uint64_t>> resourcesData;

	std::vector< std::string> buildingNameData;
	std::vector< std::vector< uint64_t>> buildingsData;

	std::vector<uint64_t> resourcesExtractData;

	std::vector<double> marketData;

	std::vector< std::vector< uint64_t>> settingsData;
	
	//Loading data components
	/// <summary>
	/// If keyword not finded, function will throw exception
	/// </summary>
	void goToStringInFile(std::ifstream& dataFile, std::string keyword);

	template<typename dataType>
	dataType loadNumber(std::ifstream& dataFile);
	std::string loadName(std::ifstream& dataFile);

	template<typename dataType>
	void loadData(std::vector< dataType>& stroage, size_t dataCount,
		std::string dataFileName, std::string dataKeyword,
		std::function< dataType (std::ifstream& dataFile)> function);

	template<typename dataType>
	void loadData(std::vector < std::vector< dataType>>& stroage,
		size_t listsCount, size_t dataCount, 
		std::string dataFileName, std::string dataKeyword,
		std::function< dataType (std::ifstream& dataFile)> function);

	//End of loading data components

	//Loading part
	void loadPlayer(std::ifstream& loadDataFile);

	void loadResources(std::ifstream& loadDataFile);

	void loadBuildings(std::ifstream& loadDataFile);

	void loadBuildingsName(std::ifstream& loadDataFile);

	void loadMarketData(std::ifstream& loadDataFile);

	void loadResourcesExtract(std::ifstream& loadDataFile);

	//void loadSettings(std::ifstream& loadDataFile);
};


