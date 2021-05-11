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
	
	void Menu(Player& p, ResourceManager &rm);
private:
	const uint16_t BUILDINGS_COUNT = 11;

	double sellCoeficient;
	std::vector<uint64_t> resourcesValueVc, resourcesAutoSellPercentVc; // Vc - vector

	
	void showProductInfo(ResourceManager rm, const std::vector<char> charIDList);

	/*
	void buyResource(Player& p, Resource& res);
	void sellResource(Player& p, Resource& res);

	void printResourcesBuySellInfo(char nameId, std::string name, Resource res);*/
};



