#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "GameHelper.h"
#include "Player.h"


class Settings
{
public:
	Settings(std::vector<bool> dataVector);

	static void settingMenu();

private:
	bool showKeywordHelp;
};

