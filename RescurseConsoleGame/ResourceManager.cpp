#include "ResourceManager.h"

ResourceManager::ResourceManager(std::vector<std::string> nameList,
	std::vector< std::vector<uint64_t>> dataList)
{
	uint16_t counter = 0;

	log.Reinitialisate		(nameList[counter], dataList[counter++]);
	wood.Reinitialisate		(nameList[counter], dataList[counter++]);
	stone.Reinitialisate	(nameList[counter], dataList[counter++]);
	coal.Reinitialisate		(nameList[counter], dataList[counter++]);
	copper.Reinitialisate	(nameList[counter], dataList[counter++]);
	tin.Reinitialisate		(nameList[counter], dataList[counter++]);
	bronze.Reinitialisate	(nameList[counter], dataList[counter++]);
	silver.Reinitialisate	(nameList[counter], dataList[counter++]);
	gold.Reinitialisate		(nameList[counter], dataList[counter++]);
	platina.Reinitialisate	(nameList[counter], dataList[counter++]);
	diamond.Reinitialisate	(nameList[counter], dataList[counter]);
}

void ResourceManager::printResourcesCount()
{
	std::cout
		<< "Log:\t" << log.getCount() << "\t\tBronze:\t" << bronze.getCount() << std::endl
		<< "Wood:\t" << wood.getCount() << "\t\tSilver:\t" << silver.getCount() << std::endl
		<< "Stone:\t" << stone.getCount() << "\t\tGold:\t" << gold.getCount() << std::endl
		<< "Coal:\t" << coal.getCount() << "\t\tPlatina:" << platina.getCount() << std::endl
		<< "Copper:\t" << copper.getCount() << "\t\tDiamond:" << diamond.getCount() << std::endl
		<< "Tin:\t" << tin.getCount() << std::endl
		<< std::endl;
}