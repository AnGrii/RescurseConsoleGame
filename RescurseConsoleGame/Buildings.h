#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Resource.h"

class Buildings
{
public:
	Buildings(std::string name, std::vector<uint64_t> dataList);
	//void SaveData(std::vector<uint64_t>& dataList);

private:
	std::string name;
	uint64_t count, inQueue, moneyNeeded, valueOfSkipTime, buildTime, endBuildTime ,resource1, resource2, resource3;
};

