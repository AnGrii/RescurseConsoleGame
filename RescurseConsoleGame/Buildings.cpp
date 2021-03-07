#include "Buildings.h"

void BuildTemplate::Reinitialisate(std::vector<uint64_t> dataList)
{
	count = dataList[0];
	inQueue = dataList[1];
	moneyNeeded = dataList[2];
	valueOfSkipTime = dataList[3];
	endBuildTime = dataList[4];
	buildTime = dataList[5];
	resource1 = dataList[6];
	resource2 = dataList[7];
	resource3 = dataList[8];
	activated = dataList[9];
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
