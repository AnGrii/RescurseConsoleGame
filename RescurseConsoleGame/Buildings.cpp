#include "Buildings.h"

void Building::Reinitialisate(std::vector<uint64_t> buildingData, std::string name)
{
	uint16_t counter = 0;

	count =				buildingData[counter]; counter++;
	productionOutput =	buildingData[counter]; counter++;
	inQueue =			buildingData[counter]; counter++;
	skipTimeValue =		buildingData[counter]; counter++;
	upgradeValue =		buildingData[counter]; counter++;
	buildTime =			buildingData[counter]; counter++;
	endBuildTime =		buildingData[counter]; counter++;
	resource1 =			buildingData[counter]; counter++;
	resource2 =			buildingData[counter]; counter++;
	resource3 =			buildingData[counter]; counter++;
	powerPercent =		buildingData[counter]; counter++;
	this->name = name;
}
std::vector<uint64_t> Building::UploadData()
{
	std::vector<uint64_t> dataVector;

	dataVector.resize(BUILDING_DATA_COUNT);

	uint16_t counter = 0;
	dataVector[counter] = count;			counter++;
	dataVector[counter] = productionOutput; counter++;
	dataVector[counter] = inQueue;			counter++;
	dataVector[counter] = skipTimeValue;	counter++;
	dataVector[counter] = upgradeValue;		counter++;
	dataVector[counter] = buildTime;		counter++;
	dataVector[counter] = endBuildTime;		counter++;
	dataVector[counter] = resource1;		counter++;
	dataVector[counter] = resource2;		counter++;
	dataVector[counter] = resource3;		counter++;
	dataVector[counter] = powerPercent;		counter++;

	return dataVector;
}

uint64_t Building::getResource1Count()
{
	return resource1;
}

uint64_t Building::getResource2Count()
{
	return resource2;
}

uint64_t Building::getResource3Count()
{
	return resource3;
}

void Building::increaseResRequest1()
{
	resource1 = uint64_t(resource1 * INCREASE_VALUE_COEFFICIENT);
}

void Building::increaseResRequest2()
{
	resource2 = uint64_t(resource2 * INCREASE_VALUE_COEFFICIENT);
}
 
void Building::increaseResRequest3()
{
	resource3 = uint64_t(resource3 * INCREASE_VALUE_COEFFICIENT);
}

void Building::increaseSkipBuildingTimeValue()
{
	skipTimeValue = uint64_t(skipTimeValue * INCREASE_VALUE_COEFFICIENT);
}

void Building::increaseUpgradeValue() {
	upgradeValue = uint64_t(upgradeValue * INCREASE_VALUE_COEFFICIENT);
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

uint64_t Building::getProductionOutput()
{
	return productionOutput;
}

uint64_t Building::calcProductivity()
{
	uint64_t productivity = uint64_t(count * productionOutput * (powerPercent / 100.0));

	if (productivity > 0) {
		return productivity;
	}
	else if(count > 0) { return 1; }
	else { return 0; }
}

uint64_t Building::getBuildTime()
{
	return buildTime;
}

std::string Building::getPowerPercentInfo()
{
	std::string info;

	info = name;
	if (name.length() < 6) {
		info = info + "\t\t\t";
	}
	else if (name.length() < 12) {
		info = info + "\t\t";
	}
	else {
		info = info + "\t";
	}

	info = info + "Power Percent: \t";
	info = info + std::to_string(powerPercent);

	return info;
}

bool Building::getActiveStatus()
{
	return false;
}

void Building::setPowerPercent(uint64_t percent)
{
	if (percent <= 100) {
		this->powerPercent = percent;
	}
	else
	{
		this->powerPercent = 100;
	}
}

uint64_t Building::getSkipValue()
{
	return skipTimeValue;
}

uint64_t Building::getUpgradeValue()
{
	return upgradeValue;
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
			count++;
			std::cout << "Building finished!" << std::endl << std::endl;
		}
	}

	if (endBuildTime == 0) {
			if (inQueue > 0) {
				std::cout << "Building started!" << std::endl << std::endl;
			endBuildTime = buildTime;
			inQueue--;
		}
	}
}

std::string Building::getQueueInfo()
{
	if (this->isInQueue()) {
		std::string info;

		info = info + "Count of " + name + " in queue -\t";
		info = info + std::to_string(inQueue) + '\n';
		info = info + "Days to building left -\t" + std::to_string(endBuildTime);

		return info;
	}
	return "-";
}

std::string Building::getSkipInfo()
{
	if (this->isInQueue()) {
		std::string info;

		info = "- " + name + "\t-\t";
		info = info + std::to_string(skipTimeValue);

		return info;
	}
	return "-";
}

void Building::skipBuildingTime()
{
	endBuildTime = 1;
	//Set 1 for correct work
	//See declaration of bulding skip time
}

void Building::skipBuildingProcess(bool payStatus)
{
	if (this->isInQueue()) {
		if (payStatus) {
			this->skipBuildingTime();
			this->increaseSkipBuildingTimeValue();

			std::cout << name << " building skiped!" << std::endl
				<< std::endl;
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
		std::cout << "Unhappy day (" << std::endl
			<< this->getName() << " was broken!" 
			<< std::endl << std::endl;
	}
}

void Building::buildInfo()
{
	std::cout << "=========   " << name << "   =========" << std::endl
		<< "Count:\t\t\t" << count << std::endl
		<< "Productivity:\t\t" << productionOutput << std::endl
		<< "Skip build time value:\t" << skipTimeValue << std::endl
		<< "Upgrade value:\t\t" << upgradeValue << std::endl
		<< "Build time:\t\t" << buildTime << std::endl
		<< "Resource1 needed:\t" << resource1 << std::endl
		<< "Resource2 needed:\t" << resource2 << std::endl
		<< "Resource3 needed:\t" << resource3 << std::endl
		<< "Power Percent:\t\t" << powerPercent << std::endl << std::endl;
}

std::string Building::getUpgradeBuildInfo()
{
	std::string info;

	info = info + name;
	if(name.size() < 6) {
		info = info + "\t\t\t";
	}
	else if (name.size() <= 11) {
		info = info + "\t\t";
	}
	else {
		info = info + "\t";
	}

	info = info + "Production Output:\t";
	info = info + std::to_string(productionOutput);
	info = info + "\tUpgrade Value:\t";
	info = info + std::to_string(upgradeValue);

	return info;
}

void Building::increaseProductivityOutput(bool payStatus)
{
	if (payStatus) {
		if (productionOutput < UINT64_MAX - 2) {
			productionOutput++;
			this->increaseUpgradeValue();
		}
		else {
			productionOutput = UINT64_MAX - 2;
		}
	}
	else {
		std::cout << "Not enough money for upgrade!" 
			<< std::endl << std::endl;
	}
}

