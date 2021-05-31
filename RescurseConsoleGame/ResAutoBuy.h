#pragma once
#pragma once
#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "SafetyInput.h"

class ResAutoBuy
{
public:
	ResAutoBuy(std::vector<std::vector<uint64_t>> dataVector);
	std::vector<std::vector<uint64_t>> UploadData();

	void countMenu();
	void levelMenu();

	void countBuy(ResourceManager rm);
	void levelBuy(ResourceManager rm);

private:
	std::vector<uint64_t> countDataVc, levelDataVc; // Vc - vector
};


