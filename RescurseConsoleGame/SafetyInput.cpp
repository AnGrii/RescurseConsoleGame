#include "SafetyInput.h"

char SafetyInput::cinAndGetChar(std::string inputMSG)
{
	char input = '0';

	std::cout << inputMSG;
	std::cin >> input;
	std::cout << std::endl;
	
	return input;
}

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
			output = uint16_t(i);
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

	number = std::stoull(str_number);

	return number;
}

