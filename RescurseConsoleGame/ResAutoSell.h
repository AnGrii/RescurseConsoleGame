#pragma once
#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "SafetyInput.h"

class ResAutoSell
{
public:
	ResAutoSell(std::vector<uint16_t> dataVector);
	std::vector<uint16_t> UploadData();
	

	void Menu();

	void sell(ResourceManager rm);

private:
	const uint16_t RESOURCES_COUNT = 11;

	std::vector<uint16_t> autoSellPercentVc; // Vc - vector

	void sellResource(Resource resource);
};

