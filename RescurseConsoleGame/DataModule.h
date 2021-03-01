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
private:
	const uint8_t RESOURCES_COUNT = 3;

	std::vector< std::vector< uint64_t>> dataMatrix;
	std::vector< std::vector< std::string>> nameList;


	void loadPlayer(std::ifstream& loadDataFile);
	void loadResources(std::ifstream& loadDataFile);

	//void loadSettings(std::ifstream& loadDataFile);

public:
	DataModule(std::string dataFileName);

	std::vector< std::string> getPlayerName();
	std::vector< uint64_t> getPlayerData();

	std::vector< uint64_t> getRecourcesData();
};

