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

	// Count - Level - Values
	countVc.swap(dataVector[0]);
	levelVc.swap(dataVector[1]);
	ResValueVc.swap(dataVector[2]);
}


std::vector<std::vector<uint64_t>> ResAutoBuy::UploadData()
{
	std::vector<std::vector<uint64_t>> dataVector;

	dataVector.reserve(RESOURCES_AUTO_BUY_LIST_COUNT);

	// Count - Level - Values
	dataVector.push_back(countVc);
	dataVector.push_back(levelVc);
	dataVector.push_back(ResValueVc);

	return dataVector;
}


void ResAutoBuy::countMenu(ResourceManager resManager)
{
	//Information
	std::cout << "========== AUTO BUY COUNT SETTINGS ==========" << std::endl << std::endl;
	
	for (size_t i = 0; i < RESOURCES_AUTO_BUY_DATA_COUNT; i++)
	{
		//Forestry - Count: 15200

		std::cout << resManager.ReosourcesVector[i]->getName() << " - "
			<< "Count: " << countVc[i] << std::endl;
	}

	//Changing status

	std::cout << "^^^^^^^^^^ AUTO BUY COUNT SETTINGS ^^^^^^^^^^" << std::endl << std::endl;
}

void ResAutoBuy::levelMenu(ResourceManager resManager)
{
	//Information
	std::cout << "========== AUTO BUY LEVEL SETTINGS ==========" << std::endl << std::endl;

	for (size_t i = 0; i < RESOURCES_AUTO_BUY_DATA_COUNT; i++)
	{
		//Forestry - Count: 50000

		std::cout << resManager.ReosourcesVector[i]->getName() << " - "
			<< "Level: " << levelVc[i] << std::endl;
	}

	//Changing status

	std::cout << "^^^^^^^^^^ AUTO BUY LEVEL SETTINGS ^^^^^^^^^^" << std::endl << std::endl;
}

void ResAutoBuy::countBuy(Player& player, ResourceManager& resManager)
{
	for (size_t resID = 0; resID < RESOURCES_AUTO_BUY_DATA_COUNT; resID++)
	{
		uint64_t transferValue = countVc[resID] * ResValueVc[resID];

		if (transferValue <= player.getBalance()) {
			player.tryPay(transferValue);
			resManager.ReosourcesVector[resID]->add(countVc[resID]);
		}
		else {
			// Not enough money message isn't important
			// Auto buy will be cout<< it every cycle
		}
	}
}


void ResAutoBuy::levelBuy(Player& player, ResourceManager& resManager)
{
	for (size_t resID = 0; resID < RESOURCES_AUTO_BUY_DATA_COUNT; resID++)
	{
		uint64_t count = 0;
		bool buyResource = false;


		if (levelVc[resID] > resManager.ReosourcesVector[resID]->getCount()) {
			count = levelVc[resID] - \
				resManager.ReosourcesVector[resID]->getCount();

			buyResource = true;
		}
		else {
			buyResource = false;
		}
		

		if (buyResource == true) {
			uint64_t transferValue = count * ResValueVc[resID];

			if (transferValue <= player.getBalance()) {
				player.tryPay(transferValue);
				resManager.ReosourcesVector[resID]->add(countVc[resID]);
			}
			else {
				// Not enough money message isn't important
				// Auto buy will be cout<< it every cycle
			}
		}
	}
}



