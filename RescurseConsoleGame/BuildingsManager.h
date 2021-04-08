#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Resource.h"
#include "ResourceManager.h"
#include "Buildings.h"
#include "Player.h"


class BuildingsManager
{
public:
	BuildingsManager(std::vector<std::string> nameData,
		std::vector< std::vector<uint64_t>> buildingsData);

	void buildMenu(ResourceManager& res);

	void work(ResourceManager& res);

	void updateBuildingsQueue();

	void printQueueStatus();

	void brokeEvent();

	void printBuildingsInfo();

	void SkipBuildingMenu(Player& p);

	void upgradeMenu(Player& p);
private:
	Building
		forestry, sawmill, quarry, career,
		copperMine, tinMine, alloyPlant,
		silverCleaner, goldMine,
		platinaCleaner, diamondFactory;

	void printBuildRequest(Building build, std::string buildSymb,
		std::string resourceName1,
		std::string resourceName2,
		std::string resourceName3);

	void build(Building& build,
		Resource& reqRes1, Resource& reqRes2, Resource& reqRes3);

	void upgradeInfo();
	void upgradeBuildingsMenu(Player& p);
};
