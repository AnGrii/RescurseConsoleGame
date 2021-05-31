#pragma once
#include <iostream>
#include <vector>

#include "Player.h"
#include "ResourceManager.h"
#include "SafetyInput.h"

class ResAutoSell
{
public:
	ResAutoSell(std::vector<std::vector<uint64_t>> dataVector);
	std::vector<std::vector<uint64_t>> UploadData();
	

	void countMenu(ResourceManager resManager);
	void levelMenu(ResourceManager resManager);

	void countSell(Player& player, ResourceManager& resManager);
	void levelSell(Player& player, ResourceManager& resManager);

private:
	const uint16_t RESOURCES_AUTO_SELL_LIST_COUNT = 3,
		RESOURCES_AUTO_SELL_DATA_COUNT = 11;

	std::vector<uint64_t> percentVc, countVc, ResValueVc; // Vc - vector

	void sellResource(Player& player, uint16_t resID);
};

