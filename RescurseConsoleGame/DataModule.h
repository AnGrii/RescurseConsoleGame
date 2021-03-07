#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<string>

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

private:
	const uint8_t
		RESOURCES_COUNT = 11,
		RESOURCES_DATA_COUNT = 2,
		BUILDING_COUNT = 3,
		BUILDING_DATA_COUNT = 10;
	


	std::vector<uint64_t> playerData;
	std::vector<std::string> playerNameData;

	std::vector< std::vector< uint64_t>> resourcesData;

	std::vector< std::vector< uint64_t>> buildingsData;

	std::vector< std::vector< uint64_t>> settingsData;
	

	void loadPlayer(std::ifstream& loadDataFile);
	void loadResources(std::ifstream& loadDataFile);

	//void loadSettings(std::ifstream& loadDataFile);

};

