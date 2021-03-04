#pragma once
#include <iostream>

#include "Resource.h"

class ResourcesEtract
{
public:
	static void extract(ResTemplate& log, ResTemplate& wood, ResTemplate& stone);

private:
	static void extractLog(ResTemplate& log);
	static void extractWood(ResTemplate& log, ResTemplate& wood);
	static void extractStone(ResTemplate& wood, ResTemplate& stone);

	static const uint32_t LOG_EXTRACT = 1, LOG_TO_WOOD_NEEDED = 2, WOOD_EXTRACT = 1, WOOD_TO_STONE_NEDDED = 5, STONE_EXTACT = 2;
};

