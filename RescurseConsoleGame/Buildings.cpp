#include "Buildings.h"

void BuildTemplate::Reinitialisate(std::vector<uint64_t> buildingData)
{
	count = buildingData[0];
	productivity = buildingData[1];
	inQueue = buildingData[2];
	moneyNeeded = buildingData[3];
	valueOfSkipTime = buildingData[4];
	endBuildTime = buildingData[5];
	buildTime = buildingData[6];
	resource1 = buildingData[7];
	resource2 = buildingData[8];
	resource3 = buildingData[9];
	activated = buildingData[10];
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

Buildings::Buildings(std::vector<std::vector<uint64_t>> buildingsData)
{
	forestry.Reinitialisate(buildingsData[0]);
	sawmill.Reinitialisate(buildingsData[1]);
	quarry.Reinitialisate(buildingsData[2]);
	career.Reinitialisate(buildingsData[3]);
	copperMine.Reinitialisate(buildingsData[4]);
	tinMine.Reinitialisate(buildingsData[5]);
	alloyPlant.Reinitialisate(buildingsData[6]);
	silverCleaner.Reinitialisate(buildingsData[7]);
	goldMine.Reinitialisate(buildingsData[8]);
	platinaCleaner.Reinitialisate(buildingsData[9]);
	diamondFactory.Reinitialisate(buildingsData[10]);
}

void Buildings::buildMenu()
{
	std::cout << "Select build:" << std::endl;

	printBuildRequest(forestry, "1 -Forestry", "Wood", "Log", "Stone");
	printBuildRequest(sawmill, "2 - Sawmill", "Wood", "Log", "Stone");
	printBuildRequest(quarry,"3 - Quarry", "Wood", "Log", "Stone");
	printBuildRequest(career,"4 - Carrer", "Wood", "Log", "Stone");
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
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		break;
	case 'a':
		break;
	case 'b':
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
		reqRes1.reduce(build.getRes1());
		reqRes2.reduce(build.getRes2());
		reqRes3.reduce(build.getRes3());

		build.addCount(1);
	}
	else
	{
		std::cout << "Not enough cunt of recources!" << std::endl;
	}
}

