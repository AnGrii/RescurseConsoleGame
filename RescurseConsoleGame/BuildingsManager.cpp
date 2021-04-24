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

	char select;
	std::cout << "Input to build: ";
	std::cin >> select;
	std::cout << std::endl;

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
		throw std::exception("Different counts!");
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
			<< BuildingsVector[i]->getProductivityInfo() << std::endl;
	}
	std::cout << std::endl;

	uint16_t buildingId = SafetyInput::cinAndGetIDfromChar("Input building id-name: ",
		charIDList, BUILDINGS_COUNT);

	uint64_t int_percent = SafetyInput::cinAndGetNumFromInput("Input percent: ");

	BuildingsVector[buildingId]->setProductivity(int_percent);
}

void BuildingsManager::printResourceRequest(Building build, std::string buildSymb,
	std::string resourceName1,
	std::string resourceName2,
	std::string resourceName3)
{
	std::cout << buildSymb << " - " << build.getName() << std::endl
		<< resourceName1 << " - " << build.getRes1() << std::endl
		<< resourceName2 << " - " << build.getRes2() << std::endl
		<< resourceName3 << " - " << build.getRes3() << std::endl << std::endl;
}

void BuildingsManager::printResourceRequest(char buildSymb, Building build,
	Resource res1, Resource res2, Resource res3)
{
	std::cout << buildSymb << " - " << build.getName() << std::endl
		<< res1.getName() << " - " << build.getRes1() << std::endl
		<< res2.getName() << " - " << build.getRes2() << std::endl
		<< res3.getName() << " - " << build.getRes3() << std::endl << std::endl;
}

void BuildingsManager::build(Building& build,
	Resource& reqRes1,
	Resource& reqRes2,
	Resource& reqRes3)
{
	if (build.getRes1() <= reqRes1.getCount() and
		build.getRes2() <= reqRes2.getCount() and
		build.getRes3() <= reqRes3.getCount())
	{
		char select = 'y';

		if (build.isInQueue()) {
			std::cout << "This type of build are in process, want to add one more to queue?" << std::endl
				<< "y - Yes, n - any key" << std::endl
				<< "Input: ";
			std::cin >> select;
			std::cout << std::endl;
		}

		if (select == 'y') {
			if (build.addInQueue()) {
				reqRes1.reduce(build.getRes1());
				reqRes2.reduce(build.getRes2());
				reqRes3.reduce(build.getRes3());

				build.increaseResValue1();
				build.increaseResValue2();
				build.increaseResValue3();
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
	for (auto& item : BuildingsVector)
	{
		item->buildInfo();
	}
}

void BuildingsManager::SkipBuildingMenu(Player &p)
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
		uint16_t buildingId = SafetyInput::cinAndGetIDfromChar("Input skip build id: ",
			charIDList, BUILDINGS_COUNT);

		BuildingsVector[buildingId]->skipBuildingProcess \
			(p.payAndGetStatus(BuildingsVector[buildingId]->getSkipValue()));
	}
	else {
		std::cout << "Queue of buildings is empty!" << std::endl << std::endl;
	}
}

void BuildingsManager::upgradeMenu(Player& p)
{
	const char nameIdLIst[11]{ '1','2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b' };

	std::cout << "========== Buildings Upgrade ===========" << std::endl;

	for (size_t i = 0; i < BUILDINGS_COUNT; i++)
	{
		std::cout << nameIdLIst[i] << " - " \
			<< BuildingsVector[i]->getUpgradeBuildInfo() << std::endl;
	}

	char select = '0';
	std::cout << "Input building id-name: ";
	std::cin >> select;
	std::cout << std::endl;

	uint16_t buildingId = 0;
	for (size_t i = 0; i < 11; i++)
	{
		if (nameIdLIst[i] == select) {
			buildingId = uint16_t(i);
			break;
		}
	}

	BuildingsVector[buildingId]->increaseProductivity \
		(p.payAndGetStatus(BuildingsVector[buildingId]->getUpgradeValue()));
}

