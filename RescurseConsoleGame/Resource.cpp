#include "Resource.h"

ResTemplate::ResTemplate()
{
	count = 0; 
	value = 0;
}
void ResTemplate::Reinitialisate(uint64_t count, uint64_t value)
{
	this->count = count;
	this->value = value;
}


uint64_t ResTemplate::getCount()
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


Resource::Resource()
{
	//Standart ResTmp constructor has initialisating in declaration
}
Resource::Resource(std::vector<uint64_t> dataList)
{
	log.Reinitialisate(dataList[0], dataList[1]);
	wood.Reinitialisate(dataList[2], dataList[3]);
	stone.Reinitialisate(dataList[4], dataList[5]);
}
void Resource::SaveData(std::vector<uint64_t>& dataList)
{
	dataList[0] = log.getCount();
	dataList[1] = log.getValue();
	dataList[2] = wood.getCount();
	dataList[3] = wood.getValue();
	dataList[4] = stone.getCount();
	dataList[5] = stone.getValue();
}

void Resource::printResourcesCount()
{
	std::cout
		<< "Log:\t" << log.getCount() << std::endl
		<< "Wood:\t" << wood.getCount() << std::endl
		<< "Stone:\t" << stone.getCount() << std::endl << std::endl;
}
