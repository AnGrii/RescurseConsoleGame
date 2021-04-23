#pragma once
#include <iostream>
#include <random>

class GameMessages
{
private:
	GameMessages() {}

public:
	static void keywordHelp(bool show);

	static void skipLine();

	static void incorrectInput();

	static void About();
};

