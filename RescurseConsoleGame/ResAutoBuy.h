#pragma once
#pragma once
#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "SafetyInput.h"

class ResAutoBuy
{
public:
	ResAutoBuy();
	
	void countMenu();
	void levelMenu();

	void countBuy(ResourceManager rm);
	void levelBuy(ResourceManager rm);

private:
	std::vector<uint64_t> countDataVc, levelDataVc; // Vc - vector
};


