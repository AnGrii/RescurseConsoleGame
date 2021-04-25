#include "Settings.h"


Settings::Settings(std::vector<uint16_t> dataVector)
{
	uint16_t counter = 0;
	showKeywordHelp = bool(dataVector[counter]); counter++;
}

void Settings::settingsMenu(Settings settings, Player player)
{
	std::cout << "===== Settings =====" << std::endl
		<< "q - To change show keyword help status" << std::endl
		<< "w - To change player name" << std::endl;

	char select = '0';
	std::cin >> select;

	switch (select)
	{
	case 'q':
	{
		if (settings.showKeywordHelp == true) settings.showKeywordHelp = false;
		else settings.showKeywordHelp = true;

		std::cout << "Show keyword help status changed!" << std::endl;
	}
		break;
	case 'w':
	{
		std::string newName;
		std::cin >> newName;

		player.setNewName(newName);
	}
		break;
	default:
		break;
	}
}

bool Settings::getShowKeywordHelpStatus()
{
	return showKeywordHelp;
}







