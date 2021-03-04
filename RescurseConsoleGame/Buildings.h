#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Resource.h"

class TempBuildings
{
public:
	TempBuildings(std::string name, std::vector<uint64_t> dataList);
	void SaveData(std::vector<uint64_t>& dataList);

private:
	std::string name;
	uint64_t count, inQueue, moneyNeeded, valueOfSkipTime, buildTime, endBuildTime, resource1, resource2, resource3;
};


class Buildings
{
public:
	Buildings();
	
	//void BuildMenu();

private:
	TempBuildings Forestry, Sawmill, Mine;
};
