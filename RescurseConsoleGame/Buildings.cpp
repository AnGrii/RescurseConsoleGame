#include "Buildings.h"

void TempBuildings::Reinitialisate(std::vector<uint64_t> dataList)
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
	Forestry.Reinitialisate(dataList[0]);
	Sawmill.Reinitialisate(dataList[1]);
	Mine.Reinitialisate(dataList[2]);
}
