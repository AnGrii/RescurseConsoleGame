#include "Buildings.h"

void Building::Reinitialisate(std::vector<uint64_t> buildingData, std::string name)
{
	uint16_t counter = 0;

	count =			buildingData[counter];
	productivity =	buildingData[++counter];
	inQueue =		buildingData[++counter];
	skipTimeValue = buildingData[++counter];
	upgradeValue = buildingData[++counter];
	buildTime =		buildingData[++counter];
	endBuildTime =	buildingData[++counter];
	resource1 =		buildingData[++counter];
	resource2 =		buildingData[++counter];
	resource3 =		buildingData[++counter];
	activated =		buildingData[++counter];
	this->name = name;
}

uint64_t Building::getRes1()
{
	return resource1;
}

uint64_t Building::getRes2()
{
	return resource2;
}

uint64_t Building::getRes3()
{
	return resource3;
}

void Building::increaseResValue1()
{
	resource1 = uint64_t(resource1 * INCREASE_COEFFICIENT_VALUE);
}

void Building::increaseResValue2()
{
	resource2 = uint64_t(resource2 * INCREASE_COEFFICIENT_VALUE);
}
 
void Building::increaseResValue3()
{
	resource3 = uint64_t(resource3 * INCREASE_COEFFICIENT_VALUE);
}

void Building::increaseSkipValue()
{
	skipTimeValue = uint64_t(skipTimeValue * INCREASE_COEFFICIENT_VALUE);
}

void Building::addCount(uint64_t addCount)
{
	uint64_t limit = UINT64_MAX - this->count;

	if (limit > addCount) {
		this->count += addCount;
	}
	else {
		this->count = UINT64_MAX;
	}
}

uint64_t Building::getCount()
{
	return count;
}

uint64_t Building::getProductivity()
{
	return productivity;
}

uint64_t Building::getBuildTime()
{
	return buildTime;
}

bool Building::getActiveStatus()
{
	return activated;
}

uint64_t Building::getSkipValue()
{
	return skipTimeValue;
}

bool Building::isInQueue()
{
	if (endBuildTime == 0){
		if (inQueue == 0) {
			return false;
		}
	}

	return true;
}

bool Building::addInQueue()
{
	if (UINT64_MAX - inQueue > 1) {
		inQueue++;
		return true;
	}
	return false;
}

void Building::updateQueue()
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

void Building::printQueueInfo()
{
	if (this->isInQueue()) {
		std::cout << "Count of " << name << " in queue -\t" << inQueue << std::endl
			<< "Days to building left -\t" << endBuildTime << std::endl << std::endl;
	}
}

void Building::printSkipInfo(char nameId)
{
	if (this->isInQueue()) {
		std::cout << nameId << " - " << name << "\t-\t\t" << skipTimeValue
			<< std::endl << std::endl;
	}
}

void Building::skipBuildingTime()
{
	endBuildTime = 0;
}

void Building::skipBuildingProcess(bool payStatus)
{
	if (this->isInQueue()) {
		if (payStatus) {
			this->skipBuildingTime();
			this->increaseSkipValue();

			std::cout << name << " building skiped!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Not enough money!" << std::endl;
		}
	}
}

void Building::brokeBuild()
{
	if (count > 0) {
		count--;
		std::cout << this->getName() << " was broken!" << std::endl << std::endl;
	}
}

void Building::buildInfo()
{
	std::cout << "=========   " << name << "   =========" << std::endl
		<< "Count:\t\t\t" << count << std::endl
		<< "Productivity:\t\t" << productivity << std::endl
		<< "Skip build time value:\t" << skipTimeValue << std::endl
		<< "Upgrade value:\t" << upgradeValue << std::endl
		<< "Build time:\t\t" << buildTime << std::endl
		<< "Resource1 needed:\t" << resource1 << std::endl
		<< "Resource2 needed:\t" << resource2 << std::endl
		<< "Resource3 needed:\t" << resource3 << std::endl
		<< "Activated:\t\t" << activated << std::endl << std::endl;
}

void Building::upgradeBuildings(BuildingsManager& buildings)
{
}

std::string Building::getUpgradeBuildInfo()
{
	std::string info;

	info += name;
	info += " Productivity: ";
	info += std::to_string(productivity);
	info += " Upgrade Value: ";
	info += std::to_string(upgradeValue);
}

void Building::increaseProductivity()
{
	if (productivity < UINT64_MAX - 2) {
		productivity++;
	}
	else
	{
		productivity = UINT64_MAX - 2;
	}
}





