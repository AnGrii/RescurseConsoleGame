#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Resource.h"
#include "ResourceManager.h"
#include "Buildings.h"
#include "Player.h"
#include "SafetyInput.h"


class BuildingsManager
{
public:
	BuildingsManager(std::vector<std::string> nameData,
		std::vector< std::vector<uint64_t>> buildingsData);

	std::vector<std::vector<uint64_t>> UploadData();

	void work(ResourceManager& res);

	void printBuildingsInfo();

	void printQueueStatus();
	void updateBuildingsQueue();
	
	void productivitySettingMenu();

	void skipBuildingMenu(Player& p);

	void upgradeMenu(Player& p);
	void buildMenu(ResourceManager& res);

	void brokeEvent();
private:
	static const uint16_t BUILDINGS_COUNT = 11;

	Building
		forestry, sawmill, quarry, career,
		copperMine, tinMine, alloyPlant,
		silverCleaner, goldMine,
		platinaCleaner, diamondFactory;

	Building* BuildingsVector[BUILDINGS_COUNT]{
		&forestry, &sawmill,& quarry,& career,
		&copperMine,& tinMine,& alloyPlant,
		&silverCleaner,& goldMine,
		&platinaCleaner,& diamondFactory
	};

	void printResourceRequest(Building build, std::string buildSymb,
		std::string resourceName1,
		std::string resourceName2,
		std::string resourceName3);

	void printResourceRequest(char buildSymb, Building build,
		Resource res1, Resource res2, Resource res3);

	void build(Building& build,
		Resource& reqRes1, Resource& reqRes2, Resource& reqRes3);
};
