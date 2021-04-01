#include "BuildingsManager.h"

BuildingsManager::BuildingsManager(std::vector<std::string> nameData,
	std::vector<std::vector<uint64_t>> buildingsData)
{
	uint16_t bCounter = 0;

	forestry.Reinitialisate(buildingsData[bCounter], nameData[bCounter]);
	sawmill.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	quarry.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	career.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	copperMine.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	tinMine.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	alloyPlant.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	silverCleaner.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	goldMine.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	platinaCleaner.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
	diamondFactory.Reinitialisate(buildingsData[++bCounter], nameData[bCounter]);
}

void BuildingsManager::buildMenu(ResourceManager& res)
{
	std::cout << "Select build:" << std::endl;

	printBuildRequest(forestry, "1", "Log", "Wood", "Stone");
	printBuildRequest(sawmill, "2", "Log", "Wood", "Stone");
	printBuildRequest(quarry, "3", "Log", "Wood", "Stone");
	printBuildRequest(career, "4", "Log", "Wood", "Stone");
	printBuildRequest(copperMine, "5", "Log", "Stone", "Coal");
	printBuildRequest(tinMine, "6", "Coal", "Stone", "Copper");
	printBuildRequest(alloyPlant, "7", "Stone", "Copper", "Tin");
	printBuildRequest(silverCleaner, "8", "Stone", "Copper", "Bronze");
	printBuildRequest(goldMine, "9", "Copper", "Bronze", "Silver");
	printBuildRequest(platinaCleaner, "a", "Bronze", "Silver", "Gold");
	printBuildRequest(diamondFactory, "b", "Silver", "Gold", "Platina");

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
	res.log.add(forestry.getCount() * forestry.getProductivity());
	res.wood.add(sawmill.getCount() * sawmill.getProductivity());
	res.stone.add(quarry.getCount() * quarry.getProductivity());
	res.coal.add(career.getCount() * career.getProductivity());
	res.copper.add(copperMine.getCount() * copperMine.getProductivity());
	res.tin.add(tinMine.getCount() * tinMine.getProductivity());
	res.bronze.add(alloyPlant.getCount() * alloyPlant.getProductivity());
	res.silver.add(silverCleaner.getCount() * silverCleaner.getProductivity());
	res.gold.add(goldMine.getCount() * goldMine.getProductivity());
	res.platina.add(platinaCleaner.getCount() * platinaCleaner.getProductivity());
	res.diamond.add(diamondFactory.getCount() * diamondFactory.getProductivity());
}

void BuildingsManager::updateBuildingsQueue()
{
	forestry.updateQueue();
	sawmill.updateQueue();
	quarry.updateQueue();
	career.updateQueue();
	copperMine.updateQueue();
	tinMine.updateQueue();
	alloyPlant.updateQueue();
	silverCleaner.updateQueue();
	goldMine.updateQueue();
	platinaCleaner.updateQueue();
	diamondFactory.updateQueue();
}

