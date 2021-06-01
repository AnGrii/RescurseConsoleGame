#include "ResAutoSell.h"




ResAutoSell::ResAutoSell(std::vector<std::vector<uint64_t>> dataVector)
{
	//Check size of loaded data
	uint16_t dataCountForInitLists = RESOURCES_AUTO_SELL_LIST_COUNT; 

	bool vectroSizeEqualLoadedData = dataVector.size() == dataCountForInitLists;
	bool listsSizeBiggerNULL = dataVector.size() > NULL;

	//Exception
	if (not listsSizeBiggerNULL or not vectroSizeEqualLoadedData) {
		throw std::exception("Wrong init lists data count!");
	}

	uint16_t dataCountForInitData = RESOURCES_AUTO_SELL_DATA_COUNT;

	//Exception
	if (dataVector[0].size() != dataCountForInitData) {
		throw std::exception("wrong init lists data count!");
	}

	// Count - Percent - Values
	countVc.swap(dataVector[0]);
	percentVc.swap(dataVector[1]);
	ResValueVc.swap(dataVector[2]);
}

std::vector<std::vector<uint64_t>> ResAutoSell::UploadData()
{
	std::vector<std::vector<uint64_t>> dataVector;

	dataVector.reserve(RESOURCES_AUTO_SELL_LIST_COUNT);

	// Count - Percent - Values
	dataVector.push_back(countVc);
	dataVector.push_back(percentVc);
	dataVector.push_back(ResValueVc);

	return dataVector;
}


void ResAutoSell::Menu(ResourceManager resManager)
{
	std::cout
		<< "c - Count Menu" << std::endl
		<< "p - Percent Menu" << std::endl;

	char select = SafetyInput::cinAndReturnChar("Input: ");

	if (select == 'c') {
		countMenu(resManager);
	}
	else if (select == 'p') {
		percentMenu(resManager);
	}
}


void ResAutoSell::countMenu(ResourceManager resManager)
{
	const std::vector<char> charIDList
	{ 'q','w','e','r','t','y','u','i','o',
		'p','a','s','d','f','g','h','j','k',
		'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	//Information
	std::cout << "========== AUTO SELL COUNT SETTINGS ==========" << std::endl << std::endl;

	for (size_t i = 0; i < RESOURCES_AUTO_SELL_DATA_COUNT; i++)
	{
		//Forestry - Count: 15200

		std::cout << charIDList[i] << " - "
			<< resManager.ReosourcesVector[i]->getName() << " - "
			<< "Count: " << countVc[i] << std::endl;
	}

	uint16_t resID = \
		SafetyInput::cinAndReturnCharID("Input letter to change Auto Sell Count: ",
			charIDList, RESOURCES_AUTO_SELL_DATA_COUNT);

	uint64_t newCount = SafetyInput::cinAndReturnUI64T("Input new Count: ");

	countVc[resID] = newCount;

	std::cout << "^^^^^^^^^^ AUTO SELL COUNT SETTINGS ^^^^^^^^^^" << std::endl << std::endl;
}

void ResAutoSell::percentMenu(ResourceManager resManager)
{
	const std::vector<char> charIDList
	{ 'q','w','e','r','t','y','u','i','o',
		'p','a','s','d','f','g','h','j','k',
		'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	//Information
	std::cout << "========== AUTO SELL PERCENT SETTINGS ==========" << std::endl << std::endl;

	for (size_t i = 0; i < RESOURCES_AUTO_SELL_DATA_COUNT; i++)
	{
		//Forestry - Count: 15200

		std::cout << charIDList[i] << " - "
			<< resManager.ReosourcesVector[i]->getName() << " - "
			<< "Percent: " << percentVc[i] << std::endl;
	}

	uint16_t resID = \
		SafetyInput::cinAndReturnCharID("Input letter to change Auto Sell Percent: ",
			charIDList, RESOURCES_AUTO_SELL_DATA_COUNT);

	uint64_t newPercent = SafetyInput::cinAndReturnUI64T("Input new Percent (0 - 100): ");

	if (newPercent > 100) { newPercent = 100; }

	percentVc[resID] = newPercent;

	std::cout << "^^^^^^^^^^ AUTO SELL PERCENT SETTINGS ^^^^^^^^^^" << std::endl << std::endl;
}


void ResAutoSell::countSell(Player& player, ResourceManager& resManager)
{
	for (size_t resID = 0; resID < RESOURCES_AUTO_SELL_DATA_COUNT; resID++)
	{
		uint64_t transferValue = countVc[resID] * ResValueVc[resID];

		uint64_t aviableResource = resManager.ReosourcesVector[resID]->getCount();

		if (countVc[resID] >= aviableResource) {
			player.addBalance(transferValue);
			resManager.ReosourcesVector[resID]->reduce(countVc[resID]);
		}
		else {
			// Not enough money message isn't important
			// Auto buy will be cout<< it every cycle
		}
	}
}

void ResAutoSell::percentSell(Player& player, ResourceManager& resManager)
{
	for (size_t resID = 0; resID < RESOURCES_AUTO_SELL_DATA_COUNT; resID++)
	{
		uint64_t aviableResource = resManager.ReosourcesVector[resID]->getCount();


		uint64_t sellCount = aviableResource * percentVc[resID];

		uint64_t transferValue = sellCount * ResValueVc[resID];

		if (countVc[resID] >= sellCount) {
			player.addBalance(transferValue);
			resManager.ReosourcesVector[resID]->reduce(countVc[resID]);
		}
		else {
			// Not enough money message isn't important
			// Auto buy will be cout<< it every cycle
		}
	}
}