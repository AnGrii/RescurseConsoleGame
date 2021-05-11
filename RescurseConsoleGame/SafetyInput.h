#pragma once
#include <string>
#include <iostream>
#include <vector>

class SafetyInput
{
public:
	static char cinAndGetChar(std::string inputMSG);

	static uint16_t cinAndGetIDfromChar(std::string inputMSG, 
		std::vector<char> nameIdLIst, const size_t MAXIMAL_ID_VALUE);

	static uint64_t cinAndGetUI64FromInput(std::string inputMSG);
private:
	SafetyInput() {}
};

