#pragma once
#include <iostream>
#include <vector>

#include "Resource.h"

class ResourcesExtract
{
public:
	ResourcesExtract(std::vector<uint64_t> dataList);

	void extract(Resource& log, Resource& wood, Resource& stone);

private:
	uint64_t logExtract, upgradeLogExtractValue,
		woodExtract, upgradeWoodExtractValue,
		stoneExtract, upgradeStoneExtractValue;

	void extractLog(Resource& log);
	void extractWood(Resource& log, Resource& wood);
	void extractStone(Resource& wood, Resource& stone);

	static const uint32_t
		LOG_TO_WOOD_NEEDED = 2,
		WOOD_TO_STONE_NEDDED = 5;
};

