#include "GameHelper.h"

void GameMessages::keywordHelp(bool show)
{
	if (show) {
		std::cout << "Key to do:" << std::endl
			<< "e - Extract base resources" << std::endl
			<< "g - Upgrade Resources Extraction" << std::endl
			<< "n - Next day" << std::endl
			<< "b - Build Buildings" << std::endl
			<< "u - Upgrade Buildings" << std::endl
			<< "q - Queue of Buildings" << std::endl
			<< "k - Skip Buildings Menu" << std::endl
			<< "i - Buildings information" << std::endl
			<< "p - Building Prouctivity Settings" << std::endl
			<< "m - Resource Market" << std::endl
			<< "t - Auto Sell Resource" << std::endl
			<< "o - Auto Buy Resource Menu" << std::endl
			<< "r - Restore data" << std::endl
			<< "a - About" << std::endl
			<< "s - Settings" << std::endl
			<< "x - Save and Exit" << std::endl << std::endl;
	}
}

/// <summary>
/// Initialization srand in header needed!!!
/// </summary>
void GameMessages::skipLine()
{
	uint16_t rand = std::rand() % 4;

	switch (rand)
	{
	case 0:
		std::cout << "Skiped (0  )/\\(  0)" << std::endl << std::endl;
		break;
	case 1:
		std::cout << "Skiped (  0)/\\(0  )" << std::endl << std::endl;
		break;
	case 2:
		std::cout << "Skiped (0  )/\\(0  )" << std::endl << std::endl;
		break;
	case 3:
		std::cout << "Skiped (  0)/\\(  0)" << std::endl << std::endl;
		break;
	default:
		std::cout << "idk it's error. Don't mind!" << std::endl << std::endl;
		break;
	}
}

void GameMessages::incorrectInput()
{
	std::cout << "Incorrect input!!!" << std::endl << std::endl;
}

void GameMessages::About()
{
	std::cout << "Hi gamer! Hope u like this game :)" << std::endl
		<< "It's game about resources!" << std::endl
		<< "All you need, extract some resources manually and build first building" << std::endl
		<< "After u will get resources automatically )" << std::endl
		<< "Then u will have many opportunities to do your mining faster" << std::endl
		<< "Upgrades of productivity, increasing of builindg count" << std::endl
		<< "Selling or buying resources to build new buildings" << std::endl
		<< "It's all is your opportunities to have fun in this game" << std::endl
		<< "Good luck!" << std::endl << std::endl;
}
