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

	static void settingsMenu();

	bool getShowKeywordHelpStatus();

private:
	bool showKeywordHelp;
};

