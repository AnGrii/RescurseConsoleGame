#pragma once
#include <iostream>
#include <random>

class GameHelper
{
private:
	GameHelper() {}

public:
	static void keywordHelp(bool show);

	static void skipLine();

	static void incorrectInputWarning();
};

