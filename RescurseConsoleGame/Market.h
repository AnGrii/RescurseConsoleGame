#pragma once
#include <iostream>
#include <vector>
#include <string>

#include"Resource.h"
#include"ResourceManager.h"
#include"Player.h"
#include "SafetyInput.h"

class Market
{
public:
	Market(std::vector<uint64_t> dataList);
	std::vector<uint64_t> UploadData();
	
	void buySellMenu(Player& p, ResourceManager &rm);

private:
	/*double sellCOeficient;


	void showBuySellInfo(ResourceManager &rm);

	void buyResource(Player& p, Resource& res);
	void sellResource(Player& p, Resource& res);

	void printResourcesBuySellInfo(char nameId, std::string name, Resource res);*/
};



