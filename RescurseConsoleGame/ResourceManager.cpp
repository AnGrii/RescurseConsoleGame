#include "ResourceManager.h"

ResourceManager::ResourceManager(std::vector<std::string> nameList,
	std::vector< std::vector<uint64_t>> dataList)
{
	uint16_t counter = 0;

	log.Reinitialisate		(nameList[counter], dataList[counter]); counter++;
	wood.Reinitialisate		(nameList[counter], dataList[counter]); counter++;
	stone.Reinitialisate	(nameList[counter], dataList[counter]); counter++;
	coal.Reinitialisate		(nameList[counter], dataList[counter]); counter++;
	copper.Reinitialisate	(nameList[counter], dataList[counter]); counter++;
	tin.Reinitialisate		(nameList[counter], dataList[counter]); counter++;
	bronze.Reinitialisate	(nameList[counter], dataList[counter]); counter++;
	silver.Reinitialisate	(nameList[counter], dataList[counter]); counter++;
	gold.Reinitialisate		(nameList[counter], dataList[counter]); counter++;
	platina.Reinitialisate	(nameList[counter], dataList[counter]); counter++;
	diamond.Reinitialisate	(nameList[counter], dataList[counter]); counter++;
}

void ResourceManager::printResourcesCount()
{
	std::cout
		<< log.getName() << ":\t" << log.getCount() << "\t\t"
		<< bronze.getName() << ":\t" << bronze.getCount() << std::endl
		<< wood.getName()<<":\t" << wood.getCount() << "\t\t"
		<< silver.getName() << ":\t" << silver.getCount() << std::endl
		<< stone.getName() << ":\t" << stone.getCount() << "\t\t"
		<< gold.getName() << ":\t" << gold.getCount() << std::endl
		<< coal.getName() << ":\t" << coal.getCount() << "\t\t"
		<< platina.getName() << ":" << platina.getCount() << std::endl
		<< copper.getName() << ":\t" << copper.getCount() << "\t\t"
		<< diamond.getName() << ":" << diamond.getCount() << std::endl
		<< tin.getName() << ":\t" << tin.getCount() << std::endl
		<< std::endl;
}