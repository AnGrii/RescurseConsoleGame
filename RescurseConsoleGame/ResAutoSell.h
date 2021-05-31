#pragma once
#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "SafetyInput.h"

class ResAutoSell
{
public:
	ResAutoSell(std::vector<uint64_t> dataVector);
	std::vector<uint64_t> UploadData();
	

	void Menu();

	void sell(ResourceManager rm);

private:
	const uint16_t RESOURCES_COUNT = 11;

	std::vector<uint64_t> autoSellPercentVc; // Vc - vector

	void sellResource(Resource resource);
};

