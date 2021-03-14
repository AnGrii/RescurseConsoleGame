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

	uint64_t getRes1();
	uint64_t getRes2();
	uint64_t getRes3();

	
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
		forestry, sawmill, quarry, career,
		copperMine, tinMine, alloyPlant,
		silverCleaner, goldMine,
		platinaCleaner, diamondFactory;

	void printBuildRequest(std::string buildName,
		std::string resourceName1, 
		std::string resourceName2, 
		std::string resourceName3 );
};
