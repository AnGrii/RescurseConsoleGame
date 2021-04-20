#include "ResourcesExtract.h"

ResourcesExtract::ResourcesExtract(std::vector<uint64_t> dataList)
{
	uint16_t counter = 0;

	logExtract = dataList[counter++];
	upgradeLogExtractValue = dataList[counter++];
	woodExtract = dataList[counter++];
	upgradeWoodExtractValue = dataList[counter++];
	stoneExtract = dataList[counter++];
	upgradeStoneExtractValue = dataList[counter++];	
}

std::vector<uint64_t> ResourcesExtract::UploadData()
{
	std::vector<uint64_t> dataVector;

	dataVector.reserve(RESOURCE_EXTRACT_DATA_COUNT);

	dataVector.push_back(logExtract);
	dataVector.push_back(upgradeLogExtractValue);
	dataVector.push_back(woodExtract);
	dataVector.push_back(upgradeWoodExtractValue);
	dataVector.push_back(stoneExtract);
	dataVector.push_back(upgradeStoneExtractValue);

	return dataVector;
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

void ResourcesExtract::upgradeResourceExtractionMenu(Player& p)
{
	this->upgradeExtractionInfo();
	this->upgradeExtractionMenu(p);
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

void ResourcesExtract::increaseLogExtractUpgradeValue()
{
	upgradeLogExtractValue = uint64_t(upgradeLogExtractValue \
		* double(1.0 + VALUE_INCREASE_COEFICIENT));
}
void ResourcesExtract::increaseWoodExtractUpgradeValue()
{
	upgradeWoodExtractValue = uint64_t(upgradeWoodExtractValue \
		* double(1.0 + VALUE_INCREASE_COEFICIENT));
}
void ResourcesExtract::increaseStoneExtractUpgradeValue()
{
	upgradeStoneExtractValue = uint64_t(upgradeStoneExtractValue \
		* double(1.0 + VALUE_INCREASE_COEFICIENT));
}

void ResourcesExtract::upgradeLogExtraction(Player& p)
{
	if (p.payAndGetStatus(upgradeLogExtractValue)) {
		logExtract++;
		this->increaseLogExtractUpgradeValue();
	}
	else
	{
		std::cout << "Not enough money!!!" << std::endl;
	}
}
void ResourcesExtract::upgradeWoodExtraction(Player& p)
{
	if (p.payAndGetStatus(upgradeWoodExtractValue)) {
		woodExtract++;
		this->increaseWoodExtractUpgradeValue();
	}
	else
	{
		std::cout << "Not enough money!!!" << std::endl;
	}
}
void ResourcesExtract::upgradeStoneExtraction(Player& p)
{
	if (p.payAndGetStatus(upgradeStoneExtractValue)) {
		stoneExtract++;
		this->increaseStoneExtractUpgradeValue();
	}
	else
	{
		std::cout << "Not enough money!!!" << std::endl;
	}
}

void ResourcesExtract::upgradeExtractionInfo()
{
	std::cout << "Value of extract upgrade:" << std::endl
		<< "Upgrade will increase extrat to 1 unit!!!" << std::endl
		<< "Count of resources needed to extract will not changed!!!" << std::endl
		<< "1 - Log level: " << logExtract << " upgrade value: "
		<< upgradeLogExtractValue << std::endl
		<< "2 - Wood level: " << woodExtract << " upgrade value: "
		<< upgradeWoodExtractValue << std::endl
		<< "3 - Stone level: " << stoneExtract << " upgrade value: "
		<< upgradeStoneExtractValue << std::endl << std::endl;
}
void ResourcesExtract::upgradeExtractionMenu(Player &p)
{
	char select = '0';

	std::cout << "Input name id to upgrade: ";
	std::cin >> select;
	std::cout << std::endl;

	switch (select)
	{
	case '1':
		upgradeLogExtraction(p);
		break;
	case '2':
		upgradeWoodExtraction(p);
		break;
	case '3':
		upgradeStoneExtraction(p);
		break;
	default:
		break;
	}
}
