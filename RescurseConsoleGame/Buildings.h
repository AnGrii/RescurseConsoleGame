#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>


class Building
{
public:
	Building() :
	count(0), productionOutput(0), inQueue(0),
		skipTimeValue(0), upgradeValue(0), buildTime(0), endBuildTime(0),
		resource1(0), resource2(0), resource3(0), powerPercent(0),
	name("NoName"){}
	void Reinitialisate(std::vector<uint64_t> buildingData, std::string name);
	std::vector<uint64_t> UploadData();

	uint64_t getRes1();
	uint64_t getRes2();
	uint64_t getRes3();

	void increaseResValue1();
	void increaseResValue2();
	void increaseResValue3();

	void increaseSkipValue();

	void increaseUpgradeValue();

	void addCount(uint64_t addCount);

	uint64_t getCount();

	uint64_t getProductionOutput();
	uint64_t calcProductivity(); //Calculate
	void setProductivity(uint64_t percent);
	std::string getProductivityInfo();
	

	uint64_t getBuildTime();
	bool getActiveStatus();
	
	uint64_t getSkipValue();

	uint64_t getUpgradeValue();

	bool isInQueue();
	bool addInQueue();
	void updateQueue();
	std::string getQueueInfo();

	std::string getSkipInfo();
	
	void skipBuildingProcess(bool payStatus);
	void brokeBuild();

	void buildInfo();

	std::string getUpgradeBuildInfo();
	void increaseProductivity(bool payStatus);

	std::string getName() { return name; }

private:
	static const uint16_t BUILDING_DATA_COUNT = 12;

	uint64_t count, productionOutput, inQueue, skipTimeValue, upgradeValue,
		buildTime, endBuildTime, resource1, resource2, resource3, powerPercent,
		autoSellPercent;
	std::string name;

	const double INCREASE_VALUE_COEFFICIENT = 1.2;

	void skipBuildingTime();
};
