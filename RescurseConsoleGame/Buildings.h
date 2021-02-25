#pragma once
#include <iostream>
#include <vector>

#include "Resource.h"

class Buildings
{
public:
	/*Buildings();
	~Buildings();*/

	/*void buildBuilding();
	void doWork();*/

private:
	
};

//Buildings::Buildings()
//{
//}
//
//Buildings::~Buildings()
//{
//} 

class Factory
{
public:
	Factory();
	
private:
	uint64_t productionIN, productionOUT, moneyNeeded, value,/*(resources)*/ valueOfSkipTime, buildTime;
};

Factory::Factory()
{
	productionIN = productionOUT = moneyNeeded = value/*(resources)*/ = valueOfSkipTime = buildTime = 0;
}
