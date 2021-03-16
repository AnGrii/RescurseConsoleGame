#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Resource.h"

class BuildTemplate
{
public:
	BuildTemplate() :
	count(0), productivity(0), inQueue(0), moneyNeeded(0),
		valueOfSkipTime(0), buildTime(0), endBuildTime(0),
		resource1(0), resource2(0), resource3(0), activated(0),
	name("NoName"){}

	void Reinitialisate(std::vector<uint64_t> buildingData, std::string name);

	uint64_t getRes1();
	uint64_t getRes2();
	uint64_t getRes3();

	void addCount(uint64_t addCount);

	uint64_t getCount();
	uint64_t getProductivity();
	
	bool isInQueue();
	bool addInQueue();

	void updateQueue();

	std::string getName() { return name; }

private:
	uint64_t count, productivity, inQueue, moneyNeeded, valueOfSkipTime,
		buildTime, endBuildTime, resource1, resource2, resource3;
	bool activated;
	std::string name;
};


class Buildings
{
public:
	Buildings(std::vector<std::string> nameData,
		std::vector< std::vector<uint64_t>> buildingsData);

	void buildMenu(Resource& res);

	void work(Resource& res);
	//void BuildingInfo();
	
	void updateBuildingsBuild();

private:
	BuildTemplate 
		forestry, sawmill, quarry, career,
		copperMine, tinMine, alloyPlant,
		silverCleaner, goldMine,
		platinaCleaner, diamondFactory;

	void printBuildRequest(BuildTemplate build, std::string buildSymb,
		std::string resourceName1, 
		std::string resourceName2, 
		std::string resourceName3 );

	void build(BuildTemplate& build, 
		ResTemplate &reqRes1, ResTemplate &reqRes2, ResTemplate &reqRes3 );


};
