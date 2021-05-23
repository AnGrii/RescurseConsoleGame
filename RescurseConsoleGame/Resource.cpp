#include "Resource.h"


void Resource::Reinitialisate(std::string name,
	std::vector<uint64_t> dataList)
{
	uint16_t dataCountForInit = RESOURCES_DATA_COUNT;

	if (dataList.size() != dataCountForInit) {
		throw std::exception("Wrong init data count!");
	}

	uint16_t counter = 0;

	this->name = name;
	this->count = dataList[counter]; counter++;
}

std::vector<uint64_t> Resource::UploadData()
{
	std::vector<uint64_t> dataVector;

	dataVector.resize(RESOURCES_DATA_COUNT);

	uint16_t counter = 0;
	dataVector[counter] = this->count; counter++;

	return dataVector;
}

uint64_t Resource::getCount()
{
	return count;
}

void Resource::add(uint64_t count)
{
	uint64_t limit = UINT64_MAX - this->count;

	if (limit > count) {
		this->count += count;
	}
	else {
		this->count = UINT64_MAX;
	}
}
void Resource::reduce(uint64_t count)
{
	if (this->count > count) {
		this->count -= count;
	}
	else {
		this->count = 0;
	}
}
void Resource::set(uint64_t count)
{
	this->count = count;
}

std::string Resource::getName()
{
	return name;
}

std::string Resource::getNameAndCountInfo()
{
	std::string info;

	info = info + this->name;
	info = info + ": ";
	info = info + std::to_string(this->getCount());

	return info;
}