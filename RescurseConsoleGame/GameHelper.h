#pragma once
#include <iostream>
#include <random>

class GameMessage
{
private:
	GameMessage() {}

public:
	static void keywordHelp(bool show);

	static void skipLine();

	static void incorrectInput();
};

