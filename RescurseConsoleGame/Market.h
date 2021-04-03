#pragma once
#include <iostream>
#include <vector>
#include <string>

#include"Resource.h"
#include"ResourceManager.h"
#include"Player.h"

class Market
{
public:
	Market(std::vector<double> dataList);

	void buySellMenu(Player& p, ResourceManager &rm);

private:
	double sellCOeficient = 1;


	void showBuySellInfo(ResourceManager &rm);

	void buyResource(Player& p, Resource& res);
	void sellResource(Player& p, Resource& res);

	void printResourcesBuySellInfo(char nameId, std::string name, Resource res);
};



