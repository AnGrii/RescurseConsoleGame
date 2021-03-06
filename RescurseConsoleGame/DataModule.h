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

	void resetData(const std::string dataFileName);

	void resetDataWithSecurity(const std::string dataFileName);
	

	std::vector<std::string> getPlayerName();
	std::vector<uint64_t> getPlayerData();
	
	std::vector<std::string> getRecourcesNameData();
	std::vector<std::vector<uint64_t>> getRecourcesData();

	std::vector<std::string> getBuildingsNameData();
	std::vector<std::vector<uint64_t>> getBuildingsData();
	
	std::vector<uint64_t> getResourcesExtractData();

	std::vector<uint64_t> getMarketData();

	std::vector<uint16_t> getSettingsData();

	std::vector<std::vector<uint64_t>> setResAutoSellData();

	std::vector<std::vector<uint64_t>> setResAutoBuyData();


	void setPlayerName(std::vector<std::string> dataVector);

	void setPlayerData(std::vector<uint64_t> dataVector);

	// Resources name don't need to change in program
	// Actual data will be normal for save
	void setRecourcesData(std::vector<std::vector<uint64_t>> dataVector);

	// Buildings name don't need to change in program
	// Actual data will be normal for save
	void setBuildingsData(std::vector<std::vector<uint64_t>> dataVector);

	 void setResourcesExtractData(std::vector<uint64_t> dataVector);

	 void setMarketData(std::vector<uint64_t> dataVector);

	 void setSettingsData(std::vector<uint16_t> dataVector);

	 void setResAutoSellData(std::vector<std::vector<uint64_t>> dataVector);

	 void setResAutoBuyData(std::vector<std::vector<uint64_t>> dataVector);

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
		keywordSettingsData = "setting:",
		keywordAutoSellData = "autoSell:",
		keywordAutoBuyData = "autoBuy:";
		
	const uint64_t MAX_PARAM_VALUE = 15'000'000'000'000'000'001;

	static const uint16_t
		COUNT_LOADING_DATA_UNIT_TO_THROW_ERROR = 1000,
		PLAYER_DATA_COUNT = 1,
		PLAYER_NAME_DATA_COUNT = 1,
		RESOURCES_COUNT = 11,
		RESOURCES_DATA_COUNT = 1,
		BUILDING_COUNT = 11,
		BUILDING_DATA_COUNT = 11,
		RESOURCES_EXTRACT_DATA_COUNT = 6,
		MARKET_DATA_COUNT = 1 + (BUILDING_COUNT * 2), // 2 - Count values in Market
		SETTINGS_DATA_COUNT = 1,
		RESOURCES_AUTO_SELL_LIST_COUNT = 3,
		RESOURCES_AUTO_SELL_DATA_COUNT = RESOURCES_COUNT,
		RESOURCES_AUTO_BUY_LIST_COUNT = 3,
		RESOURCES_AUTO_BUY_DATA_COUNT = RESOURCES_COUNT;


	//Data stroages
	std::vector<uint64_t> playerData;
	std::vector<std::string> playerNameData;

	std::vector<std::string> resourcesNameData;
	std::vector<std::vector<uint64_t>> resourcesData;

	std::vector<std::string> buildingNameData;
	std::vector<std::vector<uint64_t>> buildingsData;

	std::vector<uint64_t> resourcesExtractData;

	std::vector<uint64_t> marketData;

	std::vector<uint16_t> settingsData;
	
	std::vector<std::vector<uint64_t>> resAutoSellData;

	std::vector<std::vector<uint64_t>> resAutoBuyData;


	class LoadingComponents {
	public:
		static void goToStringInFile(std::ifstream& dataFile, std::string keyword)
		{
			std::string buffer = "0";

			while (buffer != keyword) {
				dataFile >> buffer;				
			}
		}


		template<typename dataType>
		static dataType readNumber(std::ifstream& dataFile)
		{
			dataType buffer = 0;

			dataFile >> buffer;

			if ((buffer == 0) or (buffer >= MAX_PARAM_VALUE)) // Limit for double
			{
				std::string errorMSG = "Broken data loaded!";

				throw std::exception(errorMSG.data());
			}
			//Data in file is for 1 unit bigger;
			buffer -= 1;

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
		static const uint64_t MAX_PARAM_VALUE = 15'000'000'000'000'000'001;

		LoadingComponents() {}
	};
	class SavingComponents
	{
	public:
		template<typename dataType>
		static dataType prepareNumberToSave(dataType number) {
			if (number <= MAX_PARAM_VALUE) {
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
		static const uint64_t MAX_PARAM_VALUE = 15'000'000'000'000'000'001;

		SavingComponents(){}
	};
	class Reset {
	public:
		Reset() {}

		void resetData(const std::string dataFileName) {

			std::ofstream dataFile(dataFileName);

			for (auto& item : restoreDataList)
			{
				dataFile << item << '\n';
			}
		}

		void resetDataWithSecurity(const std::string dataFileName)
		{
			std::cout << "You are in reset menu!" << std::endl
				<< "If u want to reset game data input - y" << std::endl
				<< "To cancel this process input any key" << std::endl
				<< "To reset game will be closed!" << std::endl;
				
			char select = '0';
			std::cin >> select;

			if (select == 'y') {
				std::ofstream dataFile(dataFileName);

				for (auto& item : restoreDataList)
				{
					dataFile << item << '\n';
				}

				exit(1);
			}			
		}

		void checkExistenceFileOrAskForCreate(const std::string dataFileName);

	private:
		const std::vector<std::string> restoreDataList {
			"playerName:",
			"Player/",
			"playerData:",
			"1",
			"resourcesName:",
			"Log/ Wood/ Stone/ Coal/ Copper/ Tin/ Bronze/ Silver/ Gold/ Platina/ Diamond/",
			"resourcesData:",
			"1",
			"1",
			"1",
			"1",
			"1",
			"1",
			"1",
			"1",
			"1",
			"1",
			"1",
			"buildingsName:",
			"Forestry/ Sawmill/ Quarry/ Career/ Copper Mine/ Tin Mine/ Alloy Plant/ Silver Cleaner/ Gold Mine/ Platina Cleaner/ Diamond Factory/",
			"buildingsData:",
			"1 2 1 101 121		6	1 38	1		1		101",
			"1 2 1 101 251		21	1 52	10		1		101",
			"1 2 1 101 501		53	1 73	22		8		101",
			"1 2 1 101 1001		69	1 101	26		16		101",
			"1 2 1 101 10001	85	1 251	51		26		101",
			"1 2 1 101 25001	101	1 501	101		51		101",
			"1 2 1 101 50001	117	1 1001	251		101		101",
			"1 2 1 101 100001	133	1 2501	501		251		101",
			"1 2 1 101 250001	149 1 5001	1001	501		101",
			"1 2 1 101 500001	165 1 10001 2501	1001	101",
			"1 2 1 101 1000001	181 1 50001 10001	5001	101",
			"resourcesExtract:",
			"2 101 2 501 2 1001",
			"marketData:",
			"175 2 1 3 1 4 1 6 1 11 1 21 1 46 1 81 1 151 1 251 1 1001 1",
			"setting:",
			"2",
			"autoSell:",
			"1 1 1 1 1 1 1 1 1 1 1",
			"1 1 1 1 1 1 1 1 1 1 1",
			"2 3 4 5 10 18 41 66 131 211 951",
			"autoBuy:",
			"1 1 1 1 1 1 1 1 1 1 1",
			"1 1 1 1 1 1 1 1 1 1 1",
			"2 3 4 6 11 21 46 81 151 251 1001"
		};
	};
	class WorkWithString {
	public:
		static void stringLeveling(std::vector<std::string>& stringVector);
	private:
		WorkWithString();
	};
};
