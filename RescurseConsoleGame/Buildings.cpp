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

	printBuildRequest(forestry, "Forestry", "Wood", "Log", "Stone");
	printBuildRequest(sawmill, "Sawmill", "Wood", "Log", "Stone");
	printBuildRequest(quarry,"Quarry", "Wood", "Log", "Stone");
	printBuildRequest(career,"Carrer", "Wood", "Log", "Stone");
	printBuildRequest(copperMine,"Copper Mine", "Wood", "Log", "Stone");
	printBuildRequest(tinMine,"Tin Mine", "Log", "Stone", "Copper");
	printBuildRequest(alloyPlant,"Alloy Plant", "Log", "Stone", "Copper");
	printBuildRequest(silverCleaner,"Silver Cleaner", "Stone", "Copper", "Bronze");
	printBuildRequest(goldMine,"Gold Mine", "Copper", "Bronze", "Silver");
	printBuildRequest(platinaCleaner,"Platina Cleaner", "Bronze", "Silver", "Gold");
	printBuildRequest(diamondFactory,"Diamond Factory", "Silver", "Gold", "Platina");
}

void Buildings::printBuildRequest(BuildTemplate build, std::string buildName,
	std::string resourceName1,
	std::string resourceName2,
	std::string resourceName3)
{
	std::cout
		<< "========== "
		<< buildName 
		<< " ==========" 
		<< std::endl << std::endl
		<< resourceName1 << " - " << build.getRes1() << '\t'
		<< resourceName2 << " - " << build.getRes2() << '\t'
		<< resourceName3 << " - " << build.getRes3() << std::endl << std::endl;
}
