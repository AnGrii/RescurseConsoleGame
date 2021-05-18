#include "Market.h"

Market::Market(std::vector<uint64_t> dataList)
{
	uint16_t dataCountForInit = 1 + (BUILDINGS_COUNT * 2);

	if (dataList.size() != dataCountForInit) {
		throw std::exception("Wrong init data count!");
	}

	resourcesValueVc.reserve(BUILDINGS_COUNT);
	resourcesAutoSellPercentVc.reserve(BUILDINGS_COUNT);

	size_t counter = 0;

	sellCoeficient = (dataList[counter] / 100.0);

	for (counter = 1; counter < dataList.size(); counter++)
	{
		if (counter % 2 == 1) {
			resourcesValueVc.push_back(dataList[counter]);
		}
		else {
			resourcesAutoSellPercentVc.push_back(dataList[counter]);
		}
	}
}

std::vector<uint64_t> Market::UploadData()
{
	std::vector<uint64_t> dataList;

	uint16_t dataCountForInit = 1 + (BUILDINGS_COUNT * 2);

	dataList.reserve(dataCountForInit);

	dataList.push_back(uint64_t(sellCoeficient * 100));

	for (size_t item = 0; item < BUILDINGS_COUNT; item++)
	{
		dataList.push_back(resourcesValueVc[item]);
		dataList.push_back(resourcesAutoSellPercentVc[item]);
	}

	return dataList;
}

void Market::Menu(Player& p, ResourceManager& rm)
{
	const std::vector<char> charIDList
	{ 'q','w','e','r','t','y','u','i','o',
		'p','a','s','d','f','g','h','j','k',
		'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	showProductInfo(rm, charIDList);	

	uint16_t resourceID = SafetyInput::cinAndReturnCharID("Input resources letter: ",
		charIDList, BUILDINGS_COUNT);
	
	char transferAction = SafetyInput::cinAndReturnChar("Input transfer action \n\
b - Buy\n\
s - Sell\n\
Input: ");

	uint64_t transferCount = SafetyInput::cinAndReturnUI64T("Input count of resource: ");

	if (transferAction == 'b') {
		buyResource(p, rm.ReosourcesVector[resourceID], resourceID, transferCount);
	}
	else if (transferAction == 's') {
		sellResource(p, rm.ReosourcesVector[resourceID], resourceID, transferCount);
	}
	else { /*Nothing*/ }
}

void Market::showProductInfo(ResourceManager rm, const std::vector<char> charIDList)
{
	for (size_t count = 0; count < rm.RESOURCES_COUNT; count++)
	{
		std::cout << charIDList[count] << " - "
			<< rm.ReosourcesVector[count]->getName();

		if (rm.ReosourcesVector[count]->getName().size() < 4) {
			std::cout << "\t\t\t";
		}
		else if (rm.ReosourcesVector[count]->getName().size() < 8) {
			std::cout << "\t\t";
		}
		else {
			std::cout << "\t";
		}

		std::cout << rm.ReosourcesVector[count]->getCount() << "\t"
			<< "Value: " << resourcesValueVc[count] << "\t"
			<< "Sell Value: "
			<< uint64_t(resourcesValueVc[count] * sellCoeficient)
			<< std::endl;
	}
}

void Market::buyResource(Player& p, Resource* res, uint16_t resourceID, uint64_t count)
{
	uint64_t transferValue = count * resourcesValueVc[resourceID];

	if (transferValue <= p.getBalance()) {
		res->add(count);
		p.reduceBalance(transferValue);
	}
	else {
		std::cout << "Not enough money!!!" << std::endl;
	}
}

void Market::sellResource(Player& p, Resource* res, uint16_t resourceID, uint64_t count)
{
	uint64_t transferValue = 
		uint64_t(count * resourcesValueVc[resourceID] * sellCoeficient);

	if (count <= res->getCount()) {
		res->reduce(count);
		p.addBalance(transferValue);
	}
	else {
		std::cout << "Not enough count of resource!!!" << std::endl;
	}
}

