#include "ResourcesEtract.h"

void ResourcesEtract::extract(ResTemplate& log, ResTemplate& wood, ResTemplate& stone)
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
	case 's':
		extractWood(log, wood);
		break;
	case 'w':
		extractStone(stone, wood);
		break;
	default:
		std::cout << "Incorrect input!" << std::endl;
		break;
	}
}

void ResourcesEtract::extractLog(ResTemplate& log)
{
	log.add(LOG_EXTRACT);

	std::cout << "Cutted " << uint16_t(LOG_EXTRACT) << " logs!" << std::endl;
}

void ResourcesEtract::extractWood(ResTemplate& log, ResTemplate& wood)
{
	if (log.getCount() >= LOG_TO_WOOD_NEEDED)
	{
		log.reduce(LOG_TO_WOOD_NEEDED);
		wood.add(WOOD_EXTRACT);

		std::cout << "Cutted " << uint16_t(LOG_TO_WOOD_NEEDED) << " logs, added "
			<< uint16_t(WOOD_EXTRACT) << " woods!" << std::endl;
	}
	else{
		std::cout << "Not enough logs to cut to woods! 2 nedded!!!" << std::endl;
	}
}

void ResourcesEtract::extractStone(ResTemplate& wood, ResTemplate& stone)
{
	if (wood.getCount() >= WOOD_TO_STONE_NEDDED) {

		wood.reduce(WOOD_TO_STONE_NEDDED);
		stone.add(STONE_EXTACT);

		std::cout << "Builded new branch of mine for " << WOOD_TO_STONE_NEDDED << " woods!" << std::endl
			<< "Mined " << uint16_t(STONE_EXTACT) << " stones!" << std::endl;
	}
	else{
		std::cout << "Not enough woods to build new side of mine! 5 nedded!!!" << std::endl;
	}
}
