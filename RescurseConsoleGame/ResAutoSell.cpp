#include "ResAutoSell.h"




ResAutoSell::ResAutoSell(std::vector<std::vector<uint64_t>> dataVector)
{
	//Check size of loaded data
	uint16_t dataCountForInitLists = RESOURCES_AUTO_BUY_LIST_COUNT; 

	bool vectroSizeEqualLoadedData = dataVector.size() == dataCountForInitLists;
	bool listsSizeBiggerNULL = dataVector.size() > NULL;

	if (not listsSizeBiggerNULL or not vectroSizeEqualLoadedData) {
		throw std::exception("wrong init lists data count!");
	}

	uint16_t dataCountForInitData = RESOURCES_AUTO_BUY_DATA_COUNT;

	if (dataVector[0].size() != dataCountForInitData) {
		throw std::exception("wrong init lists data count!");
	}

	percentVc.swap(dataVector[0]);
	countVc.swap(dataVector[1]);
}

std::vector<std::vector<uint64_t>> ResAutoSell::UploadData()
{
	std::vector<std::vector<uint64_t>> dataVector;

	dataVector.reserve(RESOURCES_AUTO_BUY_LIST_COUNT);

	dataVector.push_back(percentVc);
	dataVector.push_back(countVc);

	return dataVector;
}
