#include "ResourcesEtract.h"

ResourcesExtract::ResourcesExtract(std::vector<uint64_t> dataList)
{
	uint16_t counter = 0;

	logExtract = dataList[counter++];
	woodExtract = dataList[counter++];
	stoneExtract = dataList[counter++];
}

void ResourcesExtract::extract(Resource& log, Resource& wood, Resource& stone)
{
	std::cout << "Select type of resource!" << std::endl
		<< "l - Log / w - Wood / s - Stone!" << std::endl
		<< "Input: ";

	char select = '0';

	std::cin >> select;

	std::cout << std::endl;

	switch (select)
	{
	case 'l':
		extractLog(log);
		break;
	case 'w':
		extractWood(log, wood);
		break;
	case 's':
		extractStone(wood, stone);
		break;
	default:
		std::cout << "Incorrect input!" << std::endl;
		break;
	}
}

void ResourcesExtract::extractLog(Resource& log)
{
	log.add(logExtract);

	std::cout << "Cutted " << uint16_t(logExtract) << " logs!" << std::endl << std::endl;
}

void ResourcesExtract::extractWood(Resource& log, Resource& wood)
{
	if (log.getCount() >= LOG_TO_WOOD_NEEDED) {
		log.reduce(LOG_TO_WOOD_NEEDED);
		wood.add(woodExtract);

		std::cout << "Cutted " << uint16_t(LOG_TO_WOOD_NEEDED) << " logs, added "
			<< uint16_t(woodExtract) << " woods!" << std::endl << std::endl;
	}
	else {
		std::cout << "Not enough logs to cut to woods! 2 nedded!!!" << std::endl << std::endl;
	}
}

void ResourcesExtract::extractStone(Resource& wood, Resource& stone)
{
	if (WOOD_TO_STONE_NEDDED <= wood.getCount()) {
		wood.reduce(WOOD_TO_STONE_NEDDED);
		stone.add(stoneExtract);

		std::cout << "Builded new branch of mine for " << WOOD_TO_STONE_NEDDED << " woods!" << std::endl
			<< "Mined " << stoneExtract << " stones!" << std::endl << std::endl;
	}
	else {
		std::cout << "Not enough woods to build new side of mine! "
			<< WOOD_TO_STONE_NEDDED << " nedded!!!" << std::endl << std::endl;
	}
}
