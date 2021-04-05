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
		keywordMarketData = "marketData:",
		keywordSettingsData = "setting:";

	const uint16_t
		COUNT_LOADING_DATA_UNIT_TO_THROW_ERROR = 1000,
		PLAYER_DATA_COUNT = 1,
		PLAYER_NAME_DATA_COUNT = 1,
		RESOURCES_COUNT = 11,
		RESOURCES_DATA_COUNT = 2,
		BUILDING_COUNT = 11,
		BUILDING_DATA_COUNT = 11,
		RESOURCES_EXTRACT_DATA_COUNT = 6,
		MARKET_DATA_COUNT = 1;

	//Data stroages
	std::vector<uint64_t> playerData;
	std::vector<std::string> playerNameData;

	std::vector< std::vector< uint64_t>> resourcesData;

	std::vector< std::string> buildingNameData;
	std::vector< std::vector< uint64_t>> buildingsData;

	std::vector<uint64_t> resourcesExtractData;

	std::vector<double> marketData;

	std::vector< std::vector< uint64_t>> settingsData;
	
	//...
	class LoadingComponents {
	public:
		static void goToStringInFile(std::ifstream& dataFile, std::string keyword)
		{
			std::string buffer = "0";

			while (buffer != keyword) {
				dataFile >> buffer;
				//std::cout << buffer << " - loaded data!" << std::endl << std::endl;
			}
		}



		template<typename dataType>
		static dataType readNumber(std::ifstream& dataFile)
		{
			dataType buffer = 0;

			dataFile >> buffer;

			//Warning fo future realization for save data loading

			return buffer;
		}
		static std::string readName(std::ifstream& dataFile)
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
		static void loadData(std::vector<dataType>& stroage, size_t dataCount,
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
		static void loadData(std::vector<std::vector<dataType>>& stroage,
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

	private:
		LoadingComponents() {}
	};

	//Loading part
	void loadPlayer(std::ifstream& loadDataFile);

	void loadResources(std::ifstream& loadDataFile);

	void loadBuildings(std::ifstream& loadDataFile);

	void loadBuildingsName(std::ifstream& loadDataFile);

	void loadMarketData(std::ifstream& loadDataFile);

	void loadResourcesExtract(std::ifstream& loadDataFile);
};


