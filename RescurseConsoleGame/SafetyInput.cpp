#include "SafetyInput.h"

uint16_t SafetyInput::cinAndGetIDfromChar(std::string inputMSG, 
	std::vector<char> nameIdLIst)
{	
	char input = '0';

	std::cout << inputMSG;
	std::cin >> input;
	std::cout << std::endl;

	uint16_t output = 0;
	for (size_t i = 0; i < nameIdLIst.size(); i++)
	{
		if (nameIdLIst[i] == input) {
			output = i;
		}
	}

	return output;
}

uint64_t SafetyInput::cinAndGetNumFromInput(std::string inputMSG)
{
	std::string str_number = "0";
	uint64_t number = 0;

	std::cout << inputMSG;
	std::cin >> str_number;
	std::cout << std::endl;

	// Deleting minus
	if (str_number.size() >= 1) {
		if (str_number[0] == '-') {
			str_number.erase(str_number.begin());
		}
	}

	number = std::stoull(str_number);

	return number;
}

