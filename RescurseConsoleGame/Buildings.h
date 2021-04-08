#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>


class Building
{
public:
	Building() :
	count(0), productivity(0), inQueue(0),
		skipTimeValue(0), upgradeValue(0), buildTime(0), endBuildTime(0),
		resource1(0), resource2(0), resource3(0), activated(0),
	name("NoName"){}

	void Reinitialisate(std::vector<uint64_t> buildingData, std::string name);

	uint64_t getRes1();
	uint64_t getRes2();
	uint64_t getRes3();

	void increaseResValue1();
	void increaseResValue2();
	void increaseResValue3();

	void increaseSkipValue();

	void addCount(uint64_t addCount);

	uint64_t getCount();
	uint64_t getProductivity();
	
	uint64_t getBuildTime();
	bool getActiveStatus();
	
	uint64_t getSkipValue();

	bool isInQueue();
	bool addInQueue();
	void updateQueue();
	void printQueueInfo();

	void printSkipInfo(char nameId);
	
	void skipBuildingProcess(bool payStatus);
	void brokeBuild();

	void buildInfo();

	void upgradeBuildings();

	std::string getUpgradeBuildInfo();
	void increaseProductivity();

	std::string getName() { return name; }

private:
	uint64_t count, productivity, inQueue, skipTimeValue, upgradeValue, 
		buildTime, endBuildTime, resource1, resource2, resource3;
	bool activated;
	std::string name;

	const double INCREASE_VALUE_COEFFICIENT = 1.2;

	void skipBuildingTime();

	static void upgradeBuildingsInfo();
	static void upgradeBuildingsMenu();
};
