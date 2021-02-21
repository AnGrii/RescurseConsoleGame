#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<string>


class DataModule
{
public:
	DataModule(std::string dataFileName) 
	{
		std::ifstream loadDataFile(dataFileName);

		loadPlayer(loadDataFile);
		loadResources(loadDataFile);
	}

	std::string getPlayerName();
	std::vector<uint64_t> getPlayerData();

	std::vector<uint64_t> getRecourcesData();

private:
	std::vector<std::vector<uint64_t>> dataMatrix;
	std::string playerName;

	const uint16_t RESOURCES_COUNT = 3;

	void loadPlayer(std::ifstream& loadDataFile);
	void loadResources(std::ifstream& loadDataFile);
};

