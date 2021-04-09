#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>


/// <summary>
/// Loading, Initialisation, Checking and Saving game data
/// </summary>
class DataModule
{
public:
	DataModule(const std::string dataFileName);

	void loadData(const std::string dataFileName);
	void saveData(const std::string dataFileName);
	void restoreData(const std::string dataFileName);
	 

	std::vector<std::string> getPlayerName();
	std::vector<uint64_t> getPlayerData();
	
	std::vector<std::string> getRecourcesNameData();
	std::vector<std::vector<uint64_t>> getRecourcesData();

	std::vector<std::string> getBuildingsNameData();
	std::vector<std::vector<uint64_t>> getBuildingsData();
	

	std::vector<uint64_t> getResourcesExtractData();

	std::vector<double> getMarketData();

private:
	const std::string dataFileName = "Data.txt",
		keywordPlayerName = "playerName:",
		keywordPlayerData = "playerData:",
		keywordResourcesName = "resourcesName:",
		keywordResourcesData = "resourcesData:",
		keywordBuildingsName = "buildingsName:",
		keywordBuildingsData = "buildingsData:",
		keywordRecourcesExtractData = "resourcesExtract:",
		keywordMarketData = "marketData:",
		keywordSettingsData = "setting:";

	static const uint16_t
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

	std::vector<std::string> resourcesNameData;
	std::vector<std::vector<uint64_t>> resourcesData;

	std::vector<std::string> buildingNameData;
	std::vector<std::vector<uint64_t>> buildingsData;

	std::vector<uint64_t> resourcesExtractData;

	std::vector<double> marketData;

	std::vector<std::vector<uint64_t>> settingsData;
	

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

			if (buffer == 0 or buffer >= INT64_MAX - 107) // Limit for double
			{
				std::string errorMSG = "Broken data loaded!";

				throw std::exception(errorMSG.data());
			}
			//Data in file is for 1 unit bigger;
			buffer--;

			return buffer;
		}
		static std::string readName(std::ifstream& dataFile)
		{
			std::string Buffer, Result;

			dataFile >> Buffer;

			uint16_t dataReadCounter = 0;
			while (Buffer.at(Buffer.length() - 1) != '/') {
				Result += Buffer + ' ';
				dataFile >> Buffer;
				dataReadCounter++;

				if (dataReadCounter >= COUNT_LOADING_DATA_UNIT_TO_THROW_ERROR) {
					std::string errorMSG = "Error names loading!";
					throw(std::exception(errorMSG.data()));
				}
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
			std::ifstream dataFile(dataFileName);

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
			std::ifstream dataFile(dataFileName);

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
	class SavingComponents
	{
	public:
		template<typename dataType>
		static dataType prepareNumberToSave(dataType number) {
			if (number < UINT64_MAX) {
				return ++number;
			}
			else {
				return number;
			}
		}
		static std::string prepareStringToSave(std::string str) {
			return str += '/';
		}


		template<typename dataType>
		static void saveData(std::vector<dataType>& stroage,
			std::string dataFileName, std::string dataKeyword,
			std::function<dataType(dataType)> function) 
		{
			std::ofstream dataFile(dataFileName, std::ios_base::app);

			//Write keyword
			dataFile << dataKeyword << '\n';

			//Data saving
			for (auto& item : stroage) {
				dataType savingUnit = function(item);

				dataFile << savingUnit  << ' ';
			}

			dataFile << '\n';
		}

		template<typename dataType>
		static void saveData(std::vector <std::vector<dataType>>& stroage,
			std::string dataFileName, std::string dataKeyword,
			std::function<dataType(dataType)> function) 
		{
			std::ofstream dataFile(dataFileName, std::ios_base::app);

			//Write keyword
			dataFile << dataKeyword << '\n';

			//Data loading
			for (auto& list : stroage)
			{
				for (auto& item : list)
				{
					dataFile << function(item) << ' ';
				}
				dataFile << '\n';
			}
			//Function ofstream open file in app mode add '\n' in end
		}
		

	private:
		SavingComponents(){}
	};
	class Restore {
	public:
		Restore(){}

		void restoreData(const std::string dataFileName) {

			std::ofstream dataFile(dataFileName);

			for (auto& item : restoreDataList)
			{
				dataFile << item << '\n';
			}
		}
	private:
		const std::vector<std::string> restoreDataList{
			"playerName:",
			"Player/",
			"playerData:",
			"100000001",
			"resourcesName:",
			"resourcesData:",
			"11 2",
			"11 3",
			"11 4",
			"1 5",
			"1 6",
			"1 7",
			"1 8",
			"1 9",
			"1 10",
			"1 11",
			"1 12",
			"buildingsName:",
			"Forestry/ Sawmill/ Quarry/ Career/",
			"Copper Mine/ Tin Mine/ Alloy Plant/",
			"Silver Cleaner/ Gold_Mine/",
			"Platina Cleaner/ Diamond Factory/",
			"buildingsData:",
			"1 2 1 101 1001 6 1 2 3 4 2",
			"1 2 1 101 1001 11 1 5 6 7 2",
			"1 2 1 101 1001 16 1 8 9 10 2",
			"1 2 1 101 1001 21 1 11 12 13 2",
			"1 2 1 101 1001 26 1 14 15 16 2",
			"1 2 1 101 1001 31 1 17 18 17 2",
			"1 2 1 101 1001 36 1 20 21 22 2",
			"1 2 1 101 1001 41 1 23 24 25 2",
			"1 2 1 101 1001 46 1 26 27 28 2",
			"1 2 1 101 1001 51 1 29 30 31 2",
			"1 2 1 101 1001 101 1 32 33 34 2",
			"resourcesExtract:",
			"2 101",
			"2 101",
			"2 101",
			"marketData:",
			"1.75",
			"setting:",
			"2 2 2 2 2 2 2 2 2 2"
		};
	};
};
