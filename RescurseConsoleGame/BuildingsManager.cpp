#include "BuildingsManager.h"

BuildingsManager::BuildingsManager(std::vector<std::string> nameData,
	std::vector<std::vector<uint64_t>> buildingsData)
{
	for (size_t counter = 0; counter < BUILDINGS_COUNT; counter++)
	{
		BuildingsVector[counter]->Reinitialisate \
			(buildingsData[counter], nameData[counter]);
	}
}

std::vector<std::vector<uint64_t>> BuildingsManager::UploadData()
{
	std::vector<std::vector<uint64_t>> dataVector;

	dataVector.reserve(BUILDINGS_COUNT);

	for (auto& build : BuildingsVector)
	{
		dataVector.push_back(build->UploadData());
	}

	return dataVector;
}

void BuildingsManager::buildMenu(ResourceManager& res)
{
	std::cout << "Building Menu:" << std::endl;

	printResourceRequest('1', forestry, res.log, res.wood, res.stone);
	printResourceRequest('2', sawmill,  res.log, res.wood, res.stone);
	printResourceRequest('3', quarry, res.log, res.wood, res.stone);
	printResourceRequest('4', career, res.log, res.wood, res.stone);
	printResourceRequest('5', copperMine, res.log, res.stone, res.coal);
	printResourceRequest('6', tinMine, res.coal, res.stone, res.copper);
	printResourceRequest('7', alloyPlant, res.stone, res.copper, res.tin);
	printResourceRequest('8', silverCleaner, res.stone, res.copper, res.bronze);
	printResourceRequest('9', goldMine, res.copper, res.bronze, res.silver);
	printResourceRequest('a', platinaCleaner, res.bronze, res.silver, res.gold);
	printResourceRequest('b', diamondFactory, res.silver, res.gold, res.platina);

	char select = SafetyInput::cinAndReturnChar("Input id to build: ");

	switch (select)
	{
	case '1':
		build(forestry, res.log, res.wood, res.stone);
		break;
	case '2':
		build(sawmill, res.log, res.wood, res.stone);
		break;
	case '3':
		build(quarry, res.log, res.wood, res.stone);
		break;
	case '4':
		build(career, res.log, res.wood, res.stone);
		break;
	case '5':
		build(copperMine, res.log, res.stone, res.coal);
		break;
	case '6':
		build(tinMine, res.coal, res.stone, res.copper);
		break;
	case '7':
		build(alloyPlant, res.stone, res.copper, res.tin);
		break;
	case '8':
		build(silverCleaner, res.stone, res.copper, res.bronze);
		break;
	case '9':
		build(goldMine, res.copper, res.bronze, res.silver);
		break;
	case 'a':
		build(platinaCleaner, res.bronze, res.silver, res.gold);
		break;
	case 'b':
		build(diamondFactory, res.silver, res.gold, res.platina);
		break;
	default:
		std::cout << "Wrong input!" << std::endl << std::endl;
		break;
	}
}

void BuildingsManager::work(ResourceManager& res)
{
	if (BUILDINGS_COUNT != res.RESOURCES_COUNT) {
		throw std::exception("Different counts of resources and buildings!!");
		//WARNING: Count of resources and buildings is equal,
		//if it will changed, it will cause problem
		//Change cycle counter to fix
	}

	for (size_t iterator = 0; iterator < BUILDINGS_COUNT; iterator++)
	{
		res.ReosourcesVector[iterator]->add \
			(BuildingsVector[iterator]->calcProductivity());
	}
}

void BuildingsManager::updateBuildingsQueue()
{
	for (auto& item : BuildingsVector) { item->updateQueue(); }
}

