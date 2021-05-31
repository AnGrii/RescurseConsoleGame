#include "ResAutoBuy.h"





ResAutoBuy::ResAutoBuy(std::vector<std::vector<uint64_t>> dataVector)
{
	//Check size of loaded data
	uint16_t dataCountForInitLists = RESOURCES_AUTO_BUY_LIST_COUNT;

	bool vectroSizeEqualLoadedData = dataVector.size() == dataCountForInitLists;
	bool listsSizeBiggerNULL = dataVector.size() > NULL;

	//Exception
	if (not listsSizeBiggerNULL or not vectroSizeEqualLoadedData) {
		throw std::exception("wrong init lists data count!");
	}

	//Exception
	uint16_t dataCountForInitData = RESOURCES_AUTO_BUY_DATA_COUNT;

	if (dataVector[0].size() != dataCountForInitData) {
		throw std::exception("wrong init lists data count!");
	}

	levelVc.swap(dataVector[0]);
	countVc.swap(dataVector[1]);
}


	


std::vector<std::vector<uint64_t>> ResAutoBuy::UploadData()
{
	std::vector<std::vector<uint64_t>> dataVector;

	dataVector.reserve(RESOURCES_AUTO_BUY_LIST_COUNT);

	dataVector.push_back(levelVc);
	dataVector.push_back(countVc);

	return dataVector;
}
