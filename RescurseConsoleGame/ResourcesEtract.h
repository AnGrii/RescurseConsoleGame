#pragma once
#include <iostream>

#include "Resource.h"

class ResourcesEtract
{
public:
	static void extract(Resource& log, Resource& wood, Resource& stone);

private:
	static void extractLog(Resource& log);
	static void extractWood(Resource& log, Resource& wood);
	static void extractStone(Resource& wood, Resource& stone);

	static const uint32_t LOG_EXTRACT = 1,
		LOG_TO_WOOD_NEEDED = 2,
		WOOD_EXTRACT = 1,
		WOOD_TO_STONE_NEDDED = 5,
		STONE_EXTACT = 2;
};

