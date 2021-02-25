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
		extractStone(stone);
		break;
	default:
		std::cout << "Incorrect input!" << std::endl;
		break;
	}
}

void ResourcesEtract::extractLog(ResTemplate& log)
{
	uint8_t ADD_LOG = 1;

	log.add(ADD_LOG);

	std::cout << "Cutted " << uint16_t(ADD_LOG) << " logs!" << std::endl;
}

void ResourcesEtract::extractWood(ResTemplate& log, ResTemplate& wood)
{
	uint8_t CUTTED_LOG = 2, ADD_WOOD = 1;

	if (log.getCount() >= CUTTED_LOG)
	{
		log.reduce(CUTTED_LOG);
		wood.add(ADD_WOOD);

		std::cout << "Cutted " << uint16_t(CUTTED_LOG) << " logs, added "
			<< uint16_t(ADD_WOOD) << " woods!" << std::endl;
	}
}

void ResourcesEtract::extractStone(ResTemplate& stone)
{
	uint8_t ADD_STONE = 1;

	stone.add(ADD_STONE);

	std::cout << "Mined " << uint16_t(ADD_STONE) << " stones!" << std::endl;
}
