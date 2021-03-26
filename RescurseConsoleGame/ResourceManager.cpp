#include "ResourceManager.h"

ResourceManager::ResourceManager(std::vector< std::vector<uint64_t>> dataList)
{
	uint16_t counter = 0;

	log.Reinitialisate(dataList[counter++]);
	wood.Reinitialisate(dataList[counter++]);
	stone.Reinitialisate(dataList[counter++]);
	coal.Reinitialisate(dataList[counter++]);
	copper.Reinitialisate(dataList[counter++]);
	tin.Reinitialisate(dataList[counter++]);
	bronze.Reinitialisate(dataList[counter++]);
	silver.Reinitialisate(dataList[counter++]);
	gold.Reinitialisate(dataList[counter++]);
	platina.Reinitialisate(dataList[counter++]);
	diamond.Reinitialisate(dataList[counter++]);
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