void BuildingsManager::productivitySettingMenu()
{
	const std::vector<char> charIDList
	{ 'q','w','e','r','t','y','u','i','o',
		'p','a','s','d','f','g','h','j','k',
		'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	std::cout << "========== Buildings Productivity ===========" << std::endl;

	for (size_t i = 0; i < BUILDINGS_COUNT; i++)
	{
		std::cout << charIDList[i] << " - " \
			<< BuildingsVector[i]->getPowerPercentInfo() << std::endl;
	}
	std::cout << std::endl;

	uint16_t buildingId = SafetyInput::cinAndReturnCharID("Input building id-name: ",
		charIDList, BUILDINGS_COUNT);

	uint64_t int_percent = SafetyInput::cinAndReturnUI64T("Input percent: ");

	BuildingsVector[buildingId]->setPowerPercent(int_percent);
}

void BuildingsManager::printResourceRequest(Building build, std::string buildSymb,
	std::string resourceName1,
	std::string resourceName2,
	std::string resourceName3)
{
	std::cout << buildSymb << " - " << build.getName() << std::endl
		<< resourceName1 << " - " << build.getResource1Count() << std::endl
		<< resourceName2 << " - " << build.getResource2Count() << std::endl
		<< resourceName3 << " - " << build.getResource3Count() << std::endl << std::endl;
}

void BuildingsManager::printResourceRequest(char buildSymb, Building build,
	Resource res1, Resource res2, Resource res3)
{
	std::cout << buildSymb << " - " << build.getName() << std::endl
		<< res1.getName() << " - " << build.getResource1Count() << std::endl
		<< res2.getName() << " - " << build.getResource2Count() << std::endl
		<< res3.getName() << " - " << build.getResource3Count() << std::endl << std::endl;
}

void BuildingsManager::build(Building& build,
	Resource& reqRes1,
	Resource& reqRes2,
	Resource& reqRes3)
{
	if (build.getResource1Count() <= reqRes1.getCount() and
		build.getResource2Count() <= reqRes2.getCount() and
		build.getResource3Count() <= reqRes3.getCount())
	{
		char select = '0';
		if (build.isInQueue()) {
			std::cout << "This type of build are in process, " //No need endl
				<< "want to add one more to queue?" << std::endl
				<< "y - Yes, n - any key" << std::endl;		

			select = SafetyInput::cinAndReturnChar("Input: ");
		}

		if (select == 'y') {
			if (build.addInQueue()) {
				reqRes1.reduce(build.getResource1Count());
				reqRes2.reduce(build.getResource2Count());
				reqRes3.reduce(build.getResource3Count());

				build.increaseResRequest1();
				build.increaseResRequest2();
				build.increaseResRequest3();
			}
			std::cout << "Adding building in queue succeed!" << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "Not enough count of recources!" << std::endl << std::endl;
	}
}

void BuildingsManager::printQueueStatus()
{
	for (auto& item : BuildingsVector)
	{
		std::string info = item->getQueueInfo();

		if (info != "-") {
			std::cout << info << std::endl << std::endl;
		}
	}
}

void BuildingsManager::brokeEvent()
{
	srand(static_cast<uint64_t>(NULL));

	//CHANCE: 1 : (100k - 2)
	uint16_t chance = rand() % 100 * rand() % 1000;

	if (chance < BUILDINGS_COUNT - 1) {
		BuildingsVector[chance]->brokeBuild();
	}
}

void BuildingsManager::printBuildingsInfo()
{
	for (auto& item : BuildingsVector) { item->buildInfo(); }
}

void BuildingsManager::skipBuildingMenu(Player &p)
{
	const std::vector<char> charIDList
	{ 'q','w','e','r','t','y','u','i','o',
		'p','a','s','d','f','g','h','j','k',
		'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	std::cout << "=====\tValue of skip time of building\t=====" << std::endl;

	bool buildingAreInQueue = false;
	for (size_t i = 0; i < BUILDINGS_COUNT; i++)
	{
		std::string info = BuildingsVector[i]->getSkipInfo();

		if (info != "-") {
			std::cout << charIDList[i] << ' ' << info << std::endl;
			buildingAreInQueue = true;
		}
	}
	
	if (buildingAreInQueue) {
		uint16_t buildingId = SafetyInput::cinAndReturnCharID("Input skip build id: ",
			charIDList, BUILDINGS_COUNT);

		BuildingsVector[buildingId]->skipBuildingProcess \
			(p.tryPay(BuildingsVector[buildingId]->getSkipValue()));
	}
	else {
		std::cout << "Queue of buildings is empty!" << std::endl << std::endl;
	}
}

void BuildingsManager::upgradeMenu(Player& p)
{
	const std::vector<char> charIDList
	{ 'q','w','e','r','t','y','u','i','o',
		'p','a','s','d','f','g','h','j','k',
		'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	std::cout << "========== Buildings Upgrade ===========" << std::endl;

	for (size_t i = 0; i < BUILDINGS_COUNT; i++)
	{
		std::cout << charIDList[i] << " - " \
			<< BuildingsVector[i]->getUpgradeBuildInfo() << std::endl;
	}

	uint16_t buildingId = SafetyInput::cinAndReturnCharID("Input building id-name: ",
		charIDList, BUILDINGS_COUNT);

	BuildingsVector[buildingId]->increaseProductivityOutput \
		( p.tryPay( BuildingsVector[buildingId]->getUpgradeValue()));
}