void BuildingsManager::printBuildRequest(Building build, std::string buildSymb,
	std::string resourceName1,
	std::string resourceName2,
	std::string resourceName3)
{
	std::cout
		<< "========== "
		<< buildSymb << " - " << build.getName()
		<< " =========="
		<< std::endl << std::endl
		<< resourceName1 << " - " << build.getRes1() << '\t'
		<< resourceName2 << " - " << build.getRes2() << '\t'
		<< resourceName3 << " - " << build.getRes3() << std::endl << std::endl;
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

void Building::buildInfo()
{
	std::cout << "=========   " << this->getName() << "   =========" << std::endl
		<< "Count:\t\t\t" << this->getCount() << std::endl
		<< "Productivity:\t\t" << this->getProductivity() << std::endl
		<< "Skip build time value:\t" << this->getSkipValue() << std::endl
		<< "Build time:\t\t" << this->getBuildTime() << std::endl
		<< "Resource1 needed:\t" << this->getRes1() << std::endl
		<< "Resource2 needed:\t" << this->getRes2() << std::endl
		<< "Resource3 needed:\t" << this->getRes3() << std::endl
		<< "Activated:\t\t" << this->getActiveStatus() << std::endl << std::endl;
}

void BuildingsManager::printQueueStatus()
{
	forestry.printQueueInfo();
	sawmill.printQueueInfo();
	quarry.printQueueInfo();
	career.printQueueInfo();
	copperMine.printQueueInfo();
	tinMine.printQueueInfo();
	alloyPlant.printQueueInfo();
	silverCleaner.printQueueInfo();
	goldMine.printQueueInfo();
	platinaCleaner.printQueueInfo();
	diamondFactory.printQueueInfo();
}

void BuildingsManager::brokeEvent()
{
	srand(static_cast<uint64_t>(NULL));

	uint16_t chance = rand() % 100 * rand() % 1000;

	switch (chance)
	{
	case 1:
		forestry.brokeBuild();
		break;
	case 2:
		sawmill.brokeBuild();
		break;
	case 3:
		quarry.brokeBuild();
		break;
	case 4:
		career.brokeBuild();
		break;
	case 5:
		copperMine.brokeBuild();
		break;
	case 6:
		tinMine.brokeBuild();
		break;
	case 7:
		alloyPlant.brokeBuild();
		break;
	case 8:
		silverCleaner.brokeBuild();
		break;
	case 9:
		goldMine.brokeBuild();
		break;
	case 10:
		platinaCleaner.brokeBuild();
		break;
	case 11:
		diamondFactory.brokeBuild();
		break;
	default:
		break;
	}

}

void BuildingsManager::printBuildingsInfo()
{
	forestry.buildInfo();
	sawmill.buildInfo();
	quarry.buildInfo();
	career.buildInfo();
	copperMine.buildInfo();
	tinMine.buildInfo();
	alloyPlant.buildInfo();
	silverCleaner.buildInfo();
	goldMine.buildInfo();
	platinaCleaner.buildInfo();
	diamondFactory.buildInfo();
}

void BuildingsManager::SkipBuildingMenu(Player &p)
{
	std::cout << "=====\tValue of skip time of building\t=====" << std::endl;
	forestry.printSkipInfo('1');
	sawmill.printSkipInfo('2');
	quarry.printSkipInfo('3');
	career.printSkipInfo('4');
	copperMine.printSkipInfo('5');
	tinMine.printSkipInfo('6');
	alloyPlant.printSkipInfo('7');
	silverCleaner.printSkipInfo('8');
	goldMine.printSkipInfo('9');
	platinaCleaner.printSkipInfo('a');
	diamondFactory.printSkipInfo('b');

	char select;
	std::cout << "Input skip build id: ";
	std::cin >> select;
	std::cout << std::endl;

	switch (select)
	{
	case '1':
		forestry.skipBuildingProcess(p.payAndGetStatus(forestry.getSkipValue()));
		break;
	case '2':
		sawmill.skipBuildingProcess(p.payAndGetStatus(sawmill.getSkipValue()));
		break;
	case '3':
		quarry.skipBuildingProcess(p.payAndGetStatus(quarry.getSkipValue()));
		break;
	case '4':
		career.skipBuildingProcess(p.payAndGetStatus(career.getSkipValue()));
		break;
	case '5':
		copperMine.skipBuildingProcess(p.payAndGetStatus(copperMine.getSkipValue()));
		break;
	case '6':
		tinMine.skipBuildingProcess(p.payAndGetStatus(tinMine.getSkipValue()));
		break;
	case '7':
		alloyPlant.skipBuildingProcess(p.payAndGetStatus(alloyPlant.getSkipValue()));
		break;
	case '8':
		silverCleaner.skipBuildingProcess(p.payAndGetStatus(silverCleaner.getSkipValue()));
		break;
	case '9':
		goldMine.skipBuildingProcess(p.payAndGetStatus(goldMine.getSkipValue()));
		break;
	case 'a':
		platinaCleaner.skipBuildingProcess(p.payAndGetStatus(platinaCleaner.getSkipValue()));
		break;
	case 'b':
		diamondFactory.skipBuildingProcess(p.payAndGetStatus(diamondFactory.getSkipValue()));
		break;
	default:
		std::cout << "Wrong input!" << std::endl << std::endl;
		break;
	}

}