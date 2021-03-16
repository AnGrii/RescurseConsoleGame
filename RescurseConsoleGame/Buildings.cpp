#include "Buildings.h"

void BuildTemplate::Reinitialisate(std::vector<uint64_t> buildingData, std::string name)
{
	count = buildingData[0];
	productivity = buildingData[1];
	inQueue = buildingData[2];
	moneyNeeded = buildingData[3];
	valueOfSkipTime = buildingData[4];
	buildTime = buildingData[5];
	endBuildTime = buildingData[6];
	resource1 = buildingData[7];
	resource2 = buildingData[8];
	resource3 = buildingData[9];
	activated = buildingData[10];
	this->name = name;
}

uint64_t BuildTemplate::getRes1()
{
	return resource1;
}

uint64_t BuildTemplate::getRes2()
{
	return resource2;
}

uint64_t BuildTemplate::getRes3()
{
	return resource3;
}

void BuildTemplate::addCount(uint64_t addCount)
{
	uint64_t limit = UINT64_MAX - this->count;

	if (limit > addCount) {
		this->count += addCount;
	}
	else {
		this->count = UINT64_MAX;
	}
}

uint64_t BuildTemplate::getCount()
{
	return count;
}

uint64_t BuildTemplate::getProductivity()
{
	return productivity;
}

bool BuildTemplate::isInQueue()
{
	if (endBuildTime == 0){
		if (inQueue == 0) {
			return false;
		}
	}

	return true;
}

bool BuildTemplate::addInQueue()
{
	if (UINT64_MAX - inQueue > 1) {
		inQueue++;
		return true;
	}
	return false;
}

void BuildTemplate::updateQueue()
{
	if (endBuildTime > 0) {	
		endBuildTime--; 
		if (endBuildTime == 0) {
			std::cout << "Building finished!" << std::endl << std::endl;
		}
	}

	if (endBuildTime == 0) {
			if (inQueue > 0) {
				std::cout << "Building started!" << std::endl;
			endBuildTime = buildTime;
			inQueue--;
			count++;
		}
	}
}

Buildings::Buildings(std::vector<std::vector<uint64_t>> buildingsData, std::vector<std::string> nameData)
{
	forestry.Reinitialisate(buildingsData[0], nameData[0]);
	sawmill.Reinitialisate(buildingsData[1], nameData[1]);
	quarry.Reinitialisate(buildingsData[2], nameData[2]);
	career.Reinitialisate(buildingsData[3], nameData[3]);
	copperMine.Reinitialisate(buildingsData[4], nameData[4]);
	tinMine.Reinitialisate(buildingsData[5], nameData[5]);
	alloyPlant.Reinitialisate(buildingsData[6], nameData[6]);
	silverCleaner.Reinitialisate(buildingsData[7], nameData[7]);
	goldMine.Reinitialisate(buildingsData[8], nameData[8]);
	platinaCleaner.Reinitialisate(buildingsData[9], nameData[9]);
	diamondFactory.Reinitialisate(buildingsData[10], nameData[10]);
}

void Buildings::buildMenu(Resource& res)
{
	std::cout << "Select build:" << std::endl;

	printBuildRequest(forestry, "1 -Forestry", "Log", "Wood", "Stone");
	printBuildRequest(sawmill, "2 - Sawmill", "Log", "Wood", "Stone");
	printBuildRequest(quarry,"3 - Quarry", "Log", "Wood", "Stone");
	printBuildRequest(career,"4 - Carrer", "Log", "Wood", "Stone");
	printBuildRequest(copperMine,"5 - Copper Mine", "Log", "Stone", "Coal");
	printBuildRequest(tinMine,"6 - Tin Mine", "Coal", "Stone", "Copper");
	printBuildRequest(alloyPlant,"7 - Alloy Plant", "Stone", "Copper", "Tin");
	printBuildRequest(silverCleaner,"8 - Silver Cleaner", "Stone", "Copper", "Bronze");
	printBuildRequest(goldMine,"9 - Gold Mine", "Copper", "Bronze", "Silver");
	printBuildRequest(platinaCleaner,"a - Platina Cleaner", "Bronze", "Silver", "Gold");
	printBuildRequest(diamondFactory,"b - Diamond Factory", "Silver", "Gold", "Platina");

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

void Buildings::work(Resource& res)
{
	res.log.add(forestry.getCount()			* forestry.getProductivity());
	res.wood.add(sawmill.getCount()			* sawmill.getProductivity());
	res.stone.add(quarry.getCount()			* quarry.getProductivity());
	res.coal.add(career.getCount()			* career.getProductivity());
	res.copper.add(copperMine.getCount()	* copperMine.getProductivity());
	res.tin.add(tinMine.getCount()			* tinMine.getProductivity());
	res.bronze.add(alloyPlant.getCount()	* alloyPlant.getProductivity());
	res.silver.add(silverCleaner.getCount() * silverCleaner.getProductivity());
	res.gold.add(goldMine.getCount()		* goldMine.getProductivity());
	res.platina.add(platinaCleaner.getCount() * platinaCleaner.getProductivity());
	res.diamond.add(diamondFactory.getCount() * diamondFactory.getProductivity());
}

void Buildings::updateBuildingsBuild()
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

void Buildings::printBuildRequest(BuildTemplate build, std::string buildName,
	std::string resourceName1,
	std::string resourceName2,
	std::string resourceName3)
{
	std::cout
		<< "========== "
		<< buildName 
		<< " ==========" 
		<< std::endl << std::endl
		<< resourceName1 << " - " << build.getRes1() << '\t'
		<< resourceName2 << " - " << build.getRes2() << '\t'
		<< resourceName3 << " - " << build.getRes3() << std::endl << std::endl;
}

void Buildings::build(BuildTemplate& build, ResTemplate& reqRes1, ResTemplate& reqRes2, ResTemplate& reqRes3)
{
	if (build.getRes1() <= reqRes1.getCount() and
		build.getRes2() <= reqRes2.getCount() and
		build.getRes3() <= reqRes3.getCount())
	{
		char select = 'y';//init with y if inQueue - false
		if (build.isInQueue()) {
			std::cout << "This type of build are in process, want to add one more to queue?" << std::endl
				<< "y - Yes, n - any key" << std::endl
				<< "Input: ";
			std::cin >> select;
			std::cout << std::endl;
		}
		else { /*Nothing to do*/ }

		if (select == 'y') {
			if (build.addInQueue()) {
				reqRes1.reduce(build.getRes1());
				reqRes2.reduce(build.getRes2());
				reqRes3.reduce(build.getRes3());
			}

			std::cout << "Adding building in queue succeed!" << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "Not enough cunt of recources!" << std::endl;
	}

}

