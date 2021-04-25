#include "Settings.h"


Settings::Settings(std::vector<uint16_t> dataVector)
{
	uint16_t counter = 0;
	showKeywordHelp = bool(dataVector[counter]); counter++;
}

void Settings::settingsMenu()
{
}

bool Settings::getShowKeywordHelpStatus()
{
	return showKeywordHelp;
}







