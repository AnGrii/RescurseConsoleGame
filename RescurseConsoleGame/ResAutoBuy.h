#pragma once
#pragma once
#include <iostream>
#include <vector>

#include "Player.h"
#include "ResourceManager.h"
#include "SafetyInput.h"

class ResAutoBuy
{
public:
	ResAutoBuy(std::vector<std::vector<uint64_t>> dataVector);
	std::vector<std::vector<uint64_t>> UploadData();


	void countMenu(ResourceManager resManager);
	void levelMenu(ResourceManager resManager);

	void countBuy(Player& player, ResourceManager& resManager);
	void levelBuy(Player& player, ResourceManager& resManager);

private:
	const uint16_t RESOURCES_AUTO_BUY_LIST_COUNT = 3,
		RESOURCES_AUTO_BUY_DATA_COUNT = 11;

	std::vector<uint64_t> countVc, levelVc, ResValueVc; // Vc - vector

	
};


