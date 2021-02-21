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
	log.Reinitialisate(dataList[0]);
	wood.Reinitialisate(dataList[1]);
	stone.Reinitialisate(dataList[2]);
}
void Resource::SaveData(std::vector<uint64_t>& dataList)
{
	dataList[0] = log.getCount();
	dataList[1] = wood.getCount();
	dataList[2] = stone.getCount();
}
