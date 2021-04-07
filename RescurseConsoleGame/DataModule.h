#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>


/// <summary>
/// Loading, initialisation and checking game data
/// </summary>
class DataModule
{
public:
	DataModule(const std::string dataFileName);

	void loadData(const std::string dataFileName);
	void saveData(const std::string dataFileName);
	 

	std::vector<std::string> getPlayerName();
	std::vector<uint64_t> getPlayerData();
	
	std::vector<std::vector<uint64_t>> getRecourcesData();

	std::vector<std::vector<uint64_t>> getBuildingsData();
	std::vector<std::string> getBuildingsNameData();

	std::vector<uint64_t> getResourcesExtractData();

	std::vector<double> getMarketData();

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

	
};
