#include "Buildings.h"

void BuildTemplate::Reinitialisate(std::vector<uint64_t> buildingData, std::string name)
{
	uint16_t counter = 0;

	count =			buildingData[counter];
	productivity =	buildingData[++counter];
	inQueue =		buildingData[++counter];
	valueOfSkipTime = buildingData[++counter];
	buildTime =		buildingData[++counter];
	endBuildTime =	buildingData[++counter];
	resource1 =		buildingData[++counter];
	resource2 =		buildingData[++counter];
	resource3 =		buildingData[++counter];
	activated =		buildingData[++counter];
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
				std::cout << "Building started!" << std::endl << std::endl;
			endBuildTime = buildTime;
			inQueue--;
			count++;
		}
	}
}

void BuildTemplate::printQueueInfo()
{
	if (this->isInQueue()) {
		std::cout << "Count of " << name << " in queue -\t" << inQueue << std::endl
			<< "Days to building left -\t" << endBuildTime << std::endl << std::endl;
	}
}


Buildings::Buildings(std::vector<std::string> nameData,
	std::vector<std::vector<uint64_t>> buildingsData)
{
	uint16_t bCounter = 0;

	forestry.Reinitialisate(		buildingsData[bCounter],	nameData[bCounter]);
	sawmill.Reinitialisate(			buildingsData[++bCounter],	nameData[bCounter]);
	quarry.Reinitialisate(			buildingsData[++bCounter],	nameData[bCounter]);
	career.Reinitialisate(			buildingsData[++bCounter],	nameData[bCounter]);
	copperMine.Reinitialisate(		buildingsData[++bCounter],	nameData[bCounter]);
	tinMine.Reinitialisate(			buildingsData[++bCounter],	nameData[bCounter]);
	alloyPlant.Reinitialisate(		buildingsData[++bCounter],	nameData[bCounter]);
	silverCleaner.Reinitialisate(	buildingsData[++bCounter],	nameData[bCounter]);
	goldMine.Reinitialisate(		buildingsData[++bCounter],	nameData[bCounter]);
	platinaCleaner.Reinitialisate(	buildingsData[++bCounter],	nameData[bCounter]);
	diamondFactory.Reinitialisate(	buildingsData[++bCounter],	nameData[bCounter]);
}

void Buildings::buildMenu(Resource& res)
{
	std::cout << "Select build:" << std::endl;

	printBuildRequest(forestry, "1", "Log", "Wood", "Stone");
	printBuildRequest(sawmill, "2", "Log", "Wood", "Stone");
	printBuildRequest(quarry,"3", "Log", "Wood", "Stone");
	printBuildRequest(career,"4", "Log", "Wood", "Stone");
	printBuildRequest(copperMine,"5", "Log", "Stone", "Coal");
	printBuildRequest(tinMine,"6", "Coal", "Stone", "Copper");
	printBuildRequest(alloyPlant,"7", "Stone", "Copper", "Tin");
	printBuildRequest(silverCleaner,"8", "Stone", "Copper", "Bronze");
	printBuildRequest(goldMine,"9", "Copper", "Bronze", "Silver");
	printBuildRequest(platinaCleaner,"a", "Bronze", "Silver", "Gold");
	printBuildRequest(diamondFactory,"b", "Silver", "Gold", "Platina");

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

void Buildings::printBuildRequest(BuildTemplate build, std::string buildSymb,
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

void Buildings::printQueueStatus()
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



