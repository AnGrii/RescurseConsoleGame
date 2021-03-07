#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Resource.h"

class TempBuildings
{
public:
	TempBuildings() :
	count(0), inQueue(0), moneyNeeded(0), valueOfSkipTime(0), buildTime(0), endBuildTime(0), resource1(0), resource2(0), resource3(0), activated(0){}

	void Reinitialisate(std::vector<uint64_t> dataList);
	
private:
	uint64_t count, inQueue, moneyNeeded, valueOfSkipTime, buildTime, endBuildTime, resource1, resource2, resource3;
	bool activated;
};


class Buildings
{
public:
	Buildings(std::vector< std::vector<uint64_t>> dataList);

	void BuildMenu();
	//void BuildInfo();
	//void BuildingInfo();
	//void BuildMenu();

private:
	TempBuildings Forestry, Sawmill, Mine;
};
