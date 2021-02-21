#include "Resource.h"

uint64_t ResTmp::getCount()
{
	return count;
}
void ResTmp::add(uint64_t count)
{
	uint64_t limit = UINT64_MAX - this->count;

	if (limit > count) {
		this->count += count;
	}
	else {
		this->count = UINT64_MAX;
	}
}
void ResTmp::reduce(uint64_t count)
{
	if (this->count > count) {
		this->count -= count;
	}
	else {
		this->count = 0;
	}
}
void ResTmp::set(uint64_t count)
{
	this->count = count;
}


Resource::Resource()
{
	log.Reinitialisate(0);
	wood.Reinitialisate(0);
	stone.Reinitialisate(0);
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
