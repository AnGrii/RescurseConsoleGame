#pragma once
#include <iostream>
#include <vector>

#include "BuildingsManager.h"

class ScienceCentre
{
public:
	static void upgradeBuildings(BuildingsManager& buildings);


private:
	ScienceCentre(){}

	const double increaseValueCoefficient = 1.2;

	static void upgradeBuildingsInfo(const BuildingsManager& buildings);
	static void upgradeBuildingsMenu(BuildingsManager& buildings);
};

