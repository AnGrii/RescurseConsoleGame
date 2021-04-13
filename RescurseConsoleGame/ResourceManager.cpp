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
		<< log.getNameAndCountInfo() << "\t\t"
		<< bronze.getNameAndCountInfo() << std::endl
		<< wood.getNameAndCountInfo() << "\t\t"
		<< silver.getNameAndCountInfo() << std::endl
		<< stone.getNameAndCountInfo() << "\t\t"
		<< gold.getNameAndCountInfo() << std::endl
		<< coal.getNameAndCountInfo() << "\t\t"
		<< platina.getNameAndCountInfo() << std::endl
		<< copper.getNameAndCountInfo() << "\t\t"
		<< diamond.getNameAndCountInfo() << std::endl
		<< tin.getNameAndCountInfo() << std::endl
		<< std::endl;
}