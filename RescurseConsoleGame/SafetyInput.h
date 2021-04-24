#pragma once
#include <string>
#include <iostream>
#include <vector>

class SafetyInput
{
public:
	uint16_t cinAndGetIDfromChar(std::string inputMSG, 
		std::vector<char> nameIdLIst);

	uint64_t cinAndGetNumFromInput(std::string inputMSG);
private:
};

