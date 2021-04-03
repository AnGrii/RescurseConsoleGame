#pragma once
#include <iostream>
#include <vector>
#include <string>

#include"Resource.h"
#include"ResourceManager.h"

class Market
{
public:
	Market(std::vector<double> dataList);

	void buySellMenu(ResourceManager &rm);

private:
	double sellCOeficient = 1;


	void showBuySellInfo(ResourceManager &rm);

	void sellResource(Resource& res);
	void buyResource(Resource& res);

	void doTranasfer(uint64_t count, uint64_t value);

	void printResourcesBuySellInfo(char nameId, std::string name, Resource res);
};



