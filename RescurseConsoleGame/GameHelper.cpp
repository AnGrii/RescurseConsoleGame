#include "GameHelper.h"

void GameHelper::keywordHelp(bool show)
{
	std::cout << "Key to do:" << std::endl
		<< "e - Extract base resources" << std::endl
		<< "n - Next day :)" << std::endl
		<< "x - Save and Exit" << std::endl
		<< "s - Resources Shop" << std::endl
		<< "b - Build Factories!" << std::endl
		<< "" << std::endl;
}

/// <summary>
/// Initialization srand in header needed!!!
/// </summary>
void GameHelper::skipLine()
{
	
	uint16_t rand = std::rand() % 4;

	switch (rand)
	{
	case 0:
		std::cout << "Skiped (0  )/\\(  0)" << std::endl;
		break;
	case 1:
		std::cout << "Skiped (  0)/\\(0  )" << std::endl;
		break;
	case 2:
		std::cout << "Skiped (0  )/\\(0  )" << std::endl;
		break;
	case 3:
		std::cout << "Skiped (  0)/\\(  0)" << std::endl;
		break;
	default:
		std::cout << "idk it's error. Don't mind!" << std::endl;
		break;
	}
}

void GameHelper::incorrectInputWarning()
{
	std::cout << "Incorrect input!!!" << std::endl;
}
