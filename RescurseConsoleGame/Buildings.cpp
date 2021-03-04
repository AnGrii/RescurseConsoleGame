#include "Buildings.h"

TempBuildings::TempBuildings(std::string name, std::vector<uint64_t> dataList)
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
}

void TempBuildings::SaveData(std::vector<uint64_t>& dataList)
{
	dataList[0] = count;
	dataList[1] = inQueue;
	dataList[2] = moneyNeeded;
	dataList[3] = valueOfSkipTime;
	dataList[4] = endBuildTime;
	dataList[5] = buildTime;
	dataList[6] = resource1;
	dataList[7] = resource2;
	dataList[8] = resource3;
}
