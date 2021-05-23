#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "GameHelper.h"
#include "Player.h"


class Settings
{
public:
	Settings(std::vector<uint16_t> dataVector);
	std::vector<uint16_t> UploadData();

	static void settingsMenu(Settings& settings, Player& player);

	bool getShowKeywordHelpStatus();

private:
	uint16_t SETTINGS_DATA_COUNT = 1;

	bool showKeywordHelp;
};

