#include "Resource.h"


void ResTemplate::Reinitialisate(std::vector<uint64_t> dataList)
{
	uint16_t counter = 0;

	this->count = dataList[counter++];
	this->value = dataList[counter++];
}

uint64_t ResTemplate::getCount()
{
	return count;
}
uint64_t& ResTemplate::getCountLink()
{
	return count;
}
void ResTemplate::add(uint64_t count)
{
	uint64_t limit = UINT64_MAX - this->count;

	if (limit > count) {
		this->count += count;
	}
	else {
		this->count = UINT64_MAX;
	}
}
void ResTemplate::reduce(uint64_t count)
{
	if (this->count > count) {
		this->count -= count;
	}
	else {
		this->count = 0;
	}
}
void ResTemplate::set(uint64_t count)
{
	this->count = count;
}

uint64_t ResTemplate::getValue()
{
	return value;
}

Resource::Resource(std::vector< std::vector<uint64_t>> dataList)
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

void Resource::printResourcesCount()
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