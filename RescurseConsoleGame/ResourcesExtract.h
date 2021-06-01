#pragma once
#include <iostream>
#include <vector>

#include "Resource.h"
#include "Player.h"
#include "SafetyInput.h"

class ResourcesExtract
{
public:
	ResourcesExtract(std::vector<uint64_t> dataVector);
	std::vector<uint64_t> UploadData();

	void extract(Resource& log, Resource& wood, Resource& stone);

	void upgradeResourceExtractionMenu(Player& p);

private:
	const double VALUE_INCREASE_COEFICIENT = 0.35;
	const uint16_t RESOURCE_EXTRACT_DATA_COUNT = 6;

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


