#include "Buildings.h"

void BuildTemplate::Reinitialisate(std::vector<uint64_t> buildingData)
{
	count = buildingData[0];
	productivity = buildingData[1];
	inQueue = buildingData[2];
	moneyNeeded = buildingData[3];
	valueOfSkipTime = buildingData[4];
	endBuildTime = buildingData[5];
	buildTime = buildingData[6];
	resource1 = buildingData[7];
	resource2 = buildingData[8];
	resource3 = buildingData[9];
	activated = buildingData[10];
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

Buildings::Buildings(std::vector<std::vector<uint64_t>> buildingsData)
{
	forestry.Reinitialisate(buildingsData[0]);
	sawmill.Reinitialisate(buildingsData[1]);
	quarry.Reinitialisate(buildingsData[2]);
	career.Reinitialisate(buildingsData[3]);
	copperMine.Reinitialisate(buildingsData[4]);
	tinMine.Reinitialisate(buildingsData[5]);
	alloyPlant.Reinitialisate(buildingsData[6]);
	silverCleaner.Reinitialisate(buildingsData[7]);
	goldMine.Reinitialisate(buildingsData[8]);
	platinaCleaner.Reinitialisate(buildingsData[9]);
	diamondFactory.Reinitialisate(buildingsData[10]);
}

void Buildings::BuildMenu()
{
	std::cout << "Select build:" << std::endl;

	printBuildRequest("Forestry", "Wood", "Log", "Stone");
	printBuildRequest("Sawmill", "Wood", "Log", "Stone");
	printBuildRequest("Quarry", "Wood", "Log", "Stone");
	printBuildRequest("Carrer", "Wood", "Log", "Stone");
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
