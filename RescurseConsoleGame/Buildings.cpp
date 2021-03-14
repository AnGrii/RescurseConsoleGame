#include "Buildings.h"

void BuildTemplate::Reinitialisate(std::vector<uint64_t> dataList)
{
	count = dataList[0];
	productivity = dataList[1];
	inQueue = dataList[2];
	moneyNeeded = dataList[3];
	valueOfSkipTime = dataList[4];
	endBuildTime = dataList[5];
	buildTime = dataList[6];
	resource1 = dataList[7];
	resource2 = dataList[8];
	resource3 = dataList[9];
	activated = dataList[10];
}

uint64_t BuildTemplate::getRes1()
{
	return resource1;
}

uint64_t BuildTemplate::getRes2()
{
	return resource2;
}

uint64_t BuildTemplate::getRes3()
{
	return resource3;
}

Buildings::Buildings(std::vector<std::vector<uint64_t>> dataList)
{
	forestry.Reinitialisate(dataList[0]);
	sawmill.Reinitialisate(dataList[1]);
	quarry.Reinitialisate(dataList[2]);
	copperMine.Reinitialisate(dataList[3]);
	tinMine.Reinitialisate(dataList[4]);
	alloyPlant.Reinitialisate(dataList[5]);
	silverCleaner.Reinitialisate(dataList[6]);
	goldMine.Reinitialisate(dataList[7]);
	platinaCleaner.Reinitialisate(dataList[8]);
	diamondFactory.Reinitialisate(dataList[9]);
}

void Buildings::BuildMenu()
{
	//forestry, sawmill, quarry, copperMine, tinMine, alloyPlant, silverCleaner, stone—leaner, goldMine, platinaCleaner, diamondFactory;
	std::cout << "Select build:" << std::endl;

	printBuildRequest("Forestry", "Wood", "Log", "Stone");
	printBuildRequest("Sawmill", "Wood", "Log", "Stone");
	printBuildRequest("Quarry", "Wood", "Log", "Stone");
	printBuildRequest("Copper Mine", "Wood", "Log", "Stone");
	printBuildRequest("Tin Mine", "Log", "Stone", "Copper");
	printBuildRequest("Alloy Plant", "Log", "Stone", "Copper");
	printBuildRequest("Silver Cleaner", "Stone", "Copper", "Bronze");
	printBuildRequest("Gold Mine", "Copper", "Bronze", "Silver");
	printBuildRequest("Platina Cleaner", "Bronze", "Silver", "Gold");
	printBuildRequest("Platina Cleaner", "Bronze", "Silver", "Gold");
	printBuildRequest("Diamond Factory", "Silver", "Gold", "Platina");
}

void Buildings::printBuildRequest(std::string buildName,
	std::string resourceName1,
	std::string resourceName2,
	std::string resourceName3)
{
	std::cout
		<< "========== "
		<< buildName 
		<< " ==========" 
		<< std::endl << std::endl
		<< resourceName1 << " - " << forestry.getRes1() << '\t'
		<< resourceName2 << " - " << forestry.getRes2() << '\t'
		<< resourceName3 << " - " << forestry.getRes3() << std::endl << std::endl;
}
