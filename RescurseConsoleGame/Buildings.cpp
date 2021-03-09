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

Buildings::Buildings(std::vector<std::vector<uint64_t>> dataList)
{
	forestry.Reinitialisate(dataList[0]);
	sawmill.Reinitialisate(dataList[1]);
	quarry.Reinitialisate(dataList[2]);
	copperMine.Reinitialisate(dataList[3]);
	tinMine.Reinitialisate(dataList[4]);
	alloyPlant.Reinitialisate(dataList[5]);
	silverCleaner.Reinitialisate(dataList[6]);
	stone—leaner.Reinitialisate(dataList[7]);
	goldMine.Reinitialisate(dataList[8]);
	platinaCleaner.Reinitialisate(dataList[9]);
	diamondFactory.Reinitialisate(dataList[10]);
}

void Buildings::BuildMenu()
{
	//forestry, sawmill, quarry, copperMine, tinMine, alloyPlant, silverCleaner, stone—leaner, goldMine, platinaCleaner, diamondFactory;
	std::cout << "Select build:" << std::endl;
}
