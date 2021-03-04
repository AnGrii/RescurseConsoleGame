#include "Resource.h"


void ResTemplate::Reinitialisate(std::vector<uint64_t> dataList)
{
	this->count = dataList[0];
	this->value = dataList[1];
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
	log.Reinitialisate(dataList[0]);
	wood.Reinitialisate(dataList[1]);
	stone.Reinitialisate(dataList[2]);
}

void Resource::printResourcesCount()
{
	std::cout
		<< "Log:\t" << log.getCount() << std::endl
		<< "Wood:\t" << wood.getCount() << std::endl
		<< "Stone:\t" << stone.getCount() << std::endl << std::endl;
}
