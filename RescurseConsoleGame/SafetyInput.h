#pragma once
#include <string>
#include <iostream>
#include <vector>

class SafetyInput
{
public:
	static char cinAndReturnChar(std::string inputMSG);

	static uint16_t cinAndReturnCharID(std::string inputMSG, 
		std::vector<char> nameIdLIst, const size_t MAXIMAL_ID_VALUE);

	static uint64_t cinAndReturnUI64T(std::string inputMSG);
private:
	SafetyInput() {}
};

