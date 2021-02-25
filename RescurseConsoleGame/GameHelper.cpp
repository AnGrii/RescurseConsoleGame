#include "GameHelper.h"

void GameHelper::KeywordHelp(bool show)
{
	std::cout << "Key to do:" << std::endl
		<< "e - Extract base resources" << std::endl
		<< "n - Next day :)" << std::endl
		<< "x - Save and Exit" << std::endl
		<< "s - Resources Shop" << std::endl
		<< "b - Build Factories!" << std::endl
		<< "" << std::endl;
}

void GameHelper::SkipLine()
{
	srand(static_cast<uint64_t>(NULL));

	uint8_t rand = std::rand() % 4;

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
