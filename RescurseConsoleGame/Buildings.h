#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Resource.h"


class Building
{
public:
	Building() :
	count(0), productivity(0), inQueue(0),
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
	
	uint64_t getValueSkipTime();
	uint64_t getBuildTime();
	bool getActiveStatus();


	
	bool isInQueue();
	bool addInQueue();
	void updateQueue();
	void printQueueInfo();

	void brokeBuild();

	void buildInfo();

	std::string getName() { return name; }

private:
	uint64_t count, productivity, inQueue, valueOfSkipTime,
		buildTime, endBuildTime, resource1, resource2, resource3;
	bool activated;
	std::string name;
};


class BuildingsManager
{
public:
	BuildingsManager(std::vector<std::string> nameData,
		std::vector< std::vector<uint64_t>> buildingsData);

	void buildMenu(ResourceManager& res);

	void work(ResourceManager& res);
	//void BuildingInfo();
	
	void updateBuildingsBuild();

	void printQueueStatus();

	void brokeEvent();

	void printBuildingsInfo();

private:
	Building 
		forestry, sawmill, quarry, career,
		copperMine, tinMine, alloyPlant,
		silverCleaner, goldMine,
		platinaCleaner, diamondFactory;

	void printBuildRequest(Building build, std::string buildSymb,
		std::string resourceName1, 
		std::string resourceName2, 
		std::string resourceName3 );

	void build(Building& build, 
		Resource &reqRes1, Resource &reqRes2, Resource &reqRes3 );
};
