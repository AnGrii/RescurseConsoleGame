#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Resource.h"

class BuildTemplate
{
public:
	BuildTemplate() :
	count(0), productivity(0), inQueue(0), moneyNeeded(0), valueOfSkipTime(0), buildTime(0), endBuildTime(0), resource1(0), resource2(0), resource3(0), activated(0){}

	void Reinitialisate(std::vector<uint64_t> dataList);
	
private:
	uint64_t count, productivity, inQueue, moneyNeeded, valueOfSkipTime, buildTime, endBuildTime, resource1, resource2, resource3;
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
	BuildTemplate 
		forestry, sawmill, quarry,
		copperMine, tinMine, alloyPlant,
		silverCleaner, stone—leaner, goldMine,
		platinaCleaner, diamondFactory;
	//log, wood, stone, coal, copper, tin, bronze, silver, gold, platina, diamond;
};
