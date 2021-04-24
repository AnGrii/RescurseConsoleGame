#pragma once
#include <string>
#include <iostream>
#include <vector>

class SafetyInput
{
public:
	static char cinAndGetChar(std::string inputMSG);

	static uint16_t cinAndGetIDfromChar(std::string inputMSG, 
		std::vector<char> nameIdLIst);

	static uint64_t cinAndGetNumFromInput(std::string inputMSG);
private:
	SafetyInput() {}
};

