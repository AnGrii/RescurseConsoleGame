#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<string>
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

	uint64_t getSellCoeficient();

private:
	const uint16_t
		COUNT_DATA_UNIT_LOADING_TO_ERROR_THROW = 1000,
		//function will find "key word" of data if it's word will be don't finded function will throw error
		RESOURCES_COUNT = 11,
		RESOURCES_DATA_COUNT = 2,
		BUILDING_COUNT = 11,
		BUILDING_DATA_COUNT = 10;

	double sellCoeficient = 1;

	std::vector<uint64_t> playerData;
	std::vector<std::string> playerNameData;

	std::vector< std::vector< uint64_t>> resourcesData;

	std::vector< std::string> buildingNameData;
	std::vector< std::vector< uint64_t>> buildingsData;

	std::vector< std::vector< uint64_t>> settingsData;
	
	//Loading part
	void loadPlayer(std::ifstream& loadDataFile);

	void loadResources(std::ifstream& loadDataFile);

	void loadBuildings(std::ifstream& loadDataFile);

	void loadBuildingsName(std::ifstream& loadDataFile);

	void loadSellCoeficient(std::ifstream& loadDataFile);

	//void loadSettings(std::ifstream& loadDataFile);
};
