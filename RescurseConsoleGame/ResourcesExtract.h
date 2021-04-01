#pragma once
#include <iostream>
#include <vector>

#include "Resource.h"
#include "Player.h"

class ResourcesExtract
{
public:
	ResourcesExtract(std::vector<uint64_t> dataList);

	void extract(Resource& log, Resource& wood, Resource& stone);

	void upgradeResourceExtractionMenu(Player& p);

private:
	const double VALUE_INCREASE_COEFICIENT = 0.2;

	uint64_t logExtract, upgradeLogExtractValue,
		woodExtract, upgradeWoodExtractValue,
		stoneExtract, upgradeStoneExtractValue;

	void extractLog(Resource& log);
	void extractWood(Resource& log, Resource& wood);
	void extractStone(Resource& wood, Resource& stone);

	static const uint32_t
		LOG_TO_WOOD_NEEDED = 2,
		WOOD_TO_STONE_NEDDED = 5;

	void increaseLogExtractUpgradeValue();
	void increaseWoodExtractUpgradeValue();
	void increaseStoneExtractUpgradeValue();

	void upgradeLogExtraction(Player& p);
	void upgradeWoodExtraction(Player& p);
	void upgradeStoneExtraction(Player& p);


	void upgradeExtractionInfo();
	void upgradeExtractionMenu(Player& p);
};